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

std::pair<std::long long, std::string> get_system_time_and_params();
bool validate_input(std::string input);

std::pair<std::long long, std::string> get_system_time_and_params() 
 
    { 
    
    unsigned long long max_time_t = time_t::max(); 
    unsigned long long now = time_t::now(); 
    long long time_in_seconds = max_time_t - now; 
    double time_in_milliseconds = static_cast<double>(time_in_seconds) / 1000.0; 
    return std::make_pair(static_cast<long long>(time_in_milliseconds), "System Time: " + std::to_string(time_in_milliseconds)); 
    }

bool validate_input(std::string input) {
    // Extract all numbers from the input string
    std::regex numbers_regex(std::regex_searcher::digits, std::regex_iterator::none);
    auto numbers = std::sregex_iterator<std::string>(std::string::all_characters_, numbers_regex);
    std::vector<std::string> numbers_list;
    for (std::sregex_iterator i = numbers.begin(); i != numbers.end(); ++i) {
        std::string match = *i;
        numbers_list.push_back(match);
    }

    // Check if there are any numbers
    if (numbers_list.empty()) {
        return true;
    }

    // Determine if each number is positive, negative, or zero
    for (size_t i = 0; i < numbers_list.size(); ++i) {
        std::string num_str = numbers_list[i];
        std::size_t num = std::stoull(num_str);
        std::string sign;
        if (num < 0) {
            sign = std::string(-1, 1);
            num = -num;
        } else if (num == 0) {
            sign = std::string(0, 1);
        } else {
            sign = std::string(1, 1);
        }

        // Check if the number is within acceptable ranges
        if (num < 1 || num > 10000) { // Adjust ranges as needed
            return false;
        }

        // Add reasoning here
        // Step 1: Extract numbers from input string
        // Step 2: Check if any numbers exist
        // Step 3: Validate each number against acceptable range
        // Step 4: Return false if any number is out of range
    }

    return true;
}

