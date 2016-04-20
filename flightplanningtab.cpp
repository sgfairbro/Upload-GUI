#include "flightplanningtab.h"
#include "ui_flightplanningtab.h"

FlightPlanningTab::FlightPlanningTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightPlanningTab)
{
    ui->setupUi(this);
    this->setupUI();

}

FlightPlanningTab::~FlightPlanningTab()
{
    delete ui;
}

void FlightPlanningTab::setupMap(){




}

void FlightPlanningTab::setupUI(){

    QGridLayout *layout = new QGridLayout( this );

    //
    // Buttons
    //

    /*
    QPushButton *btnLeft = new QPushButton( "Left", this );
    QPushButton *btnRight = new QPushButton( "Right", this );
    QPushButton *btnUp = new QPushButton( "Up", this );
    QPushButton *btnDown = new QPushButton( "Down", this );
    QPushButton *btnHome = new QPushButton( "Home", this );

    connect( btnLeft, SIGNAL(clicked()), this, SLOT(goLeft()) );
    connect( btnRight, SIGNAL(clicked()), this, SLOT(goRight()) );
    connect( btnUp, SIGNAL(clicked()), this, SLOT(goUp()) );
    connect( btnDown, SIGNAL(clicked()), this, SLOT(goDown()) );
    connect( btnHome, SIGNAL(clicked()), this, SLOT(goHome()) );

    layout->addWidget( btnLeft, 3, 1 );
    layout->addWidget( btnRight, 3, 3 );
    layout->addWidget( btnUp, 2, 2 );
    layout->addWidget( btnDown, 4, 2 );
    layout->addWidget( btnHome, 3, 2 );
    */

    QPushButton *addWayPointButton = new QPushButton("Add Waypoint", this);
    connect(addWayPointButton, SIGNAL(clicked()), this, SLOT(addWaypoint()));
    layout->addWidget(addWayPointButton, 1, 1, 1, 1);

    waypointTable = new QTableWidget(this);
    layout->addWidget(waypointTable, 2, 1, 1, 1 );

    QStringList labels;
    labels << "Waypoint" << "Latitude" << "Longitude";
    waypointTable->setHorizontalHeaderLabels(labels);


    for (int i = 0; i < 10; i++){

        waypointTable->insertRow(i);

    }

    //
    // Embedded webpage
    //
    mView = new QWebEngineView( this );
    mView->settings()->setAttribute( QWebEngineSettings::JavascriptEnabled, true );
    QString fileName = qApp->applicationDirPath() + "/map.html";
    if( !QFile(fileName).exists() ) {
        qDebug() << "File not found:" << fileName;
    }

    QUrl url = QUrl::fromLocalFile( fileName );
    mView->load( url );

    layout->addWidget( mView, 1, 2, 4, 4 );

}


void FlightPlanningTab::addWaypoint(){

    //QVariant lat = ui->webView->page()->mainFrame()->evaluateJavaScript("map.map.center.d");
    //QVariant lon = ui->webView->page()->mainFrame()->evaluateJavaScript("map.map.center.e");

}
