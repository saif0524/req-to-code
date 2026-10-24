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

void openKeePass();
void confirmRestart();
void saveChanges();
void unlockDatabase();

void openKeePass() { KeePass::openKeePass(); }

void confirmRestart() { std::string message = "Do you want to restart KeePass now?"; std::cout << message << std::endl; std::string input; std::cin >> input; if (input == "yes") { return true; } else { return false; } }

void saveChanges() { bool success = KeePass::saveChanges(); if (success) { bool restart = confirmRestart(); if (restart) { KeePass::openKeePass(); } } }

void unlockDatabase() { std::string password; std::cout << "Enter Master Password: "; std::cin >> password; if (KeePass::unlockDatabase(password)) { std::cout << "Database unlocked successfully." << std::endl; } else { std::cout << "Invalid Master Password. Please try again." << std::endl; } }

