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

using json = nlohmann::json;

void save_game(const std::vector<std::vector<int>>& positions, const std::vector<std::vector<int>>& previous_positions, int previous_movements, double time_passed);
void load_game(std::vector<std::vector<int>>& positions, std::vector<std::vector<int>>& previous_positions, int& previous_movements, double& time_passed);

void save_game(const std::vector<std::vector<int>>& positions, const std::vector<std::vector<int>>& previous_positions, int previous_movements, double time_passed) {
  json j;
  j[
    "positions"] = positions;
    j[
      "previous_positions"] = previous_positions;
    j[
      "previous_movements"] = previous_movements;
    j[
      "time_passed"] = time_passed;
  ];
  std::ofstream file("game_state.json");
  file << j;
}

void load_game(std::vector<std::vector<int>>& positions, std::vector<std::vector<int>>& previous_positions, int& previous_movements, double& time_passed) {
  json j;
  std::ifstream file("game_state.json");
  file >> j;

  positions = j[

