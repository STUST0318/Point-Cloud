#pragma once

#include <QtWidgets/QMainWindow>
// for solving error: no override found for 'vtkRenderWindow'
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include "ui_QtWidgetsApplication1.h"
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/PolygonMesh.h>
#include <QMouseEvent>
#include "QVTKWidget.h"
#include <vtkRenderWindow.h>
#include <QtCore/qglobal.h>

class QtWidgetsApplication1 : public QMainWindow
{
	Q_OBJECT
public:
	QtWidgetsApplication1(QWidget* parent = Q_NULLPTR);
	~QtWidgetsApplication1();

private:	
	Ui::QtWidgetsApplication1Class ui;
	//定義點雲指標
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointptr;
	//定義顯示器
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	//初始化vtk
	void initialvtk();

	static void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args);
	static void pp_callback(const pcl::visualization::AreaPickingEvent& event, void* args);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr clicked_points_3d;

private slots:
	void openFile();
	void rSliderChanged();
	void gSliderChanged();
	void bSliderChanged();
	void pSliderChanged();
	void PointColorChange();
	void BackgroundColorchagne();
	void coordinateChange(int value);
	void consoleLog(QString operation, QString subname, QString filename, QString note);
};
