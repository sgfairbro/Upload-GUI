#include "flightplanningtab.h"
#include "ui_flightplanningtab.h"

FlightPlanningTab::FlightPlanningTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightPlanningTab)
{
    ui->setupUi(this);
}

FlightPlanningTab::~FlightPlanningTab()
{
    delete ui;
}
