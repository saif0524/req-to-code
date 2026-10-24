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

using zip_t = zip_t;
using zip_file_t = zip_file_t;
using zip_int64_t = zip_int64_t;
using zip_fopen = zip_fopen;
using zip_fread = zip_fread;
using zip_fclose = zip_fclose;
using zip_close = zip_close;
using std::filesystem::create_directories;
using std::ofstream;
using std::ios::binary;
using namespace std; using namespace std::filesystem; using namespace std::filesystem::copy_options;

void extract_zip(const std::string& zip_path, const std::string& dest_dir);
void copy_to_usb(const std::string& zip_path, const std::string& usb_path);
void uninstall(const std::string& zip_path);
void verify_uninstallation(const std::string& zip_path);

void extract_zip(const std::string& zip_path, const std::string& dest_dir) {
  zip_t* zip = zip_open(zip_path.c_str(), ZIP_RDONLY, NULL);
  if (zip == NULL) {
    throw std::runtime_error("Failed to open ZIP file");
  }
  zip_file_t* file = zip_fopen(zip, "", ZIP_FL_ENC_DEFL, 0);
  if (file == NULL) {
    zip_close(zip);
    throw std::runtime_error("Failed to open ZIP file");
  }
  zip_int64_t size = zip_fsize(file);
  char* buffer = new char[size + 1];
  zip_fread(file, buffer, size);
  buffer[size] = 0;
  zip_fclose(file);
  zip_close(zip);
  std::filesystem::create_directories(dest_dir);
  std::ofstream outFile(dest_dir + zip_path.substr(zip_path.find_last_of('/') + 1), std::ios::binary);
  outFile.write(buffer, size);
  outFile.close();
  delete[] buffer;
}

void copy_to_usb(const std::string& zip_path, const std::string& usb_path) {
  try {
    extract_zip(zip_path, "temp_extracted");
    using namespace std;
    using namespace std::filesystem;
    using namespace std::filesystem::copy_options;
    create_directories(usb_path);
    copy("temp_extracted", usb_path, copy_options::recursive);
  } catch (const std::exception& e) {
    throw std::runtime_error("Failed to copy ZIP file to USB stick: " + e.what());
  }
}

void uninstall(const std::string& zip_path) {
  try {
    extract_zip(zip_path, "temp_extracted");
    std::filesystem::create_directories(usb_path);
    std::filesystem::copy("temp_extracted", usb_path, std::filesystem::copy_options::recursive);
    std::filesystem::remove_all("temp_extracted");
  } catch (const std::exception& e) {
    throw std::runtime_error("Failed to copy ZIP file to USB stick: " + e.what());
  }
}

void verify_uninstallation(const std::string& zip_path) {
  try {
    std::filesystem::remove_all(zip_path);
  } catch (const std::filesystem::filesystem_error& e) {
    throw std::runtime_error("Failed to remove ZIP file: " + e.what());
  }
}

