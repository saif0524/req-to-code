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

void add_to_cart(Product product, int quantity);
void remove_from_cart(Product product);
void checkout(ShoppingCart cart);
int get_cart_items(ShoppingCart cart);
double get_cart_total(ShoppingCart cart);

void add_to_cart(Product product, int quantity) {
  // Check if the product is already in the cart
  if (cart.contains(product)) {
    // If the product is already in the cart, increment the quantity
    cart[product] += quantity;
  } else {
    // If the product is not in the cart, add it with the specified quantity
    cart[product] = quantity;
  }
}

void remove_from_cart(Product product) {
  if (cart.contains(product)) {
    cart[product] -= quantity;
  } else {
    throw std::runtime_error("Product not in cart");
  }
}

void checkout(ShoppingCart cart) {
  double total = 0;
  for (auto& item : cart) {
    total += item.first.price * item.second;
  }
  std::cout << "Total cost: " << total << std::endl;
}

int get_cart_items(ShoppingCart cart) {
  return cart.size();
}

double get_cart_total(ShoppingCart cart) {
  double total = 0;
  for (auto& item : cart) {
    total += item.first.price * item.second;
  }
  return total;
}

