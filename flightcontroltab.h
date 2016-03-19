#ifndef FLIGHTCONTROLTAB_H
#define FLIGHTCONTROLTAB_H

#include <QWidget>

namespace Ui {
class FlightControlTab;
}

class FlightControlTab : public QWidget
{
    Q_OBJECT

public:
    explicit FlightControlTab(QWidget *parent = 0);
    ~FlightControlTab();

private:
    Ui::FlightControlTab *ui;
};

#endif // FLIGHTCONTROLTAB_H
