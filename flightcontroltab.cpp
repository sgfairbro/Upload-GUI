#include "flightcontroltab.h"
#include "ui_flightcontroltab.h"

FlightControlTab::FlightControlTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightControlTab)
{
    ui->setupUi(this);
    this->connectSignals();
    this->parseBinaryData();
}

FlightControlTab::~FlightControlTab()
{
    delete ui;
}

void FlightControlTab::connectSignals(){

    QSignalMapper* signalMapper = new QSignalMapper (this);

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(sendCommand(int))) ;

    connect(ui->leftButton, SIGNAL( clicked()), signalMapper, SLOT (map()));
    connect(ui->rightButton, SIGNAL( clicked()), signalMapper, SLOT (map()));
    connect(ui->rotateLeftButton, SIGNAL( clicked()), signalMapper, SLOT (map()));
    connect(ui->rotateRightButton, SIGNAL( clicked()), signalMapper, SLOT (map()));
    connect(ui->flyUpButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->flyDownButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->backwardButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->forwardButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->disarmButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->killButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->holdButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->landButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->armButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->manualButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->setAltitudeButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->setGPSButton, SIGNAL (clicked()), signalMapper, SLOT (map()));
    connect(ui->setWaypointButton, SIGNAL (clicked()), signalMapper, SLOT (map()));


    signalMapper->setMapping(ui->leftButton, CMD_LEFT);
    signalMapper->setMapping(ui->rightButton, CMD_RIGHT);
    signalMapper->setMapping(ui->flyUpButton, CMD_UP);
    signalMapper->setMapping(ui->flyDownButton, CMD_DOWN);
    signalMapper->setMapping(ui->rotateLeftButton, CMD_ROTATE_LEFT);
    signalMapper->setMapping(ui->rotateRightButton, CMD_ROTATE_RIGHT);
    signalMapper->setMapping(ui->backwardButton, CMD_BACKWARD);
    signalMapper->setMapping(ui->forwardButton, CMD_FORWARD);
    signalMapper->setMapping(ui->disarmButton, CMD_DISARM);
    signalMapper->setMapping(ui->armButton, CMD_ARM);
    signalMapper->setMapping(ui->manualButton, CMD_MANUAL);
    signalMapper->setMapping(ui->killButton, CMD_KILL);
    signalMapper->setMapping(ui->holdButton, CMD_HOLD);
    signalMapper->setMapping(ui->landButton, CMD_LAND);
    signalMapper->setMapping(ui->setAltitudeButton, CMD_ALTITUDE);
    signalMapper->setMapping(ui->setGPSButton, CMD_GPS);
    signalMapper->setMapping(ui->setWaypointButton, CMD_WAYPOINT);




}

void FlightControlTab::sendCommand(int command)
{

    cout << command << endl;

}

void FlightControlTab::parseBinaryData(){

    Sensor_Data_T sensorData;
    GPS_Data_T gpsData;

    sensorData.WC = 64;
    sensorData.MT = 0x01;
    sensorData.Sequence_num = 3;
    sensorData.Checksum = 0;
    sensorData.Time_hours = 3;
    sensorData.Time_Min = 50;
    sensorData.Time_Sec = 30;
    sensorData.Flight_mode = FM_SAFE;
    sensorData.Rotation_x = 1;
    sensorData.Rotation_y = 2;
    sensorData.Rotation_z = 3;
    sensorData.Accel_x = 4;
    sensorData.Accel_y = 5;
    sensorData.Accel_z = 6;
    sensorData.compass = 10;
    sensorData.Temp = 50;
    sensorData.Altitude = 10;

    for (int i = 0; i < 8; i++){

        sensorData.Servos[i] = i;

    }
    sensorData.Bat22_remaining = 1;
    sensorData.Bat22_current = 2;
    sensorData.Bat22_voltage = 3;

    sensorData.Bat11_current = 4;
    sensorData.Bat11_remaining = 5;
    sensorData.Bat11_voltage = 6;

    sensorData.Air_speed = 1;
    sensorData.Cal_status = 10;



    gpsData.WC = 64;
    gpsData.MT = 0x01;
    gpsData.Sequence_num = 2;

    updateSensorUI(sensorData, gpsData);


}

void FlightControlTab::updateSensorUI(Sensor_Data_T sensorData, GPS_Data_T gpsData){

    //Sensor Data

    ui->current11LCD->display(sensorData.Bat11_current);
    ui->voltage11LCD->display(sensorData.Bat11_voltage);
    ui->remaining11LCD->display(sensorData.Bat11_remaining);

    ui->current22LCD->display(sensorData.Bat22_current);
    ui->voltage22LCD->display(sensorData.Bat22_voltage);
    ui->remaining22LCD->display(sensorData.Bat22_remaining);

    ui->current11LCD->display(sensorData.Bat11_current);
    ui->voltage11LCD->display(sensorData.Bat11_voltage);
    ui->remaining11LCD->display(sensorData.Bat11_remaining);

    ui->xAccLCD->display(sensorData.Accel_x);
    ui->yAccLCD->display(sensorData.Accel_y);
    ui->zAccLCD->display(sensorData.Accel_z);

    ui->xRotLCD->display(sensorData.Rotation_x);
    ui->yRotLCD->display(sensorData.Rotation_y);
    ui->zRotLCD->display(sensorData.Rotation_z);

    ui->servoLCD->display(sensorData.Servos[0]);
    ui->servoLCD_2->display(sensorData.Servos[1]);
    ui->servoLCD_3->display(sensorData.Servos[2]);
    ui->servoLCD_4->display(sensorData.Servos[3]);
    ui->servoLCD_5->display(sensorData.Servos[4]);
    ui->servoLCD_6->display(sensorData.Servos[5]);
    ui->servoLCD_7->display(sensorData.Servos[6]);
    ui->servoLCD_8->display(sensorData.Servos[7]);
    ui->servoLCD_9->display(sensorData.Servos[8]);

    ui->altitudeLCD->display(sensorData.Altitude);
    ui->tempLCD->display(sensorData.Temp);


    //GPS Data
    ui->altitudeLCD->display(gpsData.Altitude);




}

void FlightControlTab::writeDataToTextFile(Sensor_Data_T sensorData, GPS_Data_T gpsData){




}




