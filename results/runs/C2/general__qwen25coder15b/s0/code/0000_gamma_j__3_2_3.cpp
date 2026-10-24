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

namespace inventory_management {

void create_category(const std::string& name, const std::string& parent_name);
void add_product_to_category(const std::string& category_name, const std::string& product_name);
void update_category_details(const std::string& category_name, const std::string& new_name);
void update_product_details(const std::string& category_name, const std::string& product_name, const std::string& new_name);

void create_category(const std::string& name, const std::string& parent_name) { using namespace inventory_management; if (name.empty() || parent_name.empty()) { throw std::invalid_argument(

using namespace inventory_management;

void add_product_to_category(const std::string& category_name, const std::string& product_name) {
  if (category_name.empty() || product_name.empty()) {
    throw std::invalid_argument("Category name and product name cannot be empty");
  }
  if (!inventory_management::category_exists(category_name)) {
    throw std::invalid_argument("Parent category does not exist");
  }
  bool success = inventory_management::add_product_to_category(category_name, product_name);
  if (success) {
    return "Product added successfully";
  } else {
    return "Failed to add product";
  }
}

void update_category_details(const std::string& category_name, const std::string& new_name) { using namespace inventory_management; if (category_name.empty() || new_name.empty()) { throw std::invalid_argument("Category name and new name cannot be empty"); } if (!inventory_management::category_exists(category_name)) { throw std::invalid_argument("Parent category does not exist"); } bool success = inventory_management::update_category_details(category_name, new_name); if (success) { return "Category updated successfully"; } else { return "Failed to update category"; } }

void update_product_details(const std::string& category_name, const std::string& product_name, const std::string& new_name) { using namespace inventory_management; if (category_name.empty() || product_name.empty() || new_name.empty()) { throw std::invalid_argument("Category name and new name cannot be empty"); } if (!inventory_management::category_exists(category_name)) { throw std::invalid_argument("Parent category does not exist"); } bool success = inventory_management::update_product_details(category_name, product_name, new_name); }

