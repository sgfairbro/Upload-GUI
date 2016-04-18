#ifndef FLIGHTCONTROLTAB_H
#define FLIGHTCONTROLTAB_H

/* -- Command Definitions -- */
#define CMD_KILL         0xA5    // Shut down NOW
#define CMD_ARM          0x01    // Arm all functions. make ready for commands
#define CMD_DISARM       0x02    // Set all motors to 0 throttle
#define CMD_START        0x03    // Initiate flight plan
#define CMD_MANUAL       0x04    // Change to manual override state
#define CMD_LEFT         0x05    // Move left during override mode
#define CMD_RIGHT        0x06    // Move Right during override mode
#define CMD_UP           0x07    // Move up during override mode
#define CMD_DOWN         0x08    // Move down during override mode
#define CMD_ROTATE_LEFT  0x09    // Move rotate left during override mode
#define CMD_ROTATE_RIGHT 0x10    // Move rotate right during override mode
#define CMD_FORWARD      0x11    // Move forward during override mode
#define CMD_BACKWARD     0x12    // Move backward during override mode
#define CMD_HOLD         0x13    // Hold current position
#define CMD_LAND         0x14    // Land at the current GPS coordinate
#define CMD_ALTITUDE     0x15    // Set altitude to go to
#define CMD_GPS          0x16    // Go to a specific GPS coordinate
#define CMD_WAYPOINT     0x17    // Go to a specific GPS coordinate

/* -- Flight Mode Definitions -- */
#define FM_SAFE			        0
#define FM_TAKEOFF		        1
#define FM_VERTICAL		        2
#define FM_VERT_TO_HORIZ	    3
#define	FM_HORIZONTAL		    4
#define FM_HORIZ_TO_VERT	    5
#define FM_LANDING		        6

#include <QWidget>
#include <QSignalMapper>
#include <iostream>
#include <SerialPort.h>

using namespace std;

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

    struct Sensor_Data_T {
        unsigned char WC;		// Word Count (number of bytes) = 64
        unsigned char MT;		// Message Type  == 0x01;
        unsigned short Sequence_num;	// Messasge Sequence Number
        short Checksum;	// Twos complement of addition of all
                        //  bytes in message exlcuding checksum

        unsigned char Time_hours;	// Time of day hours
        unsigned char Time_Min;	// Time of day Minutes
        unsigned char Time_Sec;	// Time of day Seconds
        unsigned char Flight_mode;	// Current Flight Mode
        short Rotation_x;	// X rotation Value (x 100)
        short Rotation_y;	// Y rotation Value (x 100)
        short Rotation_z;	// Z rotation Value (x 100)
        short Accel_x;	// Acceleration in X Direction (x 100)
        short Accel_y;	// Acceleration in Y Direction (x 100)
        short Accel_z;	// Acceleration in Z Direction (x 100)
        short compass;	// Commpass Value ? (x 100)
        short Temp;		// Temperature (x 100)
        short Altitude;	// Altitude (x 100);
        short Servos[9];	// Servo data for all 9 Servos
        short Bat22_remaining;// Remaining 22.2 V battery capacity in mAh
        short Bat11_remaining;// Remaining 11.1 V battery capacity in mAh
        short Bat22_current;  // Real Time current Draw on 22.2 V battery (x 10)
        short Bat11_current;  // Real Time current Draw on 11.1 V battery (x 10)
        short Bat22_voltage;  // Real Time voltage of 22.2 V battery (x 100)
        short Bat11_voltage;  // Real Time voltage of 11.1 V battery (x 100)
        short Air_speed; 	// Air Speed in m/s (x 100);
        short Cal_status;	// Bit wise calibration indicator
    };

    struct GPS_Data_T {
        unsigned char WC;		// Word Count (number of bytes) = 64
        unsigned char MT;		// Message Type  == 0x01;
        unsigned short Sequence_num;	// Messasge Sequence Number
        short Checksum;	// Twos complement of addition of all
                        // bytes in message exlcuding checksum

        float LAT;		// Lattitude value (North Positive, South Negative)
        float LON;		// Longitude value (East  Positive, West  Negative)
        short Speed_kts;	// Speed over ground in KTS (x 100)
        short Angle;		// Angle from North (x 100 )
        short Altitude;	// GPS Altitude in centimeters
        unsigned char GPS_fix;	// TRUE (1) if GPS has a fix
        unsigned char Num_sats;	// Number of sattelites
        unsigned char Time_hours;	// Time of day hours
        unsigned char Time_Min;	// Time of day Minutes
        unsigned char Time_Sec;	// Time of day Seconds


    };

    void connectSignals(void);
    void parseBinaryData(void);
    void updateSensorUI(Sensor_Data_T, GPS_Data_T);
    void writeDataToTextFile(Sensor_Data_T, GPS_Data_T);

private slots:
    void sendCommand(int);

};


#endif // FLIGHTCONTROLTAB_H
