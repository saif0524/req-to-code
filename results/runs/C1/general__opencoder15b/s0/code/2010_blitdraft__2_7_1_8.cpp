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

std::string getGlossary();
void updateGlossary(std::string newGlossaryContent);
std::vector<std::string> getGlossaryTerms();
std::vector<std::string> getGlossaryDefinitions();
std::pair<std::string, std::string> getGlossaryTermDefinition(std::string term);

std::string BlitDraft::getGlossary() {
   return "Glossary content here";
}

std::vector<std::string> BlitDraft::getGlossaryTerms() {
    std::string glossaryContent = getGlossary();
    std::vector<std::string> terms;
    std::string term;
    std::istringstream iss(glossaryContent);
    std::string line;
    while (std::getline(iss, line)) {
       term = line;
       term = term.substr(0, term.find_last_not_of(' '));
       term = term.substr(term.find_first_not_of(' '));
       terms.push_back(term);
    }
    return terms;
}

std::vector<std::string> BlitDraft::getGlossaryDefinitions() {
     std::string glossaryContent = getGlossary();
     std::vector<std::string> definitions;
     std::string definition;
     std::istringstream iss(glossaryContent);
     std::string line;
     while (std::getline(iss, line)) {
         definition = line;
         definition = definition.substr(definition.find_last_of(':') + 2);
         definition = definition.substr(definition.find_first_not_of(' '));
         definitions.push_back(definition);
     }
     return definitions;
}

std::pair<std::string, std::string> BlitDraft::getGlossaryTermDefinition(std::string term) {
     std::string glossaryContent = getGlossary();
     std::pair<std::string, std::string> definition;
     std::string line;
     std::istringstream iss(glossaryContent);
     while (std::getline(iss, line)) {
         std::string termInLine = line;
         termInLine = termInLine.substr(0, termInLine.find_last_not_of(' '));
         termInLine = termInLine.substr(termInLine.find_first_not_of(' '));
         if (termInLine == term) {
             std::string definitionInLine = line;
             definitionInLine = definitionInLine.substr(definitionInLine.find_last_of(':') + 2);
             definitionInLine = definitionInLine.substr(definitionInLine.find_first_not_of(' '));
             definition.first = definitionInLine;
             definition.second = term;
             break;
         }
     }
     return definition;
}

