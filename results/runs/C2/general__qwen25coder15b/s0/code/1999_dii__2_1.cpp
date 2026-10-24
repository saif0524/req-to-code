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

void connect_to_database(const std::string& host, const std::string& port, const std::string& user, const std::string& password);

void connect_to_database(const std::string& host, const std::string& port, const std::string& user, const std::string& password);
std::vector<std::string> execute_query(const std::string& query);
void insert_data(const std::string& table, const std::map<std::string, std::string>& data);
void update_data(const std::string& table, const std::map<std::string, std::string>& data, const std::string& condition);
void delete_data(const std::string& table, const std::string& condition);

std::vector<std::string> execute_query(const std::string& query) {
  connect_to_database(host, port, user, password);
  std::string result = execute_query(query);
  std::vector<std::string> rows;
  std::map<std::string, std::string> columns;
  std::istringstream iss(result);
  std::string line;
  while (std::getline(iss, line)) {
    std::istringstream iss2(line);
    std::string column;
    std::string value;
    while (std::getline(iss2, column, ',')) {
      iss2 >> value;
      columns[column] = value;
    }
    rows.push_back(columns);
  }
  return rows;
}

void insert_data(const std::string& host, const std::string& port, const std::string& user, const std::string& password, const std::string& table, const std::map<std::string, std::string>& data) {
  connect_to_database(host, port, user, password);
  std::string query = "INSERT INTO " + table + " (";
  for (const auto& pair : data) {
    query += pair.first + ", ";
  }
  query += ") VALUES (";
  for (const auto& pair : data) {
    query += "" + pair.second + ", ";
  }
  query += ");";
  execute_query(query);
}

void update_data(const std::string& host, const std::string& port, const std::string& user, const std::string& password, const std::string& table, const std::map<std::string, std::string>& data, const std::string& condition) {
  connect_to_database(host, port, user, password);
  std::string query = "UPDATE " + table + " SET ";
  for (const auto& pair : data) {
    query += pair.first + " = " + pair.second + ", ";
  }
  query += " WHERE " + condition + ";\nexecute_query(query);\n}

void delete_data(const std::string& host, const std::string& port, const std::string& user, const std::string& password, const std::string& table, const std::string& condition) {
  connect_to_database(host, port, user, password);
  std::string query = "DELETE FROM " + table + " WHERE " + condition + ";";
  execute_query(query);
}

