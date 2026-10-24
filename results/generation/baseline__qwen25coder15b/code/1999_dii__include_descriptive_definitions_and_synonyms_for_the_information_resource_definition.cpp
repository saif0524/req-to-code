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

void registerKeyword(const std::string& keyword);
void registerThesaurus(const std::string& thesaurus);
void registerOntology(const std::string& ontology);
std::vector<std::string> substringSearch(const std::string& query, const std::vector<std::string>& fields);

void registerKeyword(const std::string& keyword) {
  keywords.push_back(keyword);
}

void registerThesaurus(const std::string& thesaurus) {
  thesauri.push_back(thesaurus);
}

void registerOntology(const std::string& ontology) {
  ontologies.push_back(ontology);
}

std::vector<std::string> substringSearch(const std::string& query, const std::vector<std::string>& fields) {
  std::vector<std::string> result;
  for (const auto& field : fields) {
    if (field.find(query) != std::string::npos) {
      result.push_back(field);
    }
  }
  return result;
}

