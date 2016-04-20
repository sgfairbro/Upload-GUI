#ifndef FLIGHTPLANNINGTAB_H
#define FLIGHTPLANNINGTAB_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QTableWidget>


namespace Ui {
class FlightPlanningTab;
}

class FlightPlanningTab : public QWidget
{
    Q_OBJECT

public:
    explicit FlightPlanningTab(QWidget *parent = 0);
    ~FlightPlanningTab();
    QTableWidget *waypointTable;

public slots:

    void addWaypoint(void);


private:
    Ui::FlightPlanningTab *ui;

    /* -- General purpose command message -- */
    struct Command_T {
        unsigned char WC;		// Word Count (number of bytes) = 7
        unsigned char MT;		// Message Type  == 0x80;
        unsigned short Sequence_num;	// Messasge Sequence Number
        short Checksum;	// Twos complement of addition of all
                        // bytes in message exlcuding checksum

        unsigned char Command;	// Command Number -> see defines
    };

    /* -- Waypoints command -- */
    struct Command_Waypoint_T {
        unsigned char WC;		// Word Count (number of bytes) = 7
        unsigned char MT;		// Message Type  == 0x80;
        unsigned short Sequence_num;	// Messasge Sequence Number
        short Checksum;	// Twos complement of addition of all
                        // bytes in message exlcuding checksum

        char Waypoint_num;	// Waypoint Number ( - negative number = end of list )
        unsigned char Flight_mode;	// Flight mode at waypoint
        float LAT;		// Lattitude value (North Positive, South Negative)
        float LON;		// Longitude value (East  Positive, West  Negative)
        short Altitude;	// GPS Altitude in centimeters
    };

    void setupMap(void);
    void setupUI();

    QWebEngineView *mView;
};

#endif // FLIGHTPLANNINGTAB_H
