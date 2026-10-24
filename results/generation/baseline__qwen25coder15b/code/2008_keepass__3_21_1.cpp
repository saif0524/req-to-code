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

void create_tan(const std::string& title, const std::string& username, const std::string& url, const std::string& notes);
void use_tan(const std::string& title);
std::time_t get_tan_expiration_time(const std::string& title);
void update_tan_notes(const std::string& title, const std::string& notes);
void delete_tan(const std::string& title);

void create_tan(const std::string& title, const std::string& username, const std::string& url, const std::string& notes) {
  // Use the create_tan function from the shared declarations to add the entry
  create_tan(title, username, url, notes);

  // Return a JSON object with a 'success' key set to 'true' if the entry is added successfully
  return {"success": true, "reason": "Entry added successfully"};
}

void use_tan(const std::string& title) {
  // Get the current time
  std::time_t current_time = std::time(nullptr);

  // Get the expiration time of the TAN entry
  std::time_t expiration_time = get_tan_expiration_time(title);

  // Set the expiration time of the TAN entry to the current time
  set_tan_expiration_time(title, current_time);

  // Update the notes of the TAN entry
  update_tan_notes(title, 'Used');

  // Delete the TAN entry from the database
  delete_tan(title);
}

std::time_t get_tan_expiration_time(const std::string& title) {
  // Retrieve the expiration time of the TAN entry from the database
  std::time_t expiration_time = get_tan_expiration_time_from_database(title);

  // Set the expiration time of the TAN entry to the current time
  set_tan_expiration_time(title, std::time(nullptr));

  // Return the expiration time of the TAN entry
  return expiration_time;
}

void update_tan_notes(const std::string& title, const std::string& notes) {
  // Retrieve the current time
  std::time_t current_time = std::time(nullptr);

  // Set the expiration time of the TAN entry to the current time
  set_tan_expiration_time(title, current_time);

  // Update the notes of the TAN entry
  update_tan_notes(title, notes);

  // Delete the TAN entry from the database
  delete_tan(title);
}

void delete_tan(const std::string& title) {
  // Use the delete_tan function from the shared declarations to remove the entry
  delete_tan(title);

  // Set the expiration time of the TAN entry to the current time
  set_tan_expiration_time(title, std::time(nullptr));

  // Return a JSON object with a 'success' key set to 'true' if the entry is deleted successfully
  return {

