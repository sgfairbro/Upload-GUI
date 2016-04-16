#ifndef FLIGHTPLANNINGBACKUP_H
#define FLIGHTPLANNINGBACKUP_H

#include <QWidget>

namespace Ui {
class FlightPlanningBackup;
}

class FlightPlanningBackup : public QWidget
{
    Q_OBJECT

public:
    explicit FlightPlanningBackup(QWidget *parent = 0);
    ~FlightPlanningBackup();

private:
    Ui::FlightPlanningBackup *ui;
};

#endif // FLIGHTPLANNINGBACKUP_H
