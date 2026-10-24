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

void change_language(std::string language);
void install_language(std::string language);

void change_language(std::string language) {
    // Change the language of the database
    set_language(language);
    // Update the UI
    update_ui();
    // Restart KeePass
    restart();
}

void install_language(std::string language) {
     // Change the language of the database
     change_language(language);
     // Update the UI
     update_ui();
     // Restart KeePass
     restart();
}

