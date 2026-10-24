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

using namespace inventory_management;

void create_category(const std::string& name, const std::string& parent_name);
void add_product_to_category(const std::string& category_name, const std::string& product_name);
void update_product_details(const std::string& product_name, const std::string& new_details);
std::vector<std::string> get_category_details(const std::string& category_name);
std::string get_product_details(const std::string& product_name);

void create_category(const std::string& name, const std::string& parent_name) {
  if (name.empty() || parent_name.empty()) {
    return "Error: Category name and parent name cannot be empty.";
  }
  if (!get_category_details(parent_name).empty()) {
    return "Error: Parent category does not exist.";
  }
  bool success = inventory_management::create_category(name, parent_name);
  if (success) {
    return "Category created successfully.";
  } else {
    return "Error: Failed to create category.";
  }
}

void add_product_to_category(const std::string& category_name, const std::string& product_name) {
  if (category_name.empty() || product_name.empty()) {
    return "Error: Category name and product name cannot be empty.";
  }
  if (!get_category_details(category_name).empty()) {
    return "Error: Parent category does not exist.";
  }
  bool success = inventory_management::add_product_to_category(category_name, product_name);
  if (success) {
    return "Product added successfully.";
  } else {
    return "Error: Failed to add product.";
  }
}

void update_product_details(const std::string& product_name, const std::string& new_details) {
  if (product_name.empty() || new_details.empty()) {
    return "Error: Product name and new details cannot be empty.";
  }
  if (!get_category_details(product_name).empty()) {
    return "Error: Product does not exist.";
  }
  bool success = inventory_management::update_product_details(product_name, new_details);
  if (success) {
    return "Product details updated successfully.";
  } else {
    return "Error: Failed to update product details.";
  }
}

void get_product_details(const std::string& product_name) {
  if (product_name.empty()) {
    return "Error: Product name cannot be empty.";
  }
  if (!get_category_details(product_name).empty()) {
    return "Error: Product does not exist.";
  }
  bool success = inventory_management::get_product_details(product_name);
  if (success) {
    return "Product details retrieved successfully.";
  } else {
    return "Error: Failed to retrieve product details.";
  }
}

