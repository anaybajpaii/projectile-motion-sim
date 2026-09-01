#include "DataLogger.h"

DataLogger::DataLogger(const std::string& filename) 
{
    file_.open(filename);
    file_ << "t,x,y\n";
}
void DataLogger::writeRow(double t, double x, double y) 
{
    file_ << t << "," << x << "," << y << "\n";
}