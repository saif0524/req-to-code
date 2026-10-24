#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

double get_temperature();
void set_temperature(double temperature);
std::string get_status();
void set_status(std::string status);
std::string get_mode();

const double THEMAS::get_temperature() const {
   // Return the current temperature.
   return temperature;
}

void THEMAS::set_temperature(double temperature) {
   this->temperature = temperature;
}

std::string THEMAS::get_status() {
    // Return the current status of the heating or cooling unit.
    return status;
}

void THEMAS::set_temperature(double temperature) {
   this->temperature = temperature;
}

std::string THEMAS::get_temperature() {
    // Return the current temperature.
    return temperature;
}

void THEMAS::set_status(std::string status) {
   this->status = status;
}

std::string THEMAS::get_mode() {
    // Return the current mode of operation for the heating or cooling unit.
    return mode;
}

void THEMAS::set_status(std::string status) {
   this->status = status;
}

std::string THEMAS::get_mode() {
    // Return the current mode of operation for the heating or cooling unit.
    return mode;
}

