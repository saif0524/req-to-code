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

string{
{\nvector<curriculum> data;\n}
string{vector<curriculum> data}

string (const string & campus, const string & subject, const int year);
string (const string & subject, const int year);
vector<curriculum> data;
vector<curriculum> data;
string (const string & subject, const int year);

string (const string & campus, const string & subject, const int year) { return data(subject, year); }

vector<curriculum> data(const string & subject, const int year, const vector<string> & other_campuses) 
    { 
        vector<curriculum> default_data; 
        for (const string & other_campus : other_campuses) \n            {
default_data.insert(get_uo_curriculum(other_campus, subject, year), default_data.end());
}
return default_data;
}

vector<curriculum> data(const string & subject, const int year) {
vector<curriculum> combined;
for (const string & other_campus : other_campuses) {
combined.insert(combined.end(), get_uo_curriculum(other_campus, subject, year));
}
return combined;
}

vector<curriculum> data(const string & subject, const int year, const vector<string> & other_campuses) { 
  vector<curriculum> default_data; 
  for (const string & other_campus : other_campuses) \n    {default_data.insert(get_uo_curriculum(other_campus, subject, year), default_data.end());}
return default_data; }

string (const string & subject, const int year) { return data(subject, year); }

