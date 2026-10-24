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

initialize_operational_parameters(std::string initialization_file_path);

void initialize_operational_parameters(std::string initialization_file_path) {
   // Open the initialization file
   std::ifstream init_file(initialization_file_path);
   if (!init_file.is_open()) {
     throw std::runtime_error("Failed to open initialization file.");
   }

   // Read the maximum number of heating or cooling units
   int max_units;
   init_file >> max_units;

   // Set the maximum number of heating or cooling units in the THEMAS system
   themas_system.set_max_units(max_units);
}

