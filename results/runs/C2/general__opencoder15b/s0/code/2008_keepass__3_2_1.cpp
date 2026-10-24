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

OpenDatabase(const std::string& path, const std::string& master_password);
GetMasterPassword(Database& db, const std::string& new_password);
UnlockDatabase(Database& db, const std::string& password);
CloseDatabase(Database& db);
GetDatabasePath(Database& db);

void GetMasterPassword(Database& db, const std::string& new_password) {
     std::string current_password = db.GetMasterPassword();
     // Ask the user for the current master password
     std::string user_password = GetUserPassword();
     // Check if the user provided the correct password
     if (user_password == current_password) {
         // If correct, set the new master password
         db.SetMasterPassword(new_password);
     } else {
         // If incorrect, inform the user and return
         std::cout << "Incorrect password.";
         return;
     }
}

void UnlockDatabase(Database& db, const std::string& password) {
     std::string current_password = db.GetMasterPassword();
     if (current_password == password) {
         db.Unlock();
     } else {
         std::cout << "Incorrect password.";
         return;
     }
}

void CloseDatabase(Database& db) {
     db.Close();
}

std::string GetDatabasePath(Database& db) {
     return db.GetPath();
}

void UnlockDatabase(Database& db, const std::string& password) {
     std::string current_password = db.GetMasterPassword();
     if (current_password == password) {
         db.Unlock();
     } else {
         std::cout << "Incorrect password.";
         return;
     }
}

void CloseDatabase(Database& db) {
     db.Close();
}

std::string GetDatabasePath(Database& db) {
     return db.GetPath();
}

