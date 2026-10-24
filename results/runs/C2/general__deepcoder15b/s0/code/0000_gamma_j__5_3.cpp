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

class Firestarter { public: explicit Firestarter(); }

bool is_card_valid(int card_number);
string encrypt_data(string data, string key);
string detect_dos_attack(string ip_address);
int count_consecutive_fail(int login_count);

bool is_card_valid(int card_number) {
  string s = to_string(card_number);
  reverse(s.begin(), s.end());
  int sum = 0;
  for (int i = 0; i < s.length(); i++) {
    int digit = 0;
    if (i % 2 == 0) {
      digit = s[i] - '0';
    } else {
      digit = s[i] - '0';
      if (digit > 9) {
        digit = (digit / 2) + (digit % 10);
      }
    }
    sum += digit;
  }
  return (sum % 10) == 0;
}

string encrypt_data(string data, string key) { 
    int shift = 0; 
    if (!key.empty() && key[0] != ' ') { 
        shift = stod(key[0]); 
    } 
    if (shift <= 0) { 
        return data; 
    } 
    string result; 
    for (char c : data) { 
        int c_val = c - '0'; 
        int shifted = (c_val + shift) % 26; 
        if (shifted < 0) { 
            shifted += 26; 
        } 
        result += (char)(shifted + '0'); 
    } 
    return result; 
 }

string detect_dos_attack(string ip_address) 
    { 
        int port = ip_address[0]; 
        if (port >= 80 && port <= 8451) 
        { 
            return 

int count_consecutive_fail(int login_count) {
  int count = 0;
  bool is_first_failure = true;
  for (int i = 0; i < login_count; i++) {
    if (is_failure(i)) {
      count ++;
    } else {
      count = 0;
    }
  }
  return count;
  }
  

