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

void load_glossary(const std::string& company_name, const std::string& system_name);
void display_glossary(const std::vector<std::pair<std::string, std::string>>& glossary);
void update_glossary(const std::string& term, const std::string& definition);
void delete_glossary(const std::string& term);

void load_glossary(const std::string& company_name, const std::string& system_name) {
  std::string unique_id = company_name + '_' + system_name;
  std::string glossary_data = fetch_glossary_data(unique_id);
  if (glossary_data.empty()) {
    return;
  }
  std::vector<std::pair<std::string, std::string>> glossary;
  parse_glossary_data(glossary_data, glossary);
  display_glossary(glossary);
}

void display_glossary(const std::vector<std::pair<std::string, std::string>>& glossary) {
  for (const auto& pair : glossary) {
    std::cout << pair.first << ': ' << pair.second << std::endl;
  }
}

void update_glossary(const std::string& term, const std::string& definition) {
  std::string unique_id = company_name + '_' + system_name;
  std::string glossary_data = fetch_glossary_data(unique_id);
  if (glossary_data.empty()) {
    return;
  }
  std::vector<std::pair<std::string, std::string>> glossary;
  parse_glossary_data(glossary_data, glossary);
  bool found = false;
  for (auto& pair : glossary) {
    if (pair.first == term) {
      pair.second = definition;
      found = true;
      break;
    }
  }
  if (!found) {
    glossary.push_back({term, definition});
  }
  std::string updated_glossary_data = serialize_glossary_data(glossary);
  save_glossary_data(unique_id, updated_glossary_data);
  display_glossary(glossary);
}

void delete_glossary(const std::string& term) {
  std::string unique_id = company_name + '_' + system_name;
  std::string glossary_data = fetch_glossary_data(unique_id);
  if (glossary_data.empty()) {
    return;
  }
  std::vector<std::pair<std::string, std::string>> glossary;
  parse_glossary_data(glossary_data, glossary);
  bool found = false;
  for (auto& pair : glossary) {
    if (pair.first == term) {
      glossary.erase(glossary.begin() + (std::find(glossary.begin(), glossary.end(), pair) - glossary.begin()));
      found = true;
      break;
    }
  }
  if (!found) {
    glossary.push_back({term, definition});
  }
  std::string updated_glossary_data = serialize_glossary_data(glossary);
  save_glossary_data(unique_id, updated_glossary_data);
  display_glossary(glossary);
}

