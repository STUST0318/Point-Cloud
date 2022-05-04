#include "QtWidgetsApplication1.h"
#include "View3D.h"
#include "QVTKWidget.h"
#include <QFileDialog>
#include <iostream>

#include <vtkPropPicker.h>
#include <vtkBoxWidget.h>

using namespace std;

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//初始化
	initialvtk();
}
QtWidgetsApplication1::~QtWidgetsApplication1() {
	delete& ui;
}
//初始化vtk
void QtWidgetsApplication1::initialvtk()
{
	pointptr.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(pointptr, "cloud");
	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	//暗灰色背景
	viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
	ui.qvtkWidget->update();

	viewer->registerPointPickingCallback(pp_callback, this);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr clicked_points3d(new pcl::PointCloud<pcl::PointXYZRGB>);
	this->clicked_points_3d = clicked_points3d;
}

int red, green, blue, p;
//Open File
void QtWidgetsApplication1::openFile() {
	QString fileName = QFileDialog::getOpenFileName(this, QString("Open PointCloud File"), ".", tr("*.pcd(*.pcd) ;;" "*.txt(*.txt)"));
	if (!fileName.isEmpty())
	{
		initialvtk();
		//預設白色的點
		red = green = blue = 255;
		string file_name = fileName.toStdString();
		QFileInfo file(QString::fromStdString(file_name));
		//副檔名
		QString ext = file.completeSuffix();
		if (ext == "pcd") {
			pcl::io::loadPCDFile(file_name, *pointptr);
		}
		else if (ext == "txt") {
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
	//pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> white(p->clicked_points_3d, 255, 255, 255);
	//pcl::PointCloud<pcl::PointXYZRGB>::iterator index = p->clicked_points_3d->points.begin();
	pcl::PointXYZRGB searchPoint;

	p->viewer->removePointCloud("clicked_points");
	p->viewer->addPointCloud(p->clicked_points_3d, red, "clicked_points");
	p->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
	//p->dataAxis.arg(current_point.x).arg(current_point.y).arg(current_point.z).arg("   ");
	//QString temStr = QString("%1 %2 %3 %4 %5 %6").arg(QString::number(current_point.x)).arg(" ").arg(QString::number(current_point.y)).arg(" ").arg(QString::number(current_point.z)).arg("\n");
	//p->dataAxis.append(temStr);
	cout << current_point.x << " " << current_point.y << " " << current_point.z << endl;
}
//Red Point
void QtWidgetsApplication1::rSliderChanged() {
	red = ui.rSlider->value();
	ui.rLCD->display(red);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
	viewer->updatePointCloud(pointptr, single_color, "cloud");
	ui.qvtkWidget->update();
}
//Green Point
void QtWidgetsApplication1::gSliderChanged() {
	green = ui.gSlider->value();
	ui.gLCD->display(green);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
	viewer->updatePointCloud(pointptr, single_color, "cloud");
	ui.qvtkWidget->update();
}
//Blue Point
void QtWidgetsApplication1::bSliderChanged() {
	blue = ui.bSlider->value();
	ui.bLCD->display(blue);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(pointptr, red, green, blue);
	viewer->updatePointCloud(pointptr, single_color, "cloud");
	ui.qvtkWidget->update();
}
//Point Size
void QtWidgetsApplication1::pSliderChanged() {
	int p = ui.pSlider->value();
	ui.sizeLCD->display(p);
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, p, "cloud");
	ui.qvtkWidget->update();
}
