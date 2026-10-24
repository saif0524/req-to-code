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

// Create a new get_product_by_id function to retrieve a product by a specific category_id

int create_product(int product_id, std::string name, std::string price, int category_id);
int update_product_price(int product_id, std::string new_price);
int update_product_category(int product_id, int new_category);
int update_category_price(int category_id, std::string new_price);

int create_product(int product_id, string name, string price, int category_id) {
  return { product_id, name, price, category_id, 0 }; }
  "reasoning": "The create_product function is implemented to create a new product with specified product_id, name, price, and category_id. It returns a struct containing all necessary fields including timestamp for when the product was created.\n", 

int update_product_price(int product_id, std::string new_price) {
  // Get the product by its ID
  int product_id_from_product = get_product_by_id(product_id);
  
  // Update the product's price
  update_product_price(product_id_from_product, new_price);
  
  // Return the updated product_id
  return product_id;
  }
  

int get_product_by_id(int category_id) {
  for (auto& product : products) {
    if (product.category_id == category_id) {
      return product.id;
    }
    // This line was not implemented, causing the compiler error
    // get_product_by_id was not declared in this scope
  }
  return -1;
}
int update_product_category(int product_id, int new_category) {
  auto& product = get_product_by_id(product_id);
  if (product == -1) {
    return -1;
  }
  product.category = new_category;
  return product.id;
}

int get_product_by_id(int category_id) {
    for (auto& product : products) {
        if (product.category_id == category_id) {
            return product.id;
        }
    }
    return -1;
  }
  

