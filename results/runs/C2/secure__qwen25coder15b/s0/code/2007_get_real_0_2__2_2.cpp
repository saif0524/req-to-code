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

std::vector<std::string> get_real_pages();
std::string get_real_page_content(const std::string& page_name);
void get_real_page_prototype(const std::string& page_name);
int get_real_page_priority(const std::string& page_name);
std::vector<std::string> get_real_page_proposals();

std::vector<std::string> get_real_pages() {  std::vector<std::string> pages;  for (const auto& page : get_real_page_prototype()) {    pages.push_back(page);  }  return pages; }

std::string get_real_page_content(const std::string& page_name) {  std::vector<std::string> pages = get_real_page_prototype();  for (const auto& page : pages) {    if (page == page_name) {      return get_real_page_prototype(page_name);    }  }  return "Page not found";}

void get_real_page_prototype(const std::string& page_name) {  std::vector<std::string> pages = get_real_page_prototype();  for (const auto& page : pages) {    if (page == page_name) {      return get_real_page_prototype(page_name);    }  }  return "Page not found";}

int get_real_page_priority(const std::string& page_name) {  std::vector<std::string> pages = get_real_page_prototype();  for (const auto& page : pages) {    if (page == page_name) {      return get_real_page_prototype(page_name);    }  }  return -1;}

std::vector<std::string> get_real_page_prototypes(const std::string& page_name) {  std::vector<std::string> pages = get_real_page_prototype();  for (const auto& page : pages) {    if (page == page_name) {      return get_real_page_prototype(page_name);    }  }  return std::vector<std::string>();}

