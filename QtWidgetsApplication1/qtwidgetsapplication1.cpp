#include "qtwidgetsapplication1.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include "QVTKWidget.h"
#include <QFileInfo>
#include <QtWidgets\qcolordialog.h>
#include <QTableWidget>
#include <QDateTime>
using namespace std;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr areacloud(new pcl::PointCloud<pcl::PointXYZRGB>); //區域選取的點雲
pcl::PointCloud<pcl::PointXYZRGB>::Ptr addpoints(new pcl::PointCloud<pcl::PointXYZRGB>); //新增檔案的點雲
pcl::PointCloud<pcl::PointXYZRGB>::Ptr Allpoints(new pcl::PointCloud<pcl::PointXYZRGB>); //全部的點雲
string ptrname;//儲存prt的名稱
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initialvtk();
    QObject::connect(ui.openAction, &QAction::triggered, this, &QtWidgetsApplication1::OpenFile);
    QObject::connect(ui.addAction, &QAction::triggered, this, &QtWidgetsApplication1::AddFile);
    QObject::connect(ui.clearAction, &QAction::triggered, this, &QtWidgetsApplication1::ClearFile);
    QObject::connect(ui.saveAction, &QAction::triggered, this, &QtWidgetsApplication1::SaveFile);
    QObject::connect(ui.exitAction, &QAction::triggered, this, &QtWidgetsApplication1::Exit);
    QObject::connect(ui.PointColorAction, &QAction::triggered, this, &QtWidgetsApplication1::PointColorChange);
    QObject::connect(ui.BackgroundColorAction, &QAction::triggered, this, &QtWidgetsApplication1::BackgroundColorchagne);
    QObject::connect(ui.treeWidget, &QTreeView::customContextMenuRequested, this, &QtWidgetsApplication1::onTreeViewMenuRequested);
    QObject::connect(ui.treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemSelected(QTreeWidgetItem*)));
}

QtWidgetsApplication1::~QtWidgetsApplication1() {
    delete& ui;
}

void QtWidgetsApplication1::initialvtk() {
    pointptr.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));

    ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
    //settableWidget(0);
    ui.qvtkWidget->update();
    ui.treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui.tableWidget->setSelectionMode(QAbstractItemView::NoSelection); //禁止點擊屬性管理器的item
    ui.tableWidget->horizontalHeader()->setSectionsClickable(false); //禁止點擊表頭
    ui.treeWidget->clear();//清除treewidget
    //初始化數值
    PointCloudCounter = 0;
    pointsusm.clear();
}

void QtWidgetsApplication1::pp_callback(const pcl::visualization::PointPickingEvent& event, void* args)
{
    QtWidgetsApplication1* p = (QtWidgetsApplication1*)args;
    if (event.getPointIndex() == -1)
        return;
    pcl::PointXYZRGB current_point;
    event.getPoint(current_point.x, current_point.y, current_point.z);
    p->clicked_points_3d->points.push_back(current_point);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> red(p->clicked_points_3d, 255, 0, 0);

    pcl::PointXYZRGB searchPoint;

    p->viewer->removePointCloud("clicked_points");
    p->viewer->addPointCloud(p->clicked_points_3d, red, "clicked_points");
    p->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
    cout << current_point.x << " " << current_point.y << " " << current_point.z << endl;
    
}

void QtWidgetsApplication1::area_callback(const pcl::visualization::AreaPickingEvent& event, void* args)
{
    QtWidgetsApplication1* p = (QtWidgetsApplication1*)args;
    vector <int> indices;
    if (event.getPointsIndices(indices) == -1)
        return;

    for (int i = 0; i < indices.size(); i++) {
        pcl::PointXYZRGB current_point;
        current_point.x = p->pointptr->points[indices[i]].x;
        current_point.y = p->pointptr->points[indices[i]].y;
        current_point.z = p->pointptr->points[indices[i]].z;
        areacloud->points.push_back(current_point);
    }
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> green(areacloud, 0, 255, 0); 
    p->viewer->removePointCloud("clicked_points_area");
    p->viewer->addPointCloud(areacloud, green, "clicked_points_area");
    p->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "clicked_points_area");
    p->ui.qvtkWidget->update();
}

void QtWidgetsApplication1::OpenFile() {
    initialvtk();
    QString filePath = QFileDialog::getOpenFileName(this, QString("Open PointCloud File"), ".", tr("*.pcd(*.pcd) ;;" "*.txt(*.txt)"));
    if (!filePath.isEmpty()) {
        std::string file_path = filePath.toStdString();
        QFileInfo file(QString::fromStdString(file_path));
        QString filename = file.fileName();//取得檔案名稱
        string name = filename.toStdString();
        viewer->addPointCloud(pointptr, name);
        QString ext = file.completeSuffix();
        if (ext == "txt") {
            ifstream infile;
            infile.open(file_path.data());
            string s;
            while (getline(infile, s)) {
                QString ss, s1, s2, s3;
                ss = tr(s.c_str());
                s1 = ss.section(" ", 0, 0);
                s2 = ss.section(" ", 1, 1);
                s3 = ss.section(" ", 2, 2);
                pcl::PointXYZRGB current_point;
                current_point.x = s1.toFloat();
                current_point.y = s2.toFloat();
                current_point.z = s3.toFloat();
                pointptr->points.push_back(current_point);
            }
            infile.close();
        }
        else if (ext == "pcd") {
            pcl::io::loadPCDFile(file_path, *pointptr);
        }
        *Allpoints += *pointptr;
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, 255, 255, 255);
        viewer->updatePointCloud(pointptr, single_color, name);
        viewer->resetCamera();
        ui.qvtkWidget->update();

        pointsusm.push_back(pointptr->size());

        QTreeWidgetItem* cloudName = new QTreeWidgetItem(QStringList() << filename);
        ui.treeWidget->addTopLevelItem(cloudName);

        viewer->registerPointPickingCallback(pp_callback, this);
        viewer->registerAreaPickingCallback(area_callback, this);
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr clicked_points3d(new pcl::PointCloud<pcl::PointXYZRGB>);
        this->clicked_points_3d = clicked_points3d;

        PointCloudCounter++;
        settableWidget(0);
        ptrname = name;

        consoleLog(
            "Open",
            filename,
            filePath,
            "Time cost: "
        );
    }
    else {
        QMessageBox::warning(NULL, "!", "!");
    }
}

void QtWidgetsApplication1::AddFile() {
    QString filePath = QFileDialog::getOpenFileName(this, QString("Open PointCloud File"), ".", tr("*.pcd(*.pcd) ;;" "*.txt(*.txt)"));
    std::string file_path = filePath.toStdString();
    QFileInfo file(QString::fromStdString(file_path));
    QString filename = file.fileName();
    if (!filePath.isEmpty()) {
        string name = filename.toStdString();
        std::string file_path = filePath.toStdString();
        pcl::io::loadPCDFile(file_path, *addpoints);
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(addpoints, r, g, b);
        *Allpoints += *addpoints;
        viewer->addPointCloud(addpoints, single_color, name);
        viewer->resetCamera();
        //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "addcloud");
        ui.qvtkWidget->update();
        cout << name;
        pointsusm.push_back(addpoints->size());

        QTreeWidgetItem* cloudName = new QTreeWidgetItem(QStringList() << filename);
        ui.treeWidget->addTopLevelItem(cloudName);
        PointCloudCounter++;//點雲檔案數量加一
        settableWidget(PointCloudCounter-1);
        viewer->registerPointPickingCallback(pp_callback, this);
        viewer->registerAreaPickingCallback(area_callback, this);
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr clicked_points3d(new pcl::PointCloud<pcl::PointXYZRGB>);
        this->clicked_points_3d = clicked_points3d;
    }
}

void QtWidgetsApplication1::ClearFile() {
    initialvtk();
    ui.tableWidget->clearContents();
}

void QtWidgetsApplication1::SaveFile() {
    QString filePath = QFileDialog::getSaveFileName(this, QString("Open PointCloud File"), ".", tr("*.pcd(*.pcd) ;;" "*.txt(*.txt)"));
    if (!filePath.isEmpty()) {
        std::string file_path = filePath.toStdString();
        pcl::io::savePCDFile(file_path, *Allpoints);
    }
}

void QtWidgetsApplication1::Exit() {
    exit(0);
}

void QtWidgetsApplication1::settableWidget(int index) {
    ui.tableWidget->setItem(0, 0, new QTableWidgetItem("Clouds"));
    ui.tableWidget->setItem(0, 1, new QTableWidgetItem(QVariant(PointCloudCounter).toString()));
    ui.tableWidget->setItem(1, 0, new QTableWidgetItem("Points"));
    if(PointCloudCounter==0)
        ui.tableWidget->setItem(1, 1, new QTableWidgetItem("0"));
    else
        ui.tableWidget->setItem(1, 1, new QTableWidgetItem(QVariant(pointsusm[index]).toString()));
    ui.tableWidget->setItem(2, 0, new QTableWidgetItem("Faces"));
    ui.tableWidget->setItem(2, 1, new QTableWidgetItem("0"));
    ui.tableWidget->setItem(3, 0, new QTableWidgetItem("Total points"));
    ui.tableWidget->setItem(3, 1, new QTableWidgetItem(QVariant(accumulate(pointsusm.begin(), pointsusm.end(), 0)).toString()));
}

void QtWidgetsApplication1::SliderColor() {
    string name = (ui.treeWidget->topLevelItem(itemSelect)->text(0)).toStdString();
    ui.rLCD->display(ui.rSlider->value());
    ui.gLCD->display(ui.gSlider->value());
    ui.bLCD->display(ui.bSlider->value());
    
    if (ptrname == name) {
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>
            single_color(pointptr, ui.rSlider->value(), ui.gSlider->value(), ui.bSlider->value());
        viewer->updatePointCloud(pointptr, single_color, name);
    }
    else {
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>
            single_color2(addpoints, ui.rSlider->value(), ui.gSlider->value(), ui.bSlider->value());
        viewer->updatePointCloud(addpoints, single_color2, name);
    }

    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::PointColorChange() {
    string name = (ui.treeWidget->topLevelItem(itemSelect)->text(0)).toStdString();
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()) {

        ui.rLCD->display(color.red());
        ui.gLCD->display(color.green());
        ui.bLCD->display(color.blue());
        ui.rSlider->setValue(color.red());
        ui.gSlider->setValue(color.green());
        ui.bSlider->setValue(color.blue());

        if (ptrname == name) {
            pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>
                single_color(pointptr, color.red(), color.green(), color.blue());
            viewer->updatePointCloud(pointptr, single_color, name);
        }
        else {
            pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>
                single_color2(addpoints, color.red(), color.green(), color.blue());
            viewer->updatePointCloud(addpoints, single_color2, name);
        }

        ui.qvtkWidget->update();
    }
}

void QtWidgetsApplication1::BackgroundColorChange(int value) {
    switch (value){
        case 0: {
            viewer->setBackgroundColor(0 / 255.0, 0 / 255.0, 0 / 255.0);
            break;
        }
        case 2: {
            viewer->setBackgroundColor(255 / 255.0, 255 / 255.0, 255 / 255.0);
            break;
        }
    }
    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::BackgroundColorchagne() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()) {
        viewer->setBackgroundColor(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0);
        ui.qvtkWidget->update();
    }
}

void QtWidgetsApplication1::SizeChange() {
    string name = (ui.treeWidget->topLevelItem(itemSelect)->text(0)).toStdString();
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,ui.SizeSlider->value(), name);
    ui.sizeLCD->display(ui.SizeSlider->value());
    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::CoordinateChange(int value)
{
    switch (value) {
        case 0: {
            viewer->removeCoordinateSystem();
            break;
        }
        case 2: {
            viewer->addCoordinateSystem();
            break;
        }
    }
    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::onTreeViewMenuRequested(const QPoint& pos)
{
    QModelIndex curIndex = ui.treeWidget->indexAt(pos);
    if (curIndex.isValid()) {
        /*QIcon Hide = QApplication::style()->standardIcon(QStyle::SP_MessageBoxInformation);
        QIcon test = QApplication::style()->standardIcon(QStyle::SP_DesktopIcon);*/
        QMenu menu;
        menu.addAction(tr("Hide"), this, &QtWidgetsApplication1::hideItem);
        menu.addAction(tr("Show"), this, &QtWidgetsApplication1::showItem);
        menu.addAction(tr("Delete"), this, &QtWidgetsApplication1::deleteItem);
        menu.addAction(tr("Change color"), this, &QtWidgetsApplication1::PointColorChange);
        //menu.addSeparator();
        menu.exec(QCursor::pos());
    }
}

void QtWidgetsApplication1::itemSelected(QTreeWidgetItem* item) {
    itemSelect = ui.treeWidget->indexOfTopLevelItem(item);//選擇點雲檔案的編碼
    settableWidget(itemSelect);
    //QMessageBox::warning(NULL, "!", QVariant(itemSelect).toString());
}

void QtWidgetsApplication1::hideItem()
{
    string name = (ui.treeWidget->topLevelItem(itemSelect)->text(0)).toStdString();
    cout << name;
    //name = 我按的那個的明智
    viewer->setPointCloudRenderingProperties(
        pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 0.0, name, 0);
    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::showItem()
{
    string name = (ui.treeWidget->topLevelItem(itemSelect)->text(0)).toStdString();
    viewer->setPointCloudRenderingProperties(
        pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 1.0, name, 0);
    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::deleteItem()
{
    string name = (ui.treeWidget->topLevelItem(itemSelect)->text(0)).toStdString();

    PointCloudCounter--;
    pointsusm.erase(pointsusm.begin() + itemSelect);
    settableWidget(0);
    ui.treeWidget->takeTopLevelItem(itemSelect);
    viewer->removePointCloud(name);
    ui.qvtkWidget->update();
}

void QtWidgetsApplication1::setConsoleTable() {
    // 設置輸出窗口
    QStringList header2;
    header2 << "Time" << "Operation" << "Operation object" << "Details" << "Note";
    ui.consoleTable->setHorizontalHeaderLabels(header2);
    ui.consoleTable->setColumnWidth(0, 150);
    ui.consoleTable->setColumnWidth(1, 200);
    ui.consoleTable->setColumnWidth(2, 200);
    ui.consoleTable->setColumnWidth(3, 300);

    //ui.consoleTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //設置不可編輯
    ui.consoleTable->verticalHeader()->setDefaultSectionSize(22); //設置行距

    ui.consoleTable->setContextMenuPolicy(Qt::CustomContextMenu);

}

void QtWidgetsApplication1::consoleLog(QString operation, QString subname, QString filename, QString note) {
    int rows = ui.consoleTable->rowCount();
    ui.consoleTable->setRowCount(++rows);
    QDateTime time = QDateTime::currentDateTime(); //獲取目前系統時間
    QString time_str = time.toString("MM-dd hh:mm:ss");  //顯示格式
    ui.consoleTable->setItem(rows - 1, 0, new QTableWidgetItem(time_str));
    ui.consoleTable->setItem(rows - 1, 1, new QTableWidgetItem(operation));
    ui.consoleTable->setItem(rows - 1, 2, new QTableWidgetItem(subname));
    ui.consoleTable->setItem(rows - 1, 3, new QTableWidgetItem(filename));
    ui.consoleTable->setItem(rows - 1, 4, new QTableWidgetItem(note));

    ui.consoleTable->scrollToBottom(); //自動滾到最底部
}

void QtWidgetsApplication1::pointsReserve() {

}

void QtWidgetsApplication1::pointsDelete() {

}

