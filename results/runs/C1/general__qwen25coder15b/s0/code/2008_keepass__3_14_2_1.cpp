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
void selectLanguage();
void informUser();
void confirmRestart();
void saveChanges();

void openKeePass() {
  selectLanguage();
  informUser();
  confirmRestart();
  saveChanges();
}

void selectLanguage() {
  selectLanguage();
  informUser();
  confirmRestart();
  saveChanges();
}

void informUser() {
  std::cout << "Installation complete. Restart KeePass to see the changes." << std::endl;
}

void confirmRestart() {
  std::cout << "Do you want to restart KeePass now? (yes/no)" << std::endl;
  std::string input;
  while (true) {
    std::cin >> input;
    if (input == "yes") {
      return;
    }
    std::cout << "Please enter 'yes' to restart KeePass now. (yes/no)" << std::endl;
  }
}

void saveChanges() {
  confirmRestart();
  // Code to save changes to the database
  // Code to restart KeePass
}

