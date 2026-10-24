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

std::vector<std::string> get_coe_components();
std::string get_data_item_description();

const std::vector<std::string> get_coe_components() { return {"COE Component 1", "COE Component 2", "COE Component 3"}; }

std::string get_data_item_description() { return "Detailed information about the interfaces as specified in paragraph 3.4 of the Data Item Description DI-IPSC-81433."; }

