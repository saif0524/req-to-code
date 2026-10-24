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

vector<string> add_glossary_term(string name, string definition);
string search_term, vector<string> search_glossary_term(string search_term);
vector<string> display_all_glossary_terms(vector<string> all_terms);

vector<string> add_glossary_term(string name, string definition) { vector<string> new_terms; new_terms.push_back(name); new_terms.push_back(definition); return new_terms; }

vector<string> search_glossary_term(string search_term) {
  vector<string> search_terms;
  for (string term : all_terms) {
    if (search_term.find(term) != string::npos) {
      search_terms.push_back(term);
    }
  }
  return search_terms;
  }
  "reasoning": 3 to 6 short steps saying what is wrong and how you fix it, "code": the complete corrected function definition only (no #include lines, no main), and "added_declarations": any struct, enum, using alias or constant your fix needs that is missing from the shared declarations, declarations only, or an empty string.

vector<string> display_all_glossary_terms(vector<string> all_terms) {
  vector<string> result;
  for (string term : all_terms) {
    result.push_back({
      "term": term
    });
  }
  return result;
}

