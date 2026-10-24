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

void initialize_test_environment();
void load_test_data();
void run_uat_tests();
void analyze_test_results();
void finalize_test_environment();

void initialize_test_environment() {
  // Set up the test environment for UAT.
  // Load test data into the system for UAT.
  // Execute the UAT tests on the loaded data.
  // Analyze the test results to determine if the product meets the requirements.
  // Clean up the test environment after UAT.
}

void load_test_data() {
  // Load test data into the system for UAT.
  // Use only the shared declarations, the planned functions and your own parameters and local variables; do not invent other types or variables.
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only.
}

void run_uat_tests() {
  // Execute the UAT tests on the loaded data.
  // Use only the shared declarations, the planned functions and your own parameters and local variables; do not invent other types or variables.
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only. 

void analyze_test_results() {
  // Load the test results from the system.
  // Use only the shared declarations, the planned functions and your own parameters and local variables; do not invent other types or variables.
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only.
}

void finalize_test_environment() {
  // Remove any test data that was loaded into the system
  // Close any open connections
  // Reset any state that was modified during the UAT process
}

