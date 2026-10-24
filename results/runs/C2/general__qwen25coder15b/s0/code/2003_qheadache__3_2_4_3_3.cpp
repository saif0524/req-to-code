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

void save_game(const std::vector<std::vector<int>>& positions, const std::vector<std::vector<int>>& previous_positions, int previous_movements, double time_passed);
void load_game(std::vector<std::vector<int>>& positions, std::vector<std::vector<int>>& previous_positions, int& previous_movements, double& time_passed);

void save_game(const std::vector<std::vector<int>>& positions, const std::vector<std::vector<int>>& previous_positions, int previous_movements, double time_passed) {
  std::ofstream file("game_state.txt");
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  file << positions << previous_positions << previous_movements << time_passed;
  file.close();
}

void load_game(std::vector<std::vector<int>>& positions, std::vector<std::vector<int>>& previous_positions, int& previous_movements, double& time_passed) {
  std::ifstream file("game_state.txt");
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  file >> positions >> previous_positions >> previous_movements >> time_passed;
  file.close();
}

