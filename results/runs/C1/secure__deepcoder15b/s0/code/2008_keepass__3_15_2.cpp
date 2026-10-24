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
    int len = sequence.size(); 
    return len <= 59; 
} "

int get_first_auto_type(string sequence) [35;32m{ [35;32m    int n = sequence.size(); [35;32m    for (int i = 0; i < n; ++i) [35;32m    { [35;32m        string word = split_sequence(i); [35;32m    } [35;32m    if (is_all_alpha(word)) [35;32m    { [35;32m        return i; [35;32m    } 00m    return -1; 00m } 00m 00m // Split sequence into words 00m 00m 00m 00m // Check each word for being an auto-type 00m } 00m 00m // Return the index of the first auto-type word 00m }

