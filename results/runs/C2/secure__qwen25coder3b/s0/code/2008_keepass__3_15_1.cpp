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

std::string parseAutoTypeSequence(const std::string& note);
bool validateAutoTypeSequence(const std::string& sequence);
std::string getAutoTypeSequence(const std::vector<Entry>& entries, const std::string& entryName);
void invokeAutoType(const std::string& sequence);
void handleAutoTypeHotKey(const std::vector<Entry>& entries);

std::string parseAutoTypeSequence(const std::string& note) {
  size_t pos = note.find("Auto-Type");
  if (pos != std::string::npos) {
    pos += 8; // Move past the prefix length
    while (pos < note.size() && std::isspace(note[pos])) {
      ++pos; // Skip leading whitespace
    }
    size_t end = note.find_first_not_of(" ", pos);
    return note.substr(pos, end - pos);
  }
  return "";
}

bool validateAutoTypeSequence(const std::string& sequence) {
  if (sequence.substr(0, 8) != "Auto-Type") {
    return false;
  }
  size_t length = sequence.size() - 8;
  if (length > 0 && std::isspace(sequence[length - 1])) {
    return false;
  }
  return true;
}

std::string getAutoTypeSequence(const std::vector<Entry>& entries, const std::string& entryName) {
  for (const auto& entry : entries) {
    if (entry.name == entryName) {
      std::string sequence = parseAutoTypeSequence(entry.notes);
      if (!sequence.empty()) {
        return sequence;
      }
    }
  }
  return "";
}

void invokeAutoType(const std::string& sequence) {
  INPUT inputs[sequence.size()];
  for (size_t i = 0; i < sequence.size(); ++i) {
    inputs[i].type = INPUT_KEYBOARD;
    inputs[i].ki.wVk = sequence[i];
    inputs[i].ki.wScan = 0;
    inputs[i].ki.dwFlags = 0;
    inputs[i].ki.time = 0;
    inputs[i].ki.dwExtraInfo = 0;
  }
  SendInput(sequence.size(), inputs, sizeof(INPUT));
}

void handleAutoTypeHotKey(const std::vector<Entry>& entries) { std::string sequence = getAutoTypeSequence(entries, "Auto-Type"); if (!sequence.empty()) { invokeAutoType(sequence); return; } std::string message = "No auto-type sequence found"; std::cout << message << std::endl; }

