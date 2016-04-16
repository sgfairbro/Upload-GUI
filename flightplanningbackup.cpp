#include "flightplanningbackup.h"
#include "ui_flightplanningbackup.h"

FlightPlanningBackup::FlightPlanningBackup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightPlanningBackup)
{
    ui->setupUi(this);
}

FlightPlanningBackup::~FlightPlanningBackup()
{
    delete ui;
}
