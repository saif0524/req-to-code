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

void turnHeatingOn();
void turnHeatingOff();
bool getHeatingStatus() const;
void setHeatingStatus(bool status);
bool getCoolingStatus() const;

void turnHeatingOn() { turnHeatingOn(); }

void turnHeatingOff() { turnHeatingOn(); }

bool getHeatingStatus() { return heatingStatus; }

void setHeatingStatus(bool status) { heatingStatus = status; }

bool getCoolingStatus() { return coolingStatus; }

