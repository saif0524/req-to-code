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

void select_report_type();
void select_report_file_location();
void generate_operational_history_report();
void generate_statistical_report();

void select_report_type() {
  select_report_file_location();
  int report_type;
  std::cout << "Select report type:\n1. Operational history report\n2. Statistical summary report\n";
  std::cin >> report_type;
  if (report_type == 1) {
    generate_operational_history_report();
  } else if (report_type == 2) {
    generate_statistical_report();
  } else {
    std::cout << "Invalid report type. Please try again.\n";
    select_report_type();
  }
}

void select_report_file_location() {
  std::cout << "Select report file location:\n";
  std::string file_location;
  std::cin >> file_location;
  std::cout << "Select report file name:\n";
  std::string file_name;
  std::cin >> file_name;
  std::cout << "File location and name selected: \n";
}

void generate_operational_history_report() {
  select_report_file_location();
  int report_type;
  std::cout << "Select report type:\n1. Operational history report\n2. Statistical summary report\n";
  std::cin >> report_type;
  if (report_type == 1) {
    generate_operational_history_report();
  } else if (report_type == 2) {
    generate_statistical_report();
  } else {
    std::cout << "Invalid report type. Please try again.\n";
    generate_operational_history_report();
  }
}

void generate_statistical_report() {
  select_report_file_location();
  int report_type;
  std::cout << "Select report type:\n1. Operational history report\n2. Statistical summary report\n";
  std::cin >> report_type;
  if (report_type == 1) {
    generate_operational_history_report();
  } else if (report_type == 2) {
    generate_statistical_report();
  } else {
    std::cout << "Invalid report type. Please try again.\n";
    generate_statistical_report();
  }
}

