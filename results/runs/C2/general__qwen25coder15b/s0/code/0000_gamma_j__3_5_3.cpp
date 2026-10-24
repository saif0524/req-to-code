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
std::vector<std::string> searchProducts(const std::string& searchTerm);
void handleSearchResults(const std::vector<std::string>& results);
void displaySearchForm();

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

std::vector<std::string> searchProducts(const std::string& searchTerm) {
  std::vector<std::string> results = searchProducts(searchTerm);
  handleSearchResults(results);
  return results;
}

void handleSearchResults(const std::vector<std::string>& results) {
  for (const auto& product : results) {
    std::cout << product << std::endl;
  }
}

void displaySearchForm() {
  using namespace std;
  std::string html = R"(\n<form>\n<input type="text" name="search" placeholder="Search...">\n<button type="submit">Search</button>
    </form>
  )";\n}

