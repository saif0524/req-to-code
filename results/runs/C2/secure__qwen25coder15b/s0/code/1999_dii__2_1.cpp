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

struct Database; using DatabasePtr = std::shared_ptr<Database>; DatabasePtr db;

void connect_to_database(const std::string& host, const std::string& port, const std::string& user, const std::string& password);
std::vector<std::string> execute_query(const std::string& query);
void close_connection();

void connect_to_database(const std::string& host, const std::string& port, const std::string& user, const std::string& password) {
  Database db(host, port, user, password);
  try {
    std::vector<std::string> results = db.execute_query("SELECT * FROM your_table");
    // Use the results as needed
  } catch (const std::exception& e) {
    std::cerr << "Error connecting to database: " << e.what() << std::endl;
  }
}

void execute_query(const std::string& query, Database& db) {
  db.execute_query(query);
  db.close_connection();
}

void close_connection(Database& db) { db.close_connection(); }

