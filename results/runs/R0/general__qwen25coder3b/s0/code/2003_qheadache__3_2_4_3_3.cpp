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

std::string openSaveFileDialog();
void saveGameData(const std::string& filename, const std::vector<BlockPosition>& blockPositions, const std::vector<BlockPosition>& previousBlockPositions, int previousMovements, int timePassed);
std::vector<BlockPosition> getBlockPositions();
std::vector<BlockPosition> getPreviousBlockPositions();
int getPreviousMovements();

std::string openSaveFileDialog() {
  std::string filePath;
  // Use standard library functions to create a dialog box
  // Example: using Qt's QFileDialog
  // filePath = QFileDialog::getSaveFileName();
  // Return the selected file path
  return filePath;
}

void saveGameData(const std::string& filename, const std::vector<BlockPosition>& blockPositions, const std::vector<BlockPosition>& previousBlockPositions, int previousMovements, int timePassed) {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << "Block Positions: " << blockPositions.size() << "\n";
    for (const auto& pos : blockPositions) {
      file << pos.x << "," << pos.y << "\n";
    }
    file << "Previous Block Positions: " << previousBlockPositions.size() << "\n";
    for (const auto& pos : previousBlockPositions) {
      file << pos.x << "," << pos.y << "\n";
    }
    file << "Previous Movements: " << previousMovements << "\n";
    file << "Time Passed: " << timePassed << "\n";
    file.close();
  } else {
    std::cerr << "Unable to open file: "

std::vector<BlockPosition> getBlockPositions() { return getBlockPositions(); }

std::vector<BlockPosition> getPreviousBlockPositions() { return previousBlockPositions; }

int getPreviousMovements() { return previousMovements; }

