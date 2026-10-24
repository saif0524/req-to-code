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

std::pair<std::string, std::pair<std::string, std::string>> initialize_keyring(std::string password);
std::string generate_password(int length, int range, bool case_insensitive, bool lowercase);
std::pair<std::string, std::string> create_keyring_from_password(std::string password);
std::pair<std::string, bool> save_keyring(std::string file, bool write_to_file);
std::pair<std::string, std::string> load_keyring(std::string file);

pair<string, pair<string, string>> initialize_keyring(string password) {
  random_device rd;
  mt19937 gen(rd());
  for (int i = 0; i < 8; ++i) {
    random_str += static_cast<char>(gen.random(10));
  }
  return make_pair(password, make_pair(random_str,));
  }
```json `

string generate_password(int length, int range, bool case_insensitive, bool lowercase) {
  string password;
  for (int i = 0; i < length; ++i) {
    int num = rand() % range;
    char c = static_cast<char>('a' + num);
    // Determine case based on parameters
    if (lowercase && case_insensitive) {
      c = static_cast<char>('a');
    } else if (!lowercase && !case_insensitive) {
      c = static_cast<char>('A');
    }
    password += c;
  }
  return password;
  }
  

pair<string, string> create_keyring_from_password(string password) {
  size_t half = password.size() / 2;
  string part1 = password.substr(0, half);
  string part2 = password.substr(half);

  string random_str;
  random_device rd;
  mt19937 gen(rd());
  for (int i = 0; i < 8; ++i) {
    random_str += static_cast<char>(randomigit(gen));
  }

  return make_pair(part1, random_str);
  }

pair<string, string> save_keyring(string file, bool write_to_file) {
  // Create the keyring object using the password from generate_password
  pair<string, string> keyring = create_keyring_from_password(generate_password(10, 20, false, false));
  // Extract part1 and the random string
  string part1 = keyring.first;
  string random_str = keyring.second;
  // Write part1 to the file
  if (file != string()) {
    open(file, string::write_mode) {
      write(string(10), '\n');
    }
  }
  // Write random_str to the file
  if (file != string() && write_to_file) {
    open(file, string::write_mode) {
      write(random_str, '\n');
    }
  }
  return keyring;
  }
  

pair<string, string> load_keyring(string file) { pair<string, string>> keyring = create_keyring_from_password(file.substr(0, file.size() / 2)); keyring = make_pair(keyring.first, make_pair(keyring.second, file.substr(file.size() / 2))); return keyring; }

