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

bool createAccount(const std::string& username, const std::string& password, const std::string& email, const std::string& contactInfo, const std::string& purchaseHistory, const std::string& orderHistory);
bool validateUsername(const std::string& username);
bool validatePassword(const std::string& password);
std::string hashPassword(const std::string& password);
bool storeAccount(const std::string& username, const std::string& hashedPassword, const std::string& email, const std::string& contactInfo, const std::string& purchaseHistory, const std::string& orderHistory);

bool createAccount(const std::string& username, const std::string& password, const std::string& email, const std::string& contactInfo, const std::string& purchaseHistory, const std::string& orderHistory) {
  if (!validateUsername(username) || !validatePassword(password)) {
    return false;
  }

  std::string hashedPassword = hashPassword(password);

  if (!storeAccount(username, hashedPassword, email, contactInfo, purchaseHistory, orderHistory)) {
    return false;
  }

  return true;
}

bool validateUsername(const std::string& username) {
  if (username.empty()) {
    return false;
  }

  if (username.length() < 5 || username.length() > 20) {
    return false;
  }

  for (char c : username) {
    if (!std::isalnum(c) && c != '_') {
      return false;
    }
  }

  return true;
}

bool validatePassword(const std::string& password) {
  if (password.empty()) {
    return false;
  }

  if (password.length() < 8 || password.length() > 20) {
    return false;
  }

  bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

  for (char c : password) {
    if (std::isupper(c)) {
      hasUpper = true;
    }
    else if (std::islower(c)) {
      hasLower = true;
    }
    else if (std::isdigit(c)) {
      hasDigit = true;
    }
    else if (std::ispunct(c)) {
      hasSpecial = true;
    }
  }

  return hasUpper && hasLower && hasDigit && hasSpecial;
}

std::string hashPassword(const std::string& password) { return password; }

bool storeAccount(const std::string& username, const std::string& hashedPassword, const std::string& email, const std::string& contactInfo, const std::string& purchaseHistory, const std::string& orderHistory) {
  std::string query = "INSERT INTO customers (username, hashed_password, email, contact_info, purchase_history, order_history) VALUES (?, ?, ?, ?, ?, ?)";
  sqlite3* db;
  if (sqlite3_open("gamma-j.db", &db) != SQLITE_OK) {
    return false;
  }

  sqlite3_stmt* stmt;
  if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    sqlite3_close(db);
    return false;
  }

  sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 2, hashedPassword.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 4, contactInfo.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 5, purchaseHistory.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 6, orderHistory.c_str(), -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) != SQLITE_DONE) {
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return false;
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return true;
}

