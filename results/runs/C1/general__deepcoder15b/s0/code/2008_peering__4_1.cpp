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

The function uses std::string, which is the correct type, and std::string is the correct function to create the string.

std::string readUserInput(std:: pointer &input);
std:: string writeOutput(std:: pointer &output, int code);
std:: string handleError(int code);
std:: array< int> processDeviceData(std:: array< int> device);
void closeInterface(std:: pointer &context);

std::string readUserInput(std::string &input) { // Reads user input and returns it as a string.
    std::string userInput;
    while (true) {
        std::string c;
        std::cin >> c;
        if (c.empty()) {
            break;
        }
        userInput += c;
    }
    return userInput;
    }

string writeOutput(string &output, int code) {
    string s;
    s += code;
    output = s;
    return output;
    }

string handleError(int code) {
  switch (code) {
    case 1: return "Invalid parameters";
    case 2: return "Invalid output";
    case 3: return "Connection failed";
    case 4: return "Invalid device";
    case 5: return "Invalid address";
    case 6: return "Invalid port";
    case 7: return "Invalid protocol";
    case 8: return "Invalid connection";
    case 9: return "Invalid device version";
    case 10: return "Invalid device type";
    case 11: return "Invalid device model";
    case 12: return "Invalid device version";
    case 13: return "Invalid device type";
    case 14: return "Invalid device model";
    case 15: return "Invalid device version";
    case 16: return "Invalid device type";
    case 17: return "Invalid device model";
    case 18: return "Invalid device version";
    case 19: return "Invalid device type";
    case 20: return "Invalid device model";
    case 21: return "Invalid device version";
    case 22: return "Invalid device type";
    case 23: return "Invalid device model";
    case 24: return "Invalid device version";
    case 25: return "Invalid device type";
    case 26: return "Invalid device model";
    case 27: return "Invalid device version";
    case 28: return "Invalid device type";
    case 29: return "Invalid device model";
    case 30: return "Invalid device version";
    case 31: return "Invalid device type";
    case 32: return "Invalid device model";
    case 33: return "Invalid device version";
    case 34: return "Invalid device type";
    case 35: return "Invalid device model";
    case 36: return "Invalid device version";
    case 37: return "Invalid device type";
    case 38: return "Invalid device model";
    case 39: return "Invalid device version";
    case 40: return "Invalid device type";
    case 41: return "Invalid device model";
    case 42: return "Invalid device version";
    case 43: return "Invalid device type";
    case 44: return "Invalid device model";
    case 45: return "Invalid device version";
    case 46: return "Invalid device type";
    case 47: return "Invalid device model";
    case 48: return "Invalid device version";
    case 49: return "Invalid device type";
    case 50: return "Invalid device model";
    default: return "Invalid parameters";
  }
  }
  

array<int> processDeviceData(array<int> device) {
  array<int> result;
  for (int i = 0; i < device.size(); i++) {
    int value = device[i];
    if (value >= 1 && value <= 100) {
      result.push_back(value - 1);
    } else {
      result.push_back(value);
    }
    }
    return result;
  }
  return result;
  }

