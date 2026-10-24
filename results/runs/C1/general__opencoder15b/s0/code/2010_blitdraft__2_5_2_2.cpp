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
void initialize_log_file();

void write_to_log(const std::string& message) {
   std::ofstream log_file("log.txt", std::ios::app);
   if (log_file.is_open()) {
     log_file << message << std::endl;
   } else {
     std::cout << "Error: Could not open log file." << std::endl;
   }
}

std::string read_from_log() {
    std::ifstream log_file("log.txt");
    std::string message;
    if (log_file.is_open()) {
     std::getline(log_file, message);
    } else {
     std::cout << "Error: Could not open log file." << std::endl;
    }
    return message;
}

void clear_log() {
     std::ofstream log_file("log.txt");
     log_file.seekp(0);
     log_file << "" << std::endl;
}

bool check_log_file() {
     std::ifstream log_file("log.txt");
     return log_file.good();
}

void initialize_log_file() {
    std::ofstream log_file("log.txt");
    if (log_file.is_open()) {
     log_file << "Log file initialized.\n";
    } else {
     std::cout << "Error: Could not open log file." << std::endl;
    }
}

