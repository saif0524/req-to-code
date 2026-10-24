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

void addCategory(std::string name, std::vector<std::string> subCategories);
void updateCategory(std::string oldName, std::string newName, std::vector<std::string> newSubCategories);
void addProductToCategory(std::string productName, std::string categoryName);
void updateProductDetails(std::string productName, std::string newDetails);
void removeProductFromCategory(std::string productName, std::string categoryName);

class Category {
public:
  std::string name;
  std::vector<std::string> subCategories;
  std::vector<std::string> products;
};

void addCategory(std::string name, std::vector<std::string> subCategories) {
  std::map<std::string, Category> categories;
  if (categories.find(name) != categories.end()) {
    // Handle duplicate category names
    return;
  }
  categories[name] = {name, subCategories, {}};
  // Add products to the category as needed
}

void updateCategory(std::string oldName, std::string newName, std::vector<std::string> newSubCategories) {
  std::map<std::string, Category> categories;
  if (categories.find(oldName) == categories.end()) {
    // Handle category not found
    return;
  }
  categories[newName] = {newName, newSubCategories, categories[oldName].products};
  categories.erase(oldName);
}

void addProductToCategory(std::string productName, std::string categoryName) {
  std::map<std::string, Category> categories;
  if (categories.find(categoryName) == categories.end()) {
    // Handle category not found
    return;
  }
  if (std::find(categories[categoryName].products.begin(), categories[categoryName].products.end(), productName) != categories[categoryName].products.end()) {
    // Handle product already in category
    return;
  }
  categories[categoryName].products.push_back(productName);
}

void updateProductDetails(std::string productName, std::string newDetails) {
  std::map<std::string, Category> categories;
  if (categories.find(productName) == categories.end()) {
    // Handle product not found
    return;
  }
  for (auto& product : categories[productName].products) {
    if (product == productName) {
      product = newDetails;
      break;
    }
  }
}

void removeProductFromCategory(std::string productName, std::string categoryName) {
  std::map<std::string, Category> categories;
  if (categories.find(categoryName) == categories.end()) {
    // Handle category not found
    return;
  }
  auto& category = categories[categoryName];
  auto it = std::find(category.products.begin(), category.products.end(), productName);
  if (it != category.products.end()) {
    category.products.erase(it);
    // Optionally, update the category's product list to reflect the removal
  }
}

