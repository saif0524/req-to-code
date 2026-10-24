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

void saveGame(const std::string& filename, const std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& blockPositions, const std::vector<std::pair<int, int>>& previousBlockPositions, int previousMovements, int timePassed);
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& readBlockPositions(const std::string& filename);
std::vector<std::pair<int, int>>& readPreviousBlockPositions(const std::string& filename);
int readPreviousMovements(const std::string& filename);
int readTimePassed(const std::string& filename);

void saveGame(const std::string& filename, const std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& blockPositions, const std::vector<std::pair<int, int>>& previousBlockPositions, int previousMovements, int timePassed) {
  if (filename.empty() || blockPositions.empty()) {
    return;
  }

  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return;
  }

  file << blockPositions << "\n" << previousBlockPositions << "\n" << previousMovements << "\n" << timePassed << std::endl;

  file.close();
}

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> readBlockPositions(const std::string& filename) {
  if (filename.empty()) {
    return std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>();
  }

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file "

std::vector<std::pair<int, int>>& readPreviousBlockPositions(const std::string& filename) {
  if (filename.empty() || blockPositions.empty()) {
    return blockPositions;
  }

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return blockPositions;
  }

  std::vector<std::pair<int, int>> previousBlockPositions;
  file >> previousBlockPositions;

  file.close();

  return previousBlockPositions;
}

int readPreviousMovements(const std::string& filename) { if (filename.empty() || blockPositions.empty()) { return 0; } std::ifstream file(filename); if (!file.is_open()) { std::cerr << "Error: Could not open file " << filename << std::endl; return 0; } int previousMovements; file >> previousMovements; file.close(); return previousMovements; }

int readTimePassed(const std::string& filename) { if (filename.empty() || blockPositions.empty()) { return 0; } std::ifstream file(filename); if (!file.is_open()) { std::cerr << "Error: Could not open file " << filename << std::endl; return 0; } int timePassed; file >> timePassed; file.close(); return timePassed; }

