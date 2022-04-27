#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <vtkRenderWindow.h>
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include "QVTKWidget.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);
    ~QtWidgetsApplication1();

private:
    Ui::QtWidgetsApplication1Class ui;
    //定義點雲指標
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointptr;
    //定義顯示器
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;;
    //初始化vtk
    void initialvtk();
    int r;
    int g;
    int b;
private slots:
    void OpenFile();
    void OpenFiletxt();
    void Slider2Spin();
    void Spin2Slider();
    void BackgroundColorChange(int value);
    void SizeChange();
};

