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

<your corrected declarations here>

vector<pair<int, double>> get_thermostats() -> vector<pair<int, double>>

int select_thermostat(int index, vector<pair<int, double>>*thermostats, vector<int>&*selected_thermostat) -> int

bool validate_temperature(int index, vector<pair<int, double>>*thermostats, int*proposed_temp) -> bool

vector<pair<int, double>> list_valid Temperatures(vector<pair<int, double>>*thermostats) -> vector<pair<int, double>>

std::pair<std::vector<std::pair<int, double>>, std::vector<std::pair<int, double>>> get_thermostats() -> std::pair<std::vector<std::pair<int, double>>, std::vector<std::pair<int, double>>>>;
int select_thermostat(int index, std::pair<int, double>>*thermostats, std::vector<int>&*selected_thermostat) -> int;
bool validate_temperature(int index, std::pair<int, double>>*thermostats, int*proposed_temp) -> bool;
std::vector<std::pair<int, double>> list_valid Temperatures(std::pair<int, double>>*thermostats) -> std::vector<std::pair<int, double>>;

std::pair<std::vector<std::pair<int, double>>*, std::vector<int>> get_thermostats() -> std::pair<std::vector<std::pair<int, double>>*, std::vector<int>> {
return std::make_pair(std::vector<std::pair<int, double>>(), std::vector<int});
}

int select_thermostat(int index, std::pair<int, double> *thermostats, std::vector<int>& *selected_thermostat) -> int {
    for (int i = 0; i < *thermostats.size(); i++) {
        if (i == index) {
            pair<int, double> t = *thermostats[i];
            int temp = t.first;
            selected_thermostat->assign(temp);
            return temp;
        }
    }
    return -1;
  }

int select_thermostat(int index, std::pair<int, double>> *thermostats, std::vector<int>& *selected_thermostat) -> int {
  for (int i = 0; i < *thermostats.size(); i++) {
    if (i == index) {
      pair<int, double> t = *thermostats[i];
      int temp = t.first;
      selected_thermostat->assign(temp);
      return temp;
    }
  }
  return -1;
}

bool list_valid Temperatures(std::pair<std::vector<int>, std::vector<int>> *thermostats) -> bool {
    auto the_thermostats = static_cast-auto*(thermostats);
    std::vector<std::pair<int, double>> result;
    for (auto* t = the_thermostats->get<0>(); t != the_thermostats->get<0>(); t++) {
        if (validate_temperature(*the_thermostats, the_thermostats, t)) {
            result.push_back(t);
        }
    }
    return result;
}

