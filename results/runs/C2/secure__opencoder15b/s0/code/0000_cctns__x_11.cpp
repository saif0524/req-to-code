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

MAX_OBJECTS, JSON
MAX_OBJECTS, JSON

struct JSON {
    std::string error;
};

int get_help_text(int object);

void show_help(int action, int object);
void show_context_help(int object);
void show_object_help(int object);
void show_action_help(int action);
void show_object_context_help(int object);

void show_help(int action, int object) {
    // Check if the object is valid
    if (object < 0 || object >= MAX_OBJECTS) {
        // Object is invalid, return an error message
        return JSON{"error": "Invalid object"};
    }

    // Retrieve the appropriate help text
    const std::string& help_text = get_help_text(object);

    // Display the help text to the user
    std::cout << help_text;
}

void show_context_help(int object) {
   // Check if the object is valid
   if (object < 0 || object >= MAX_OBJECTS) {
     // Object is invalid, return an error message
     return JSON{"error": "Invalid object"};
   }

   // Retrieve the appropriate help text
   const std::string& help_text = get_help_text(object);

   // Display the help text to the user
   std::cout << help_text;
}

void show_object_help(int object) {
    // Check if the object is valid
    if (object < 0 || object >= MAX_OBJECTS) {
      // Object is invalid, return an error message
     return JSON{"error": "Invalid object"};
    }

    // Retrieve the appropriate help text
    const std::string& help_text = get_help_text(object);

    // Display the help text to the user
    std::cout << help_text;
}

void show_action_help(int action) {
     // Check if the action is valid
     if (action < 0 || action >= MAX_ACTIONS) {
         // Action is invalid, return an error message
         return JSON{{"error": "Invalid action"}};
     }

     // Retrieve the appropriate help text
     const std::string& help_text = get_help_text(action);

     // Display the help text to the user
     std::cout << help_text;
}

void show_object_context_help(int object) {
     // Check if the object is valid
     if (object < 0 || object >= MAX_OBJECTS) {
         // Object is invalid, return an error message
         return JSON{{"error": "Invalid object"}};
     }

     // Retrieve the appropriate help text
     const std::string& help_text = get_help_text(object);

     // Display the help text to the user
     std::cout << help_text;
}

