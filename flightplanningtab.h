#ifndef FLIGHTPLANNINGTAB_H
#define FLIGHTPLANNINGTAB_H

#include <QWidget>

namespace Ui {
class FlightPlanningTab;
}

class FlightPlanningTab : public QWidget
{
    Q_OBJECT

public:
    explicit FlightPlanningTab(QWidget *parent = 0);
    ~FlightPlanningTab();

private:
    Ui::FlightPlanningTab *ui;
};

#endif // FLIGHTPLANNINGTAB_H
