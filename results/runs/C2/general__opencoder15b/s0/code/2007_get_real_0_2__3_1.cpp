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

get_real_data();

std::vector<College> get_real_data() {
    // Fetch data from API
    std::vector<College> colleges = fetch_data_from_API();

    // Filter and organize the data
    std::vector<College> filtered_colleges = filter_and_organize(colleges);

    // Return the filtered and organized data
    return filtered_colleges;
}

