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

using Entry = std::chrono::system_clock::time_point; using namespace std::chrono;
<chrono>
struct Entry {
  Entry(const std::string& title, const std::string& username, const std::string& url, const std::string& notes)
    : title(title), username(username), url(url), notes(notes), expiration_time(std::chrono::system_clock::now()) {}

  std::string title;
  std::string username;
  std::string url;
  std::string notes;
  Entry* next;

  Entry* create_entry(const std::string& title, const std::string& username, const std::string& url, const std::string& notes) {
    Entry* entry = new Entry(title, username, url, notes);
    entry->next = nullptr;
    return entry;
  }

  void delete_entry(Entry* entry) {
    if (entry->next != nullptr) {
      delete_entry(entry->next);
    }
    delete entry;
  }

  void set_notes(Entry* entry, const std::string& new_notes) {
    entry->notes = new_notes;
  }

  void set_expiration_time(Entry* entry, const std::chrono::system_clock::time_point& expiration_time) {
    entry->expiration_time = expiration_time;
  }
};

void create_tan(const std::string& title, const std::string& username, const std::string& url, const std::string& notes);
void use_tan(const std::string& title);
void update_tan(const std::string& title, const std::string& new_notes);
void delete_tan(const std::string& title);

void create_tan(const std::string& title, const std::string& username, const std::string& url, const std::string& notes) {
  Entry* entry = create_entry(title, username, url, notes);
  if (entry != nullptr) {
    set_expiration_time(entry, std::chrono::system_clock::now());
    return;
  }
  return;
}

void use_tan(const std::string& title) {
  Entry* entry = find_entry(title);
  if (entry == nullptr) {
    return;
  }
  set_expiration_time(entry, std::chrono::system_clock::now());
  return;
}

void update_tan(const std::string& title, const std::string& new_notes) {
  Entry* entry = find_entry(title);
  if (entry != nullptr) {
    set_notes(entry, new_notes);
    set_expiration_time(entry, std::chrono::system_clock::now());
  }
}


struct Entry {
  Entry(const std::string& title, const std::string& username, const std::string& url, const std::string& notes)
    : title(title), username(username), url(url), notes(notes), expiration_time(std::chrono::system_clock::now()) {}

  std::string title;
  std::string username;
  std::string url;
  std::string notes;
  Entry* next;

  Entry* create_entry(const std::string& title, const std::string& username, const std::string& url, const std::string& notes) {
    Entry* entry = new Entry(title, username, url, notes);
    entry->next = nullptr;
    return entry;
  }

  void delete_entry(Entry* entry) {
    if (entry->next != nullptr) {
      delete_entry(entry->next);
    }
    delete entry;
  }

  void set_notes(Entry* entry, const std::string& new_notes) {
    entry->notes = new_notes;
  }

  void set_expiration_time(Entry* entry, const std::chrono::system_clock::time_point& expiration_time) {
    entry->expiration_time = expiration_time;
  }

  std::chrono::system_clock::time_point expiration_time;
};

void delete_tan(const std::string& title) {
  Entry* entry = find_entry(title);
  if (entry != nullptr) {
    delete_entry(entry);
  }
}

