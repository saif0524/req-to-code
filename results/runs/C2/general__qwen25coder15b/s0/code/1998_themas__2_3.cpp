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

class Themas {
  public:
    static double read_temperature();
    static bool check_temperature(double temperature);
    static std::string generate_report();
    static void send_report(const std::string& report);
};
using namespace std;

double read_temperature();
bool check_temperature(double temperature);
std::string generate_report();
void send_report(const std::string& report);

double read_temperature() {
  // Read the current temperature from the system
  double temperature = get_current_temperature();
  return temperature;
}

bool check_temperature(double temperature) {  double limit = 20.0;  // Define the acceptable temperature limit  if (temperature < limit || temperature > limit + 5.0) {    return false;  }  return true; }

std::string generate_report() {  double temperature = read_temperature();  bool is_within_limit = check_temperature(temperature);  std::string report = "Current temperature: " + std::to_string(temperature) + "\n";  if (!is_within_limit) {    report += "Warning: Temperature is out of acceptable limits.\n";  }  report += "System status: " + get_system_status() + "\n";  return report; }

void send_report(const std::string& report) { std::cout << report << std::endl; }

