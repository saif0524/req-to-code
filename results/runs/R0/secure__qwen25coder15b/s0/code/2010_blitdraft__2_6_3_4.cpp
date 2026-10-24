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

void send_release_notes(const std::string& release_notes, const std::string& email_address);
std::string get_release_notes() const;
void set_release_notes(const std::string& release_notes);
std::string get_email_address() const;
void set_email_address(const std::string& email_address);

void send_release_notes(const std::string& release_notes, const std::string& email_address) {
  std::string email_address = get_email_address();
  send_email(release_notes, email_address);
}

std::string get_release_notes() const { return release_notes; }

void set_release_notes(const std::string& release_notes) {
  std::string current_release_notes = get_release_notes();
  release_notes = current_release_notes;
  send_release_notes(release_notes, get_email_address());
}

std::string get_email_address() const { return email_address; }

void set_email_address(const std::string& email_address) {
  std::string current_release_notes = get_release_notes();
  release_notes = current_release_notes;
  send_release_notes(release_notes, email_address);
}

