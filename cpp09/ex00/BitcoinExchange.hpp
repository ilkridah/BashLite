#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

void readInput(const std::string& fileName, std::map<std::string, double> &mapdData);
double findValue(std::map<std::string, double> &mapData, const std::string& date);
void readData(const std::string& fileName, std::map<std::string, double> &mapData);
