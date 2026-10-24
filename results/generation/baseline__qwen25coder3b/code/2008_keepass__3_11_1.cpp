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

void selectEntry(Entry& entry);
void editEntry(Entry& entry);
void updateEntry(Entry& entry);
void saveEntry(Entry& entry);
void displayEntryForm(Entry& entry);

void selectEntry(Entry& entry) { // Selects an entry for editing }

void editEntry(Entry& entry) {
  displayEntryForm(entry);
  updateEntry(entry);
  saveEntry(entry);
}

void updateEntry(Entry& entry) {
  displayEntryForm(entry);
  entry.update();
  saveEntry(entry);
}

void saveEntry(Entry& entry) {
  displayEntryForm(entry);
  entry.save();
}

void displayEntryForm(Entry& entry) {
  std::cout << "Group: " << entry.getGroup() << std::endl;
  std::cout << "Title: " << entry.getTitle() << std::endl;
  std::cout << "User Name: " << entry.getUserName() << std::endl;
  std::cout << "Password: " << entry.getPassword() << std::endl;
  std::cout << "URL: " << entry.getUrl() << std::endl;
  std::cout << "Notes: " << entry.getNotes() << std::endl;
  std::cout << "Expiration Date: " << entry.getExpirationDate() << std::endl;
  std::cout << "Attachment File: " << entry.getAttachmentFile() << std::endl;
}

