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

void write_to_log(const std::string& message);
std::string read_from_log();
void clear_log();
bool check_log_file();
void initialize_log();

void write_to_log(const std::string& message) {
  // Write a message to the log file.
  std::ofstream log_file("log.txt", std::ios::app);
  log_file << message << std::endl;
}

std::string read_from_log() {
   std::ifstream log_file("log.txt");
   std::string message;
   std::getline(log_file, message);
   log_file.close();
   return message;
}

void clear_log() {
    std::ofstream log_file("log.txt");
    log_file << "";
}

bool check_log_file() {
    if (std::ifstream("log.txt")) {
        return true;
    } else {
        return false;
    }
}

void initialize_log() {
    if (!check_log_file()) {
        std::ofstream log_file("log.txt");
        log_file << "";
    }
}

