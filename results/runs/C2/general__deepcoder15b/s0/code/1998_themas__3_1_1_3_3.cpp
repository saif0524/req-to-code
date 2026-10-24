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

.h:

int Theta = 25.0, ThetaHeating = 26.0, ThetaCooling = 24.0, efficiency = 0, capacity = 0;
Load Thermostat Definitions(int type, int* settings);
Process Data(int* units, int* efficiency, int* capacity);

int Load Thermostat Definitions(int type, int* settings);
void Process Data(int* units, int* efficiency, int* capacity);

int Load Thermostat Definitions(int type, int* settings) {
    if (type == 0) {
        int count = 0;
        for (int i = 0; i < *settings; i++) {
            if (type == 0 && settings[i] == ThetaCooling) {
                count ++;
            }
        }
        return count;
    }
    else if (type == 1) {
        int count = 0;
        for (int i = 0; i < *settings; i++) {
            if (type == 1 && settings[i] == ThetaHeating) {
                count ++;
            }
        }
        return count;
    }
    else {
        return 0;
    }
}

int* ProcessData(int* units, int* efficiency, int* capacity) { if (units == NULL || *units == 0) return new int[0]; int totalEfficiency = 0, totalCapacity = 0; for (int i = 0; i < *units; i++) { totalEfficiency += *efficiency; totalCapacity += *capacity; } return new int[] { totalEfficiency, totalCapacity }; } return JSONResponse({ 

