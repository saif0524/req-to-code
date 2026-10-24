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

void addCategory(const std::string& name, const std::string& parentCategoryName);
void addProductToCategory(const std::string& productName, const std::string& categoryName);
void updateProductDetails(const std::string& productName, const std::string& newDetails);
void deleteCategory(const std::string& categoryName);
void deleteProduct(const std::string& productName);

void addCategory(const std::string& name, const std::string& parentCategoryName) {
  if (name.empty() || parentCategoryName.empty()) {
    throw std::invalid_argument("Category name or parent category name cannot be empty.");
  }

  auto it = categories.find(parentCategoryName);
  if (it == categories.end()) {
    throw std::invalid_argument("Parent category does not exist.");
  }

  auto category = std::make_unique<Category>(name, it->second);
  categories[name] = std::move(category);
}

void addProductToCategory(const std::string& productName, const std::string& categoryName) {
  if (productName.empty() || categoryName.empty()) {
    throw std::invalid_argument("Product name or category name cannot be empty.");
  }

  auto it = categories.find(categoryName);
  if (it == categories.end()) {
    throw std::invalid_argument("Category does not exist.");
  }

  auto& category = it->second;

  struct Product {
    std::string name;
    std::string details;
  };

  auto product = std::make_unique<Product>(productName);
  category.products.push_back(std::move(product));
}

void updateProductDetails(const std::string& productName, const std::string& newDetails) {
  if (productName.empty() || newDetails.empty()) {
    throw std::invalid_argument("Product name or new details cannot be empty.");
  }

  auto it = categories.find(productName);
  if (it == categories.end()) {
    throw std::invalid_argument("Product does not exist.");
  }

  it->second->details = newDetails;
}

void deleteCategory(const std::string& categoryName) {
  if (categories.find(categoryName) == categories.end()) {
    throw std::invalid_argument("Category does not exist.");
  }

  auto& category = categories[categoryName];

  for (auto& product : category.products) {
    products.erase(product);
  }

  categories.erase(categoryName);
}

void deleteProduct(const std::string& productName) {
  if (productName.empty()) {
    throw std::invalid_argument("Product name cannot be empty.");
  }

  auto it = products.find(productName);
  if (it == products.end()) {
    throw std::invalid_argument("Product does not exist.");
  }

  auto& category = it->second->category;

  for (auto& product : category.products) {
    if (product->name == productName) {
      category.products.erase(std::remove(category.products.begin(), category.products.end(), product), category.products.end());
      break;
    }
  }

  products.erase(productName);
  std::cout << "Product deleted successfully." << std::endl;
}

