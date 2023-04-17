#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <sstream>

class  bitcoinExchange
{
public:
    bitcoinExchange();
    bitcoinExchange(const bitcoinExchange &src);
    bitcoinExchange &operator=(const bitcoinExchange &rhs);
    ~bitcoinExchange ();

    static void readInput(const std::string& fileName, std::map<std::string, double> &mapdData);
    static double findValue(std::map<std::string, double> &mapData, const std::string& date);
    static void readData(const std::string& fileName, std::map<std::string, double> &mapData);
};




