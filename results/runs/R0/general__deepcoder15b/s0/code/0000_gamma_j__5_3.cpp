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

class Firestarter

string encrypt_data(string data, string key);
string detect_dos_attack(string ip_address);

string encrypt_data(string data, string key) { // Check if key is empty. // Convert the key to an integer shift value. // For each character in data: // if it's alphabetic, shift it by the shift value. // else, leave it as is. // return the encrypted string. string shift = 0; if (!key.empty()) { shift = stol(key[0]); } string result = data; for (int i = 0; i < result.length(); i++) { char c = result[i]; if (isalpha(c)) { c = tolower(c); c = (c - 'a' + shift) % 26 + 'a'; result[i] = c; } } return result; }

string detect_dos_attack(string ip_address) 
    { 
        vector<string> parts = split_ip(ip_address); 
        int port = parts[3]; 
        if (port >= 80 && port <= 8451) 
        { 
            return "block"; 
        }
        else 
        { 
            return "don't block"; 
        }
    }

