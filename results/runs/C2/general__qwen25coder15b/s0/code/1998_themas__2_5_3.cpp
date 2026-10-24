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

const bool coolingStatus;

void turnHeatingOn();
void turnHeatingOff();
bool getHeatingStatus() const;
void setHeatingStatus(bool status);
bool getCoolingStatus() const;

void turnHeatingOn() { turnHeatingOn(); }

void turnHeatingOff() { turnHeatingOn(); }

bool getHeatingStatus() const { return heatingStatus; }

void setHeatingStatus(bool status) { using namespace std; cout << "Setting heating status to: " << status << endl; heatingStatus = status; }

bool getCoolingStatus() const { return coolingStatus; }

