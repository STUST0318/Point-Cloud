/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QAction *openAction;
    QAction *saveAction;
    QAction *PointColorAction;
    QAction *BackgroundColorAction;
    QWidget *centralWidget;
    QVTKWidget *qvtkWidget;
    QDockWidget *RGBDock;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLCDNumber *rLCD;
    QSlider *rSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *gLCD;
    QSlider *gSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLCDNumber *bLCD;
    QSlider *bSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLCDNumber *sizeLCD;
    QSlider *pSlider;
    QCheckBox *coordinateChkBox;
    QTableWidget *consoleTable;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(1123, 809);
        openAction = new QAction(QtWidgetsApplication1Class);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        saveAction = new QAction(QtWidgetsApplication1Class);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        PointColorAction = new QAction(QtWidgetsApplication1Class);
        PointColorAction->setObjectName(QString::fromUtf8("PointColorAction"));
        BackgroundColorAction = new QAction(QtWidgetsApplication1Class);
        BackgroundColorAction->setObjectName(QString::fromUtf8("BackgroundColorAction"));
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(260, 10, 851, 561));
        RGBDock = new QDockWidget(centralWidget);
        RGBDock->setObjectName(QString::fromUtf8("RGBDock"));
        RGBDock->setGeometry(QRect(0, 10, 245, 475));
        RGBDock->setMinimumSize(QSize(245, 400));
        RGBDock->setMaximumSize(QSize(300, 524287));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_1 = new QLabel(dockWidgetContents_4);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_1->setFont(font);

        horizontalLayout->addWidget(label_1);

        rLCD = new QLCDNumber(dockWidgetContents_4);
        rLCD->setObjectName(QString::fromUtf8("rLCD"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rLCD->sizePolicy().hasHeightForWidth());
        rLCD->setSizePolicy(sizePolicy1);
        rLCD->setAutoFillBackground(false);
        rLCD->setInputMethodHints(Qt::ImhNone);
        rLCD->setFrameShape(QFrame::Panel);
        rLCD->setFrameShadow(QFrame::Raised);
        rLCD->setLineWidth(1);
        rLCD->setSmallDecimalPoint(false);
        rLCD->setDigitCount(3);
        rLCD->setMode(QLCDNumber::Dec);
        rLCD->setProperty("value", QVariant(255.000000000000000));
        rLCD->setProperty("intValue", QVariant(255));

        horizontalLayout->addWidget(rLCD);


        verticalLayout->addLayout(horizontalLayout);

        rSlider = new QSlider(dockWidgetContents_4);
        rSlider->setObjectName(QString::fromUtf8("rSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rSlider->sizePolicy().hasHeightForWidth());
        rSlider->setSizePolicy(sizePolicy2);
        rSlider->setMinimumSize(QSize(132, 0));
        rSlider->setMaximum(255);
        rSlider->setSliderPosition(255);
        rSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(rSlider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(dockWidgetContents_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        gLCD = new QLCDNumber(dockWidgetContents_4);
        gLCD->setObjectName(QString::fromUtf8("gLCD"));
        sizePolicy1.setHeightForWidth(gLCD->sizePolicy().hasHeightForWidth());
        gLCD->setSizePolicy(sizePolicy1);
        gLCD->setFrameShape(QFrame::Panel);
        gLCD->setDigitCount(3);
        gLCD->setProperty("intValue", QVariant(255));

        horizontalLayout_2->addWidget(gLCD);


        verticalLayout->addLayout(horizontalLayout_2);

        gSlider = new QSlider(dockWidgetContents_4);
        gSlider->setObjectName(QString::fromUtf8("gSlider"));
        sizePolicy2.setHeightForWidth(gSlider->sizePolicy().hasHeightForWidth());
        gSlider->setSizePolicy(sizePolicy2);
        gSlider->setMinimumSize(QSize(132, 0));
        gSlider->setMaximum(255);
        gSlider->setSliderPosition(255);
        gSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(gSlider);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(dockWidgetContents_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        bLCD = new QLCDNumber(dockWidgetContents_4);
        bLCD->setObjectName(QString::fromUtf8("bLCD"));
        sizePolicy1.setHeightForWidth(bLCD->sizePolicy().hasHeightForWidth());
        bLCD->setSizePolicy(sizePolicy1);
        bLCD->setFrameShape(QFrame::Panel);
        bLCD->setDigitCount(3);
        bLCD->setProperty("intValue", QVariant(255));

        horizontalLayout_3->addWidget(bLCD);


        verticalLayout->addLayout(horizontalLayout_3);

        bSlider = new QSlider(dockWidgetContents_4);
        bSlider->setObjectName(QString::fromUtf8("bSlider"));
        sizePolicy2.setHeightForWidth(bSlider->sizePolicy().hasHeightForWidth());
        bSlider->setSizePolicy(sizePolicy2);
        bSlider->setMinimumSize(QSize(132, 0));
        bSlider->setMaximum(255);
        bSlider->setSliderPosition(255);
        bSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(bSlider);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(dockWidgetContents_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        sizeLCD = new QLCDNumber(dockWidgetContents_4);
        sizeLCD->setObjectName(QString::fromUtf8("sizeLCD"));
        sizePolicy1.setHeightForWidth(sizeLCD->sizePolicy().hasHeightForWidth());
        sizeLCD->setSizePolicy(sizePolicy1);
        sizeLCD->setDigitCount(1);
        sizeLCD->setSegmentStyle(QLCDNumber::Filled);
        sizeLCD->setProperty("intValue", QVariant(1));

        horizontalLayout_4->addWidget(sizeLCD);


        verticalLayout->addLayout(horizontalLayout_4);

        pSlider = new QSlider(dockWidgetContents_4);
        pSlider->setObjectName(QString::fromUtf8("pSlider"));
        sizePolicy2.setHeightForWidth(pSlider->sizePolicy().hasHeightForWidth());
        pSlider->setSizePolicy(sizePolicy2);
        pSlider->setMinimumSize(QSize(132, 0));
        pSlider->setMinimum(1);
        pSlider->setMaximum(10);
        pSlider->setSliderPosition(1);
        pSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(pSlider);


        verticalLayout_2->addLayout(verticalLayout);

        RGBDock->setWidget(dockWidgetContents_4);
        coordinateChkBox = new QCheckBox(centralWidget);
        coordinateChkBox->setObjectName(QString::fromUtf8("coordinateChkBox"));
        coordinateChkBox->setGeometry(QRect(20, 490, 121, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        coordinateChkBox->setFont(font1);
        consoleTable = new QTableWidget(centralWidget);
        if (consoleTable->columnCount() < 5)
            consoleTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        consoleTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        consoleTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        consoleTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        consoleTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        consoleTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        consoleTable->setObjectName(QString::fromUtf8("consoleTable"));
        consoleTable->setGeometry(QRect(0, 580, 1121, 171));
        consoleTable->setShowGrid(false);
        consoleTable->horizontalHeader()->setDefaultSectionSize(210);
        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        QtWidgetsApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplication1Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(openAction);
        menu->addSeparator();
        menu->addAction(saveAction);
        menu_2->addAction(PointColorAction);
        menu_2->addSeparator();
        menu_2->addAction(BackgroundColorAction);

        retranslateUi(QtWidgetsApplication1Class);
        QObject::connect(rSlider, SIGNAL(valueChanged(int)), QtWidgetsApplication1Class, SLOT(rSliderChanged()));
        QObject::connect(gSlider, SIGNAL(valueChanged(int)), QtWidgetsApplication1Class, SLOT(gSliderChanged()));
        QObject::connect(bSlider, SIGNAL(valueChanged(int)), QtWidgetsApplication1Class, SLOT(bSliderChanged()));
        QObject::connect(pSlider, SIGNAL(valueChanged(int)), QtWidgetsApplication1Class, SLOT(pSliderChanged()));
        QObject::connect(openAction, SIGNAL(triggered()), QtWidgetsApplication1Class, SLOT(openFile()));
        QObject::connect(coordinateChkBox, SIGNAL(stateChanged(int)), QtWidgetsApplication1Class, SLOT(coordinateChange(int)));

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        openAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\351\226\213\345\225\237\346\252\224\346\241\210", nullptr));
        saveAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\204\262\345\255\230\346\252\224\346\241\210", nullptr));
        PointColorAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\351\273\236\351\233\262", nullptr));
        BackgroundColorAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\350\203\214\346\231\257", nullptr));
        RGBDock->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "RGB", nullptr));
        label_1->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Red", nullptr));
        label_2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Green", nullptr));
        label_3->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Blue", nullptr));
        label_4->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Point Size", nullptr));
        coordinateChkBox->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Coordinate", nullptr));
        QTableWidgetItem *___qtablewidgetitem = consoleTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = consoleTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Operation", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = consoleTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Operation Object", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = consoleTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Details", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = consoleTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Note", nullptr));
        menu->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\346\252\224\346\241\210", nullptr));
        menu_2->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\350\211\262\345\275\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
