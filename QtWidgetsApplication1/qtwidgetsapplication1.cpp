#include "qtwidgetsapplication1.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include "QVTKWidget.h"
using namespace std;
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initialvtk();
    QObject::connect(ui.openAction, &QAction::triggered, this, &QtWidgetsApplication1::OpenFile);
    QObject::connect(ui.openActiontxt, &QAction::triggered, this, &QtWidgetsApplication1::OpenFiletxt);
}

QtWidgetsApplication1::~QtWidgetsApplication1() {
    delete& ui;
}

void QtWidgetsApplication1::initialvtk() {
    pointptr.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    viewer->addPointCloud(pointptr, "cloud");
    ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
    ui.qvtkWidget->update();
}
void QtWidgetsApplication1::OpenFile() {
    QString fileName = QFileDialog::getOpenFileName(
        this, QString("Open PointCloud"), ".",QString("PCD files(*.pcd|*.txt)"));

    if (!fileName.isEmpty()) {
        std::string file_name = fileName.toStdString();
        pcl::io::loadPCDFile(file_name, *pointptr);
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, 255, 255, 255);
        viewer->updatePointCloud(pointptr, single_color, "cloud");
        viewer->resetCamera();
        ui.qvtkWidget->update();
    }
    else {
        QMessageBox::warning(NULL, "°T®§¤è¶ô", "¿ù»~");
    }
}
void QtWidgetsApplication1::OpenFiletxt() {
    string filename = "D:/Chair_TXT_6097039_points.txt";
    ifstream infile;
    infile.open(filename.data());
    string s;
    while (getline(infile,s)) {
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
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>single_color(pointptr, 255, 255, 255);
    viewer->addPointCloud<pcl::PointXYZRGB>(pointptr, single_color, "cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");
    ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
    viewer->resetCamera();
    ui.qvtkWidget->update();
}
void QtWidgetsApplication1::Slider2Spin() {
    ui.ColorspinBoxB->setValue(ui.ColorSliderB->value());
    ui.ColorspinBoxG->setValue(ui.ColorSliderG->value());
    ui.ColorspinBoxR->setValue(ui.ColorSliderR->value());
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> 
        single_color(pointptr, ui.ColorSliderR->value(), ui.ColorSliderG->value(), ui.ColorSliderB->value());
    viewer->updatePointCloud(pointptr, single_color, "cloud");
    ui.qvtkWidget->update();
}
void QtWidgetsApplication1::Spin2Slider() {
    ui.ColorSliderB->setValue(ui.ColorspinBoxB->value());
    ui.ColorSliderG->setValue(ui.ColorspinBoxG->value());
    ui.ColorSliderR->setValue(ui.ColorspinBoxR->value());
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>
        single_color(pointptr, ui.ColorSliderR->value(), ui.ColorSliderG->value(), ui.ColorSliderB->value());
    viewer->updatePointCloud(pointptr, single_color, "cloud");
    ui.qvtkWidget->update();
}
void QtWidgetsApplication1::BackgroundColorChange(int value) {
    switch (value){
        case 0: {
            viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
            break;
        }
        case 2: {
            viewer->setBackgroundColor(240 / 255.0, 240 / 255.0, 240 / 255.0);
            break;
        }
    }
    ui.qvtkWidget->update();
}
void QtWidgetsApplication1::SizeChange() {
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,ui.SizeSlider->value(), "cloud");
    ui.qvtkWidget->update();
}