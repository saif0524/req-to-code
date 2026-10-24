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

bool validate_auto_type_sequence(const std::string& sequence);
std::string extract_first_auto_type_sequence(const std::string& note);
std::vector<std::string> extract_auto_type_sequences(const std::string& note);
std::string format_auto_type_sequence(const std::string& sequence);
void handle_auto_type_sequence(const std::string& sequence, std::string& note);

bool validate_auto_type_sequence(const std::string& sequence) {
  std::string first_sequence = extract_first_auto_type_sequence(sequence);
  if (first_sequence.empty()) {
    return false;
  }
  if (first_sequence.length() > 59) {
    return false;
  }
  return true;
}

std::string extract_first_auto_type_sequence(const std::string& note) {
  size_t pos = note.find("Auto-Type:");
  if (pos == std::string::npos) {
    return "";
  }
  pos += 10;
  size_t end_pos = note.find("", pos);
  if (end_pos == std::string::npos) {
    return "";
  }
  return note.substr(pos, end_pos - pos);
}

std::vector<std::string> extract_auto_type_sequences(const std::string& note) {
  std::vector<std::string> sequences;
  size_t pos = 0;
  while ((pos = note.find("Auto-Type:", pos)) != std::string::npos) {
    pos += 10;
    size_t end_pos = note.find("", pos);
    if (end_pos == std::string::npos) {
      break;
    }
    sequences.push_back(note.substr(pos, end_pos - pos));
  }
  return sequences;
}

std::string format_auto_type_sequence(const std::string& sequence) {
  std::string formatted_sequence;
  size_t pos = 0;
  while ((pos = sequence.find(

void handle_auto_type_sequence(const std::string& sequence, std::string& note) {
  if (!validate_auto_type_sequence(sequence)) {
    return;
  }
  std::string first_sequence = extract_first_auto_type_sequence(note);
  if (!first_sequence.empty()) {
    first_sequence = format_auto_type_sequence(first_sequence);
    insert_auto_type_sequence(first_sequence, note);
  }
}

