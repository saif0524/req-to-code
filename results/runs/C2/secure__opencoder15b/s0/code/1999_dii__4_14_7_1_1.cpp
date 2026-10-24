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

void validateInput(const std::string& input);
void handleMemory(const std::string& data);
void handleResource(const std::string& resource);
std::string getOutput(const std::string& input);

void validateInput(const std::string& input) {
  // Check if the input string is empty
  if (input.empty()) {
    throw std::invalid_argument("Input string is empty.");
  }
  // Check if the input string contains only valid characters
  for (char c : input) {
    if (!std::isprint(c)) {
      throw std::invalid_argument("Input string contains non-printable characters.");
    }
  }
}

void handleMemory(const std::string& data) {
   // Check if the input string is empty
   if (data.empty()) {
     throw std::invalid_argument("Input string is empty.");
   }
   // Check if the input string contains only valid characters
   for (char c : data) {
     if (!std::isprint(c)) {
       throw std::invalid_argument("Input string contains non-printable characters.");
     }
   }
}

void handleResource(const std::string& resource) {
    // Check if the input string is empty
    if (resource.empty()) {
        throw std::invalid_argument("Input string is empty.");
    }
    // Check if the input string contains only valid characters
    for (char c : resource) {
        if (!std::isprint(c)) {
            throw std::invalid_argument("Input string contains non-printable characters.");
        }
    }
}

std::string getOutput(const std::string& input) {
    // Check if the input string is empty
    if (input.empty()) {
        throw std::invalid_argument("Input string is empty.");
    }
    // Check if the input string contains only valid characters
    for (char c : input) {
        if (!std::isprint(c)) {
            throw std::invalid_argument("Input string contains non-printable characters.");
        }
    }
    // Process the input string and generate the output
    // Add your logic here
    std::string output = "Processed: " + input;
    return output;
}

