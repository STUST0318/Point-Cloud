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
    //設定treeWidget2
    void settableWidget(int index);
    //紀錄點雲數量
    std::vector<int> pointsusm;

    int r=255,g=255,b=255,PointCloudCounter = 0;
    int itemSelect=0;
    static void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args);
    static void area_callback(const pcl::visualization::AreaPickingEvent& event, void* args);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr clicked_points_3d;
    void setConsoleTable();
    void consoleLog(QString operation, QString subname, QString filename, QString note);

    
private slots:
    void OpenFile();
    void AddFile();
    void ClearFile();
    void SaveFile();
    void Exit();
    void SliderColor();
    void BackgroundColorChange(int value);
    void SizeChange();
    void CoordinateChange(int value);
    void PointColorChange();
    void BackgroundColorchagne();
    //treeview
    void onTreeViewMenuRequested(const QPoint& pos);
    void itemSelected(QTreeWidgetItem*);
    
    void hideItem();
    void showItem();
    void deleteItem();

    void pointsReserve();
    void pointsDelete();
};

