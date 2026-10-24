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

void displayCategories(const std::vector<std::string>& categories);
void displayProducts(const std::vector<std::string>& products);
std::vector<std::string> searchProducts(const std::string& query);
bool checkBrowserCompatibility(const std::string& browser);
void displaySearchResults(const std::vector<std::string>& results);

void displayCategories(const std::vector<std::string>& categories) {
  for (const auto& category : categories) {
    std::cout << category << std::endl;
  }
}

void displayProducts(const std::vector<std::string>& products) {
  for (const auto& product : products) {
    std::cout << product << std::endl;
  }
}

std::vector<std::string> searchProducts(const std::string& query) {
  std::vector<std::string> results;
  for (const auto& product : products) {
    if (product.find(query) != std::string::npos) {
      results.push_back(product);
    }
  }
  return results;
}

bool checkBrowserCompatibility(const std::string& browser) {
  std::vector<std::string> compatibleBrowsers = {"Internet Explorer", "Mozilla Navigator", "Mozilla Firefox", "Opera", "Safari"};
  for (const auto& compatibleBrowser : compatibleBrowsers) {
    if (compatibleBrowser == browser) {
      return true;
    }
  }
  return false;
}

void displaySearchResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

