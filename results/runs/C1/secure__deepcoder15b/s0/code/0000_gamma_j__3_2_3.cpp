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

create_category(std::string name, std::string description) int& category_type;
update_category(std::string old_name, std::string new_name, std::string description) int& category_type;
create_product_in_category(std::string category_name, std::string product_name, std::string description, std::string price) int& product_id;
update_product(std::string product_id, std::string name, std::string description, std::string price, std::string category) int& product_id;
update_category_description(std::string category_name, std::string new_description) int& category_type;

int& create_category(std::string name, std::string description) {
    if (!is_valid_category_type(category_type)) {
      return false;
    }
    category_type = -1;
    category_type = std::stoi(name);
    category_type = std::stoi(description);
    return true;
  }
  

string update_category(string old_name, string new_name, string description) {
  int old_product_id = stoi(old_name);
  int new_product_id = stoi(new_name);
  if (!is_valid_category_type(old_product_id) || !is_valid_category_type(new_product_id)) {
    return false;
  }
  int new_description = stoi(description);
  if (!is_valid_category_type(new_description)) {
    return false;
  }
  return true;
  }
  

int& create_product_in_category(std::string category_name, std::string product_name, std::string description, std::string price) {
  // Step 1: Validate the existing category
  int& category_type = create_category(category_name, description);
  if (!category_type) return false;

  // Step 2: Validate the product name
  if (!is_valid_product_name(product_name)) return false;

  // Step 3: Create a new product_id
  int new_product_id = -1;
  if (create_product_in_category(new_product_id, product_name, description, price)) return new_product_id;

  return new_product_id;
  }
  

int update_product(int product_id, string name, string description, string price, string category) {
  if (!is_valid_product_id(product_id)) {
    return false;
  }
  int new_name = name;
  int new_description = description;
  int new_price = price;
  int new_category = category;
  string updated_product = {new_name, new_description, new_price, new_category};
  return true;
  }
  

