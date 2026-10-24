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

bool is_sequence_valid(string sequence);
int get_first_auto_type(string sequence);

bool is_sequence_valid(string sequence) 
 { 
   return sequence.size() <= 59; 
 }

int get_first_auto_type(string sequence) {
  int n = sequence.size();
  for (int i = 0; i < n; ++i) {
    string word = split_sequence(i);
    if (is_all_alpha(word)) {
      return i;
    }
  }
  return -1;
}

