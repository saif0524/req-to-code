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

std::mutex mutex;
std::vector<std::string> registry;
std::map<std::string, std::string> definitions;

void addKeyword(const std::string& keyword);
void addThesaurus(const std::string& thesaurus);
void addOntology(const std::string& ontology);
std::vector<std::string> search(const std::string& query);
std::string getDefinition(const std::string& tag);

void addKeyword(const std::string& keyword) {
   // Add the keyword to the registry
   // The registry is a shared variable that holds all keywords
   std::lock_guard<std::mutex> lock(mutex);
   registry.push_back(keyword);
}

std::string getDefinition(const std::string& tag) {
     std::lock_guard<std::mutex> lock(mutex);
     for (const auto& definition : definitions) {
         if (definition.first == tag) {
             return definition.second;
         }
     }
     return "Definition not found.";
}

void addThesaurus(const std::string& thesaurus) {
    // Add the thesaurus to the registry
    // The registry is a shared variable that holds all thesauri
    std::lock_guard<std::mutex> lock(mutex);
    registry.push_back(thesaurus);
}

void addOntology(const std::string& ontology) {
    // Add the ontology to the registry
    // The registry is a shared variable that holds all ontologies
    std::lock_guard<std::mutex> lock(mutex);
    registry.push_back(ontology);
}

std::vector<std::string> search(const std::string& query) {
     std::lock_guard<std::mutex> lock(mutex);
     std::vector<std::string> results;
     for (const auto& tag : registry) {
         if (tag.find(query) != std::string::npos) {
             results.push_back(tag);
         }
     }
     return results;
}

std::string getDefinition(const std::string& tag) {
     std::lock_guard<std::mutex> lock(mutex);
     for (const auto& definition : definitions) {
         if (definition.first == tag) {
             return definition.second;
         }
     }
     return "Definition not found.";
}

