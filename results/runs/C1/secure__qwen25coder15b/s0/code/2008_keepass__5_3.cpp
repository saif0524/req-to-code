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

void uninstall();
void transfer_to_usb(const std::string& usb_path);
bool license_check();
void download(const std::string& url);

void transfer_to_usb(const std::string& usb_path) {
  using namespace std;
  uninstall();
  download("http://keepass.info/downloads/keepass-2.7.2.zip");\nuninstall();\n}

bool license_check() {
  uninstall();
  download("http://keepass.info/downloads/keepass-2.7.2.zip");\nreturn true;\n}

void download(const std::string& url) {
  uninstall();
  download(url);
  uninstall();
}

