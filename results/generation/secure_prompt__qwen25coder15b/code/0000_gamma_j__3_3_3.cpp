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

void add_to_cart(const Product& product, ShoppingCart& cart);
void remove_from_cart(const Product& product, ShoppingCart& cart);
void update_cart(const ShoppingCart& cart);
void checkout(ShoppingCart& cart);

void add_to_cart(const Product& product, ShoppingCart& cart) {
  if (cart.contains(product)) {
    cart.increment_quantity(product);
  } else {
    cart.add_product(product);
  }
  cart.update_display();
}

void remove_from_cart(const Product& product, ShoppingCart& cart) {
  if (cart.contains(product)) {
    cart.decrement_quantity(product);
    cart.update_display();
    return true;
  } else {
    cart.update_display();
    return false;
  }
}

void update_cart(const ShoppingCart& cart) {
  cart.update_display();
}

void checkout(ShoppingCart& cart) {
  double total_cost = 0.0;
  for (const auto& item : cart.get_items()) {
    total_cost += item.get_price() * item.get_quantity();
  }
  cout << "Total cost: $

