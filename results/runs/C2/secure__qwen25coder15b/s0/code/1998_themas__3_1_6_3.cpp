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

void read_input(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status);
void generate_signal(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status);
void output_status(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status);
void generate_event(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status);

void read_input(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status) {
  std::cin >> heating_unit >> cooling_unit >> on_off_status;
}

void generate_signal(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status) {
  std::cout << "Generating signal for heating unit: " << heating_unit << std::endl;
  std::cout << "Generating signal for cooling unit: " << cooling_unit << std::endl;
  std::cout << "Generating signal for ON/OFF status: " << on_off_status << std::endl;
  std::cout << "Generating event for heating unit: " << heating_unit << std::endl;
  std::cout << "Generating event for cooling unit: " << cooling_unit << std::endl;
  std::cout << "Generating event for ON/OFF status: " << on_off_status << std::endl;
}

void output_status(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status) {
  std::cout << "Current status of heating unit: " << heating_unit << std::endl;
  std::cout << "Current status of cooling unit: " << cooling_unit << std::endl;
  std::cout << "Current status of ON/OFF status: " << on_off_status << std::endl;
}

void generate_event(std::string& heating_unit, std::string& cooling_unit, std::string& on_off_status) {
  std::cout << "Generating event for heating unit: " << heating_unit << std::endl;
  std::cout << "Generating event for cooling unit: " << cooling_unit << std::endl;
  std::cout << "Generating event for ON/OFF status: " << on_off_status << std::endl;
}

