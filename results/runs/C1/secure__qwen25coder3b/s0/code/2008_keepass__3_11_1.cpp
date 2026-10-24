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

void load_entry(const std::string& entry_id, Entry& entry);
void save_entry(const Entry& entry);
void update_entry(const Entry& entry);
void display_entry_form(const Entry& entry);
void handle_entry_changes(const Entry& entry);

void load_entry(const std::string& entry_id, Entry& entry) {
  // Load the entry from the database using the shared declarations
  auto loaded_entry = load_entry(entry_id);
  // Copy the loaded data into the entry object
  entry = loaded_entry;
}

void save_entry(const Entry& entry) {
  auto loaded_entry = load_entry(entry.id);
  loaded_entry = entry;
  save_entry(loaded_entry);
}

void update_entry(const Entry& entry) {
  auto loaded_entry = load_entry(entry.id);
  loaded_entry = entry;
  save_entry(loaded_entry);
}

struct Entry {
  std::string group;
  std::string title;
  std::string user_name;
  std::string password;
  std::string url;
  std::string notes;
  std::string expiration_date;
  std::string attachment_file;

  Entry() = default;
  ~Entry() = default;

  void set_group(const std::string& group) { this->group = group; }
  std::string get_group() const { return group; }

  void set_title(const std::string& title) { this->title = title; }
  std::string get_title() const { return title; }

  void set_user_name(const std::string& user_name) { this->user_name = user_name; }
  std::string get_user_name() const { return user_name; }

  void set_password(const std::string& password) { this->password = password; }
  std::string get_password() const { return password; }

  void set_url(const std::string& url) { this->url = url; }
  std::string get_url() const { return url; }

  void set_notes(const std::string& notes) { this->notes = notes; }
  std::string get_notes() const { return notes; }

  void set_expiration_date(const std::string& expiration_date) { this->expiration_date = expiration_date; }
  std::string get_expiration_date() const { return expiration_date; }

  void set_attachment_file(const std::string& attachment_file) { this->attachment_file = attachment_file; }
  std::string get_attachment_file() const { return attachment_file; }
};

void handle_entry_changes(const Entry& entry) {
  // Validate input
  if (entry.group.empty() || entry.title.empty() || entry.user_name.empty() || entry.password.empty() || entry.url.empty() || entry.notes.empty() || entry.expiration_date.empty() || entry.attachment_file.empty()) {
    std::cerr << "Error: Entry fields cannot be empty." << std::endl;
    return;
  }

  // Load the current entry state
  Entry current_entry;
  load_entry(entry.id, current_entry);

  // Update the entry with the new values
  current_entry.group = entry.group;
  current_entry.title = entry.title;
  current_entry.user_name = entry.user_name;
  current_entry.password = entry.password;
  current_entry.url = entry.url;
  current_entry.notes = entry.notes;
  current_entry.expiration_date = entry.expiration_date;
  current_entry.attachment_file = entry.attachment_file;

  // Save the updated entry back to the database
  save_entry(current_entry);
}

