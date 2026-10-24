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

string get_input() -> string;
vector<string> save_data(vector<string> data) -> string;
string communicate(string message) -> bool;
bool is_operation_success() -> bool;
void manage_state() -> void;

string get_input() -> string {
    
    string message = "Please select between adding a new item or selecting a product: \n1. Add new item\n2. Select product\n Enter your choice (1 or 2): \n";
    
    string choice;
    
    cin >> choice;
    
    if (choice == "1") {
        return "Add new item";
    } else if (choice == "2") {
        return "Select product";
    } else {
        return "Invalid choice";
    }
    
    return "Select product";
    }

vector<string> save_data(vector<string> data) -> string {
    string file_path = 

string communicate(string message) -> bool {
    vector<string> output;
    // Send the message to the system's console
    string stream;
    try {
        stream = output.push_back(message);
        // Check if the message was successfully sent
        if (output.empty()) {
            return false;
        }
        return true;
    } catch (const invalid_argument& e) {
    } catch (const out_of_range& e) {
    } catch (const exception& e) {
    }
    return false;
  }
  

bool is_operation_success() -> bool {
    return communicate("The last operation was successful.");
}

void manage_state() {
    string message = "Loading new version";
    communicate(message);
  }

