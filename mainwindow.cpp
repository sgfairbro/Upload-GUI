#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtQuick/QQuickView>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout *flightPlanningGrid = new QGridLayout();
    FlightPlanningTab *flightPlan = new FlightPlanningTab();
    flightPlanningGrid->addWidget(flightPlan);

    QGridLayout *flightControlGrid = new QGridLayout();
    FlightControlTab *flightControl = new FlightControlTab();
    flightControlGrid->addWidget(flightControl);

    QGridLayout *flightPlanningBackupGrid = new QGridLayout();
    FlightPlanningBackup *flightPlanBackup = new FlightPlanningBackup();
    flightPlanningBackupGrid->addWidget(flightPlanBackup);

    //This could be used for that map thing if time permits
    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, ui->tab_1);
    view->setSource(QUrl("qrc:/navigation.qml"));
    view->show();
    flightPlanningGrid->addWidget(container);

    ui->tab_1->setLayout(flightPlanningGrid);
    ui->tab_2->setLayout(flightPlanningBackupGrid);
    ui->tab_3->setLayout(flightControlGrid);

}

/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(200, 200);
    container->setMaximumSize(200, 200);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("navigation.qmll"));
    ui->tab
    ui->verticalLayout->addWidget(container);
}
*/
MainWindow::~MainWindow()
{
    delete ui;
}
