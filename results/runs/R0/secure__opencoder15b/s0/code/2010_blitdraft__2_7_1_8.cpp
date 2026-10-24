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

std::vector<std::string> get_glossary_terms();
std::string get_online_help_content(std::string term);
void update_glossary_terms(std::vector<std::string> new_terms);
void update_online_help_content(std::string term, std::string new_content);
std::string get_glossary_terms_declarations();

std::vector<std::string> get_glossary_terms() {
  return get_glossary_terms_declarations();
}

std::string get_online_help_content(std::string term) {
   // Retrieve the content of the online help for the given term
   // Use only the shared declarations, the planned functions and local variables
   // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only
}

void update_glossary_terms(std::vector<std::string> new_terms) {
    std::lock_guard<std::mutex> lock(mutex);
    glossary_terms = new_terms;
}

std::string get_online_help_content(std::string term) {
    // Retrieve the content of the online help for the given term
    // Use only the shared declarations, the planned functions and local variables
    // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only
}

class Glossary {
public:
    std::vector<std::string> get_glossary_terms();
    std::string get_online_help_content(std::string term);
    void update_glossary_terms(std::vector<std::string> new_terms);
    std::string get_online_help_content(std::string term);
    std::string get_glossary_terms_declarations();
};

