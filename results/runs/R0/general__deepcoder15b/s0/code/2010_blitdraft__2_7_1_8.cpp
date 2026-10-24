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

string search_term, vector<string> search_glossary_term(string search_term) {
  vector<string> matching_terms;
  for (string term : all_terms) {
    if (search_term.find(term) != string::npos) {
      matching_terms.push_back(term);
    }
  }
  return { "reasoning": [
    "The function searches for terms that contain the search term as a substring. This ensures that all relevant terms are identified regardless of their exact spelling. \n"The function iterates through each term in the existing glossary. For each term, it checks if the search term is a substring of the term's name. If it is, the term is added to the matching terms vector. This approach ensures that all terms containing the search term are found. 
    "The function constructs a JSON response with the reasoning steps and the found terms. This provides clear and structured output for the user. \n"The function returns a JSON object with 'reasoning' containing steps 3 to 6 and 'terms' containing the matching terms. This meets the requirements specified in the problem. 
    ],
    "terms": matching_terms
  };
  return code;
  }

return std::json::load<std::json::json>({ { "reasoning": [
    "Step 3: List all terms in the glossary.\n"Step 4: Ensure each term is listed only once.
    "Step 5: Handle case sensitivity by ignoring different capitalizations.\n"Step 6: Return the complete list of terms.
    ]}
    "terms": all_terms }
  );
  

