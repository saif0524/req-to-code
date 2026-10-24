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

pair<string, string, string> view_product(int product_id);
string add_to_cart(int product_id, int quantity);
string place_order(int product_id, int quantity);

pair<string, string, string> view_product(int product_id) {
  if (product_id < 1 || product_id > 100) {
    return make_pair(

string add_to_cart(int product_id, int quantity) {
  // Check if product_id is valid
  if (product_id < 1 || product_id > 100) {
    return string();
  }
  
  // Check if product exists
  const map = make_map();
  if (map.find(product_id) == map.end()) {
    return string();
  }
  
  // Check if quantity is valid
  if (quantity < 1) {
    return string();
  }
  
  // Add product to cart
  map[product_id].name = 

string place_order(int product_id, int quantity)
{ 
  if (product_id < 1 || product_id > 100) {
    return string();
  }
  const map = make_map();
  if (map.find(product_id) == map.end()) {
    return string();
  }
  if (quantity < 1) {
    return string();
  }
  add_to_cart(product_id, quantity);
  return string('Order placed');
}

