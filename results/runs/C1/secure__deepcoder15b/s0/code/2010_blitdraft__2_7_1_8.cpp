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

auto addTermToGlossary(const string& term);
auto searchTerms(const string& term);
auto displayGlossary(const vector<GlossaryTerm>& glossary);
auto handleUserInput(const string& term);
auto handleError(const string& term);

vector<string> addTermToGlossary(const string& term) {
    vector<GlossaryTerm> currentTerms;
    for (const auto& termInGlossary : glossary) {
      if (termInGlossary.name == term) {
        GlossaryTerm termToAdd( termInGlossary.name, termInGlossary.value );
        currentTerms.push_back( termToAdd );
      }
    }
    if (!currentTerms.empty() && currentTerms.back().name == term) {
      currentTerms.pop_back();
      GlossaryTerm newTerm( term, term );
      currentTerms.push_back( newTerm );
    } else {
      GlossaryTerm newTerm( term, term );
      currentTerms.push_back( newTerm );
    }
    return "added";
  }
  "reasoning": 3

vector<string> handleUserInput(const string& term) {
  vector<string> searchResults = searchTerms(term);
  if (searchResults.empty()) {
    error(

vector<string> displayGlossary(const vector<GlossaryTerm>& glossary) { 
  vector<string> displayTerms; 
  for (const auto& term : glossary) { 
    displayTerms.push_back(getTermName(term)); 
  } 
  return displayTerms; 
}

vector<string> handleUserInput(const string& term) {
  vector<string> terms = searchTerms(term);
  if (terms.size() > 0) {
    size_t pos = terms.find(term);
    if (pos != terms.end()) {
      terms.erase(pos);
      new_terms.push_back(new_term);
      updateGlossary(new_terms);
      return "added";
    } else {
      new_terms.push_back(term);
      updateGlossary(new_terms);
      return "added";
    }
  } else {
    new_terms.push_back(term);
    updateGlossary(new_terms);
    return "added";
  }
  }

vector<string> handleUserInput(const string& term) {
  vector<string> terms = searchTerms(term);
  if (terms.size() > 0 && terms.find(term) != terms.end()) {
    terms.erase(terms.find(term));
    updateGlossary(terms);
    return "added";
  }
  updateGlossary(terms);
  return "added";
}

