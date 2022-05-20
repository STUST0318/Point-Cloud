#pragma execution_character_set("utf-8")

#include "QtWidgetsApplication1.h"
#include "View3D.h"
#include "QVTKWidget.h"
#include <QFileDialog>
#include <iostream>
#include <QtWidgets\qcolordialog.h>
#include <QTime>
#include <vtkPropPicker.h>
#include <vtkBoxWidget.h>

using namespace std;

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ªì©l¤Æ
	initialvtk();
	QObject::connect(ui.PointColorAction, &QAction::triggered, this, &QtWidgetsApplication1::PointColorChange);
	QObject::connect(ui.BackgroundColorAction, &QAction::triggered, this, &QtWidgetsApplication1::BackgroundColorchagne);
}
QtWidgetsApplication1::~QtWidgetsApplication1() {
	delete& ui;
}
//ªì©l¤Ævtk
void QtWidgetsApplication1::initialvtk()
{
	pointptr.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(pointptr, "cloud");
	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	//·t¦Ç¦â­I´º
	viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
	ui.qvtkWidget->update();

	viewer->registerPointPickingCallback(pp_callback, this);
	viewer->registerAreaPickingCallback(pp_callback, this);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr clicked_points3d(new pcl::PointCloud<pcl::PointXYZRGB>);
	this->clicked_points_3d = clicked_points3d;	
}

int red, green, blue, p;
//Open File
void QtWidgetsApplication1::openFile() {
	ui.statusBar->showMessage("¶}±ÒÀÉ®×");
	QString fileName = QFileDialog::getOpenFileName(this,
		QString("Open PointCloud File"),
		".", tr("*.pcd(*.pcd) ;;" "*.txt(*.txt) ;;" "*.ply(*.ply)"));
	if (!fileName.isEmpty())
	{
		initialvtk();
		//¹w³]¥Õ¦âªºÂI
		red = green = blue = 255;
		string file_name = fileName.toStdString();
		QFileInfo file(QString::fromStdString(file_name));
		//°ÆÀÉ¦W
		QString ext = file.completeSuffix();
		if (ext == "pcd") pcl::io::loadPCDFile(file_name, *pointptr);
		if (ext == "ply") pcl::io::loadPLYFile(file_name, *pointptr);
		if (ext == "txt") {
			ifstream infile;
			infile.open(file_name.data());
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
			viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");
		}
		consoleLog("File open", "", fileName, "");
		pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
		viewer->updatePointCloud(pointptr, single_color, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
	}
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
	p->viewer->removePointCloud("clicked_points");
	p->viewer->addPointCloud(p->clicked_points_3d, red, "clicked_points");
	p->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
	cout << "·í«e®y¼Ð" << current_point.x << " " << current_point.y << " " << current_point.z << endl;
	cout << endl;
}

void QtWidgetsApplication1::pp_callback(const pcl::visualization::AreaPickingEvent& event, void* args) 
{
	QtWidgetsApplication1* p = (QtWidgetsApplication1*)args;
	vector<int> indices;
	p->clicked_points_3d->points.clear();
	p->viewer->removePointCloud("clicked_points");
	if (event.getPointsIndices(indices) == -1) return;
	for (int i = 0; i < indices.size(); i++) {
		p->clicked_points_3d->points.push_back(p->pointptr->points.at(indices[i]));
	}
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> red(p->clicked_points_3d, 255, 0, 0);
	p->viewer->addPointCloud(p->clicked_points_3d, red, "clicked_points");
	p->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
	p->ui.qvtkWidget->update();
}

//Red Point
void QtWidgetsApplication1::rSliderChanged() {
	red = ui.rSlider->value();
	ui.rLCD->display(red);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
	QString rvalue = QString("(%1)").arg(red);
	consoleLog("Color red change", "", "R:" + rvalue, "");
	viewer->updatePointCloud(pointptr, single_color, "cloud");
	ui.qvtkWidget->update();
}
//Green Point
void QtWidgetsApplication1::gSliderChanged() {
	green = ui.gSlider->value();
	ui.gLCD->display(green);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
	QString gvalue = QString("(%1)").arg(green);
	consoleLog("Color green change", "", "G:" + gvalue, "");
	viewer->updatePointCloud(pointptr, single_color, "cloud");
	ui.qvtkWidget->update();
}
//Blue Point
void QtWidgetsApplication1::bSliderChanged() {
	blue = ui.bSlider->value();
	ui.bLCD->display(blue);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
	QString bvalue = QString("(%1)").arg(blue);
	consoleLog("Color blue change", "", "B:" + bvalue, "");
	viewer->updatePointCloud(pointptr, single_color, "cloud");
	ui.qvtkWidget->update();
}
//Point Size
void QtWidgetsApplication1::pSliderChanged() {
	int p = ui.pSlider->value();
	ui.sizeLCD->display(p);
	QString pvalue = QString("(%1)").arg(p);
	consoleLog("Point Size change", "", "point size:" + pvalue, "");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, p, "cloud");
	ui.qvtkWidget->update();
}

void QtWidgetsApplication1::PointColorChange() {
	QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
	if (color.isValid()) {

		ui.rLCD->display(color.red());
		ui.gLCD->display(color.green());
		ui.bLCD->display(color.blue());
		ui.rSlider->setValue(color.red());
		ui.gSlider->setValue(color.green());
		ui.bSlider->setValue(color.blue());

		pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB>
			single_color(pointptr, color.red(), color.green(), color.blue());
		QString rvalue = QString("(%1)").arg(color.red());
		QString gvalue = QString("(%1)").arg(color.green());
		QString bvalue = QString("(%1)").arg(color.blue());
		consoleLog("Point color change", "", "R:" + rvalue + " G:" + gvalue + " B:" + bvalue, "");
		viewer->updatePointCloud(pointptr, single_color, "cloud");
		ui.qvtkWidget->update();
	}
}

void QtWidgetsApplication1::BackgroundColorchagne() {
	QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
	if (color.isValid()) {
		viewer->setBackgroundColor(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0);
		QString rvalue = QString("(%1)").arg(color.red());
		QString gvalue = QString("(%1)").arg(color.green());
		QString bvalue = QString("(%1)").arg(color.blue());
		consoleLog("Background color change", "", "R:"+rvalue+" G:"+gvalue+" B:"+bvalue, "");
		ui.qvtkWidget->update();
	}
}

void QtWidgetsApplication1::coordinateChange(int value)
{
	switch (value) {
	case 0: {
		viewer->removeCoordinateSystem();
		consoleLog("coordinateChange", "", "remove", "");
		break;
	}
	case 2: {
		viewer->addCoordinateSystem();
		consoleLog("coordinateChange", "", "add", "");
		break;
	}
	}
	ui.qvtkWidget->update();
}

void QtWidgetsApplication1::consoleLog(QString operation, QString subname, QString filename, QString note) {
	int rows = ui.consoleTable->rowCount();
	ui.consoleTable->setRowCount(++rows);
	QDateTime time = QDateTime::currentDateTime();//獲取系統時間
	QString time_str = time.toString("MM-dd hh:mm:ss"); //時間顯示格式
	ui.consoleTable->setItem(rows - 1, 0, new QTableWidgetItem(time_str));
	ui.consoleTable->setItem(rows - 1, 1, new QTableWidgetItem(operation));
	ui.consoleTable->setItem(rows - 1, 2, new QTableWidgetItem(subname));
	ui.consoleTable->setItem(rows - 1, 3, new QTableWidgetItem(filename));
	ui.consoleTable->setItem(rows - 1, 4, new QTableWidgetItem(note));

	ui.consoleTable->scrollToBottom(); //滾動至底部
}