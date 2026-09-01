#ifndef DATALOGGER_H
#define DATALOGGER_H 
#include <fstream> 
#include <string>
class DataLogger 
{ 
    public: 
    DataLogger(const std::string& filename);
    void writeRow(double t, double x, double y);
    private: 
    std::ofstream file_;
};
#endif