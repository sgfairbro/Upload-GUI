#include "flightcontroltab.h"
#include "ui_flightcontroltab.h"

FlightControlTab::FlightControlTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightControlTab)
{
    ui->setupUi(this);
}

FlightControlTab::~FlightControlTab()
{
    delete ui;
}
