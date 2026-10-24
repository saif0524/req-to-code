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

void transfer_to_usb(const std::string& usb_path);
bool license_check();
void download(const std::string& url);

void transfer_to_usb(const std::string& usb_path) {
  uninstall();
  download("http://keepass.info/downloads/keepass-2.7.2.zip");\ntransfer_to_usb(usb_path);\nuninstall();\n}

bool license_check() {
  uninstall();
  download("http://keepass.info/downloads/keepass-2.7.2.zip");\nuninstall();\nreturn true;\n}

void download(const std::string& url) {
  uninstall();
  download(url);
  uninstall();
}

