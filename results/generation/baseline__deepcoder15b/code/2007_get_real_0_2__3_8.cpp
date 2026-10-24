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

string

string (const string & campus, const string & subject, const int year);
string (const string & subject, const int year);
vector<curriculum> data;
vector<curriculum> data;

string get_uo_curriculum(const string & campus, const string & subject, const int year) {
    if (campus == 

string (const string & subject, const int year)  // Get default curriculum data from other campuses.
  // This function will loop through all other campuses, call get_uo_curriculum for each, and combine their data into a single vector of curriculum objects.
  // Then, present this combined data as the default curriculum.
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only.

vector<curriculum> data(const string & subject, const int year) {
  vector<curriculum> combined;
  for (const string & other_campus : other_campuses) {
    combined.insert(combined.end(), get_uo_curriculum(other_campus, subject, year));
  }
  return combined;
  }
  "reasoning": "The function combines data from UO and other campuses by looping through each other campus, calling get_uo_curriculum to retrieve their curriculum data, and accumulating these into a single vector. This allows for a comprehensive view of recommended curricula for high school students.", "code": "vector<curriculum> data(const string & subject, const int year) {\nvector<curriculum> combined;\nfor (const string & other_campus : other_campuses) {\ncombined.insert(combined.end(), get_uo_curriculum(other_campus, subject, year));
    }
    return combined;
  }
  "reasoning": "The function combines data from UO and other campuses by iterating through each other campus, retrieving their curriculum data using get_uo_curriculum, and accumulating these into a single vector to provide a comprehensive curriculum recommendation.", "code": "string default_curriculum(const string & subject, const int year) {\nvector<curriculum> default_data;\nfor (const string & other_campus : other_campuses) {\ndefault_data.insert(default_data.end(), get_uo_curriculum(other_campus, subject, year));
    }
    return default_data;
  }
  "reasoning": "The function retrieves default curriculum data from all other campuses, combining them into a single vector to provide a default curriculum recommendation for high school students.", 

vector<curriculum> data(const string & subject, const int year) {
    vector<curriculum> default_data;
    for (const string & other_campus : other_campuses) {
        default_data.insert(default_data.end(), get_uo_curriculum(other_campus, subject, year));
    }
    return default_data;
  }

