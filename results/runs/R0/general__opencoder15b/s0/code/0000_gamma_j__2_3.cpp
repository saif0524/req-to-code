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

registerAccount(std::string username, std::string password, std::string email);
loginAccount(std::string username, std::string password);
logoutAccount();
updateAccount(std::string username, std::string password, std::string email);
deleteAccount(std::string username);

void registerAccount(std::string username, std::string password, std::string email) {
  // Step 1: Check if the username already exists in the database.
  if (usernameExists(username)) {
    // Step 2: If the username exists, return an error message.
    return false;
  }
  // Step 3: If the username does not exist, insert the new account information into the database.
  insertAccount(username, password, email);
  // Step 4: Return a success message.
  return true;
}

bool loginAccount(std::string username, std::string password) {
  // Step 1: Check if the username and password match the ones in the database.
  if (checkLogin(username, password)) {
    // Step 2: If the username and password match, return a success message.
    return true;
  }
  // Step 3: If the username and password do not match, return an error message.
  return false;
}

void logoutAccount() {
  // Step 1: Set the current account to null.
  setCurrentAccount(nullptr);
  // Step 2: Return a success message.
  return true;
}

bool updateAccount(std::string username, std::string password, std::string email) {
   // Step 1: Check if the username and password match the ones in the database.
   if (checkLogin(username, password)) {
     // Step 2: If the username and password match, return a success message.
     return true;
   }
   // Step 3: If the username and password do not match, return an error message.
   return false;
}

void deleteAccount(std::string username) {
   // Step 1: Check if the username exists in the database.
   if (usernameExists(username)) {
     // Step 2: If the username exists, delete the account from the database.
     deleteAccount(username);
     // Step 3: Return a success message.
     return true;
   }
   // Step 4: If the username does not exist, return an error message.
   return false;
}

