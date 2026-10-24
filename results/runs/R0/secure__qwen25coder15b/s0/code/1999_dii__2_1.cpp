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

std::vector<std::string> execute_query(const std::string& query);
void close_connection();

void execute_query(const std::string& query) {
  Database db;
  db.connect_to_database(host, port, user, password);
  std::vector<std::string> results = db.execute_query(query);
  db.close_connection();
  return results;
}

void close_connection() {
  Database db;
  try {
    db.close_connection();
  } catch (const std::exception& e) {
    std::cerr << "Error closing database connection: " << e.what() << std::endl;
  }
}

