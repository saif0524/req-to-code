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
  std::cout << "Please select a report type:\n1. Operational history report\n2. Statistical summary report\n
  Enter your choice: ";\nint choice;\nstd::cin >> choice;\n
  if (choice == 1) {
    select_report_file_location();
    generate_operational_history_report();
  } else if (choice == 2) {
    select_report_file_location();
    generate_statistical_report();
  } else {
    std::cout << "Invalid choice. Please try again.\n";
    select_report_type();
  }
}

void select_report_file_location() {
  std::string location;
  std::cout << "Please enter the location and name of the ASCII report file: ";
  std::cin >> location;
  generate_report_file(location);
}

void generate_operational_history_report() {
  std::string location;
  select_report_file_location(&location);
  std::vector<Event> events = get_all_events();
  sort_events(&events);
  generate_report_file(&location, &events);
}

void generate_statistical_report() {
  std::string location;
  select_report_file_location(&location);
  std::vector<Event> events = get_all_events();
  sort_events(&events);
  generate_report_file(&location, &events);
  calculate_statistics(&location, &events);
}

