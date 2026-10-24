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
  // Implement the search logic here
  // For example, you can use a database or an API to search for products
  // Return the results as a vector of strings
}

void handleSearchResults(const std::vector<std::string>& results) {
  for (const auto& product : results) {
    std::cout << product << std::endl;
  }
}

void displaySearchForm() {
  std::string html = R"(\n<form action="/search" method="GET">\n<input type="text" name="search" placeholder="Search products...">\n<button type="submit">Search</button>
    </form>
  )";\nstd::cout << html << std::endl;\n}

