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

bool validateAutoTypeSequence(const std::string& sequence);
std::string formatAutoTypeSequence(const std::string& sequence);
std::string mergeAutoTypeSequences(const std::string& sequence1, const std::string& sequence2);

bool validateAutoTypeSequence(const std::string& sequence) {
  if (sequence.empty()) return true;
  if (sequence.length() > 59) return false;
  return true;
}

std::string formatAutoTypeSequence(const std::string& sequence) {
  if (sequence.empty()) return sequence;
  if (sequence.length() > 59) return sequence.substr(0, 59);
  return sequence;
}

std::string mergeAutoTypeSequences(const std::string& sequence1, const std::string& sequence2) {
  if (!validateAutoTypeSequence(sequence1)) return sequence2;
  if (!validateAutoTypeSequence(sequence2)) return sequence1;
  return sequence1;
}

