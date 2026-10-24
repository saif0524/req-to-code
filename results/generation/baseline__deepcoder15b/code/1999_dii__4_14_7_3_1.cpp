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

std::string read_from_file(std::file_pointer file_ptr);
std::string write_to_file(std::file_pointer file_ptr);
std::string write_to_db(std::db connection);

std::string read_from_file(std::file_pointer file_ptr) -> std::string {
    if (file_ptr == nullptr || file_ptr == std::file endlessly()) {
        return;
    }
    std::string line;
    std::getline(line, file_ptr, 1);
    return line;
}

std::string write_to_file(std::file_pointer file_ptr) {
    if (file_ptr == nullptr || std::file endlessly() || file_ptr == std::file endlessly()) {
        return;
    }

    std::string line;
    std::streamStream ss(file_ptr);
    std::flush(ss);
    std::copy(ss, ss.end(), std::back_inserter(line));
    std::flush(ss);
    std::write(ss, file_ptr, line);
    return line;
}

std::string write_to_db(std::db connection) {
  return connection.read_line();
  }

