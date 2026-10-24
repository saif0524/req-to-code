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

std::string load_auto_type_sequence(const std::string& entry_note);
void save_auto_type_sequence(const std::string& entry_note, const std::string& sequence);
void invoke_auto_type(const std::string& sequence);
void handle_context_menu_command(const std::string& entry_note);
void handle_ctrl_v(const std::string& entry_note);

std::string load_auto_type_sequence(const std::string& entry_note) {
  std::string sequence;
  size_t start = entry_note.find("Auto-Type");
  if (start != std::string::npos) {
    size_t end = entry_note.find(' ', start);
    if (end != std::string::npos) {
      sequence = entry_note.substr(start + 9, end - start - 9);
    } else {
      sequence = entry_note.substr(start + 9);
    }
  }
  return sequence;
}

void save_auto_type_sequence(const std::string& entry_note, const std::string& sequence) {
  size_t start = entry_note.find("Auto-Type");
  if (start != std::string::npos) {
    size_t end = entry_note.find('', start);
    if (end != std::string::npos) {
      sequence = entry_note.substr(start + 9, end - start - 9);
    } else {
      sequence = entry_note.substr(start + 9);
    }
  }
}

void invoke_auto_type(const std::string& sequence) {
  if (sequence.empty()) {
    return;
  }
  std::string prefix = sequence.substr(0, sequence.find(' '));
  std::string suffix = sequence.substr(sequence.find(' ') + 1);
  invoke_auto_type(prefix);
  invoke_auto_type(suffix);
}

void handle_context_menu_command(const std::string& entry_note) {
  size_t start = entry_note.find('Auto-Type');
  if (start != std::string::npos) {
    size_t end = entry_note.find(' ', start);
    if (end != std::string::npos) {
      std::string prefix = entry_note.substr(start + 9, end - start - 9);
      std::string sequence = entry_note.substr(end + 1);
      invoke_auto_type(prefix);
      invoke_auto_type(sequence);
    } else {
      std::string prefix = entry_note.substr(start + 9);
      invoke_auto_type(prefix);
    }
  }
}

void handle_ctrl_v(const std::string& entry_note) {
  size_t start = entry_note.find('Auto-Type');
  if (start != std::string::npos) {
    size_t end = entry_note.find(' ', start);
    if (end != std::string::npos) {
      std::string prefix = entry_note.substr(start + 9, end - start - 9);
      std::string sequence = entry_note.substr(end + 1);
      invoke_auto_type(prefix);
      invoke_auto_type(sequence);
    } else {
      std::string prefix = entry_note.substr(start + 9);
      invoke_auto_type(prefix);
    }
  }
}

