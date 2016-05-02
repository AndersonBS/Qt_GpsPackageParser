#include "gps.h"
#include <QApplication>
#include <QLoggingCategory>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);

    GPS gps;
    gps.parseGPS("$GPGGA,232803.000,2709.5426,S,05131.4711,W,1,8,0.96,697.8,M,3.1,M,,*62\r\n"
                 "$GPGSA,A,3,03,23,09,22,07,16,01,26,,,,,1.32,0.96,0.90*0A\r\n"
                 "$GPGSV,3,1,12,03,69,085,26,23,55,181,32,09,42,233,21,22,35,057,43*78\r\n"
                 "$GPGSV,3,2,12,07,35,319,19,16,29,090,24,06,24,235,17,01,23,357,33*79\r\n"
                 "$GPGSV,3,3,12,49,21,073,39,26,19,120,24,11,07,001,,30,07,321,29*7A\r\n"
                 "$GPRMC,232803.000,A,2709.5426,S,05131.4711,W,0.14,6.67,110416,,,A*64\r\n");
    qDebug() << gps._gpgga->_latitude << gps._gpgga->_longitude;

    return a.exec();
}
