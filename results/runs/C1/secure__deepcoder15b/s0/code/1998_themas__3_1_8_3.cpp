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

std::pair<std::object, std::string> generate_event(std::string event_type);
std::pair<std::long long, std::string> get_system_time_and_params();
bool validate_input(std::string input);
void ensure_safe_release(std::string resource);
void store_event(std::pair<std::object, std::string> event_data, std::db& db);

std::pair<std::long long, std::string> get_system_time_and_params() 
 
    { 
    
    unsigned long long max_time_t = time_t::max(); 
    unsigned long long now = time_t::now(); 
    long long time_in_seconds = max_time_t - now; 
    double time_in_milliseconds = static_cast<double>(time_in_seconds) / 1000.0; 
    return std::make_pair(static_cast<long long>(time_in_milliseconds), "System Time: " + std::to_string(time_in_milliseconds)); 
    }

bool validate_input(std::string input) {
  // Create a vector to store all numbers found
  std::vector<std::string> numbers_list;

  // Use std::sregex_iterator to find all digits in the input string
  std::sregex_iterator iter(input, std::sregex_iterator::digits, std::sregex_iterator::any);
  std::sregex_iterator-exit iter_ex(input, std::sregex_iterator::digits, std::sregex_iterator::any);

  // Iterate over all matches
  while (iter != iter_ex) {
    std::smatch match = *iter;
    std::string num_str = match[1];
    std::size_t num = std::stoull(num_str);

    // Check if the number is within the acceptable range
    if (num < 1 || num > 10000) {
      return false;
    }

    // Add the number to the list
    numbers_list.push_back(num_str);
    ++iter;
  }

  // Return true if all numbers are within range
  return true;
}

std::string resource = ...; // The input string here

// Extract all numbers from the resource string
std::vector<std::string> numbers;
std::sregex_iterator iter(resource, std::sregex_iterator::digits, std::sregex_iterator::any);
std::sregex_iterator_ex iter_ex(resource, std::sregex_iterator::digits, std::sregex_iterator::any);

while (iter != iter_ex) {
    std::smatch match = *iter;
    std::string num_str = match[1];
    std::size_t num = std::stoull(num_str);

    if (num < 1 || num > 10000) {
        return std::make_tuple(false, "The number ... is outside the acceptable range (1-10000)");
    }

    numbers.push_back(num_str);
    ++iter;
}

return true;

void store_event(std::pair<std::object, std::string> event_data, std::db& db) {
    // Create a new entry in the Access database
    db.insert({
      std::make_tuple(event_data.first, event_data.second, 
      std::make_tuple(get_system_time_and_params(event_data).second, 
      time_t::now() + std::chrono::seconds(0))
    });
  }
  // reason: create entry, use get_system_time_and_params, store event data
  // code: store_event function as above
  // reasoning: create entry in database, use helper functions, store event data
  return;
  }

