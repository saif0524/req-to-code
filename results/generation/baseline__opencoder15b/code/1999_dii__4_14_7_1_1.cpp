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

ExternalInterface getExternalInterface();
void setExternalInterface(ExternalInterface interface);
DiiData getDiiData();
void setDiiData(DiiData data);
DiiState getDiiState();

ExternalInterface DII::getExternalInterface() {
  return this->externalInterface;
}

void setExternalInterface(ExternalInterface interface) {
   this->externalInterface = interface;
}

DiiData DII::getDiiData() {
   return this->diiData;
}

void setDiiData(DiiData data) {
   this->diiData = data;
}

void setDiiData(DiiData data) {
   this->diiData = data;
}

enum DiiState {
    IDLE,
    RUNNING,
    ERROR
};

DiiState DII::getDiiState() {
    return this->diiState;
}

