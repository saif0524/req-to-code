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

auto searchTerms(const string& term);
auto displayGlossary(const vector<GlossaryTerm>& glossary);
auto handleUserInput(const string& term);
auto handleError(const string& term);

vector<string> searchTerms(const string& term) {
  vector<string> searchResults;
  for (const auto& termInGlossary : glossary) {
    if (termInGlossary.name == term) {
      searchResults.push_back(termInGlossary);
    }
  }
  return searchResults;
}

vector<string> displayGlossary(const vector<GlossaryTerm>& glossary) {
  vector<string> displayTerms;
  for (const auto& term : glossary) {
    displayTerms.push_back(getTermName(term));
  }
  return { "reasoning": "Display the current terms in the glossary", "display": displayTerms };
}

vector<string> handleUserInput(const string& term) { 
  vector<string> terms = searchTerms(term);
  if (terms.size() > 0) {
    vector<string> new_terms = terms;
    new_terms.erase(new_terms.begin(), new_terms.end());
    new_terms.push_back(new_term);
    updateGlossary(new_terms);
    return "added";
  } else {
    vector<string> new_terms = terms + vector<string>{term};
    updateGlossary(new_terms);
    return "added";
  }
  }
  

auto handleError(const string& term) {
  vector<string> terms = searchTerms(term);
  if (terms.empty()) {
    handleError(term);
  } else {
    updateGlossary(terms);
    return "added";
  }
}

