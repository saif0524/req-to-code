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
void clear_cart();
int get_cart_items();
double get_cart_total();

std::map<Product, int> cart;

void add_to_cart(Product product, int quantity) {
  if (cart.find(product) == cart.end()) {
    cart[product] = quantity;
  } else {
    cart[product] += quantity;
  }

  double total = 0;
  for (auto& item : cart) {
    total += item.first.price * item.second;
  }

  cart_total = total;
}

void remove_from_cart(Product product) {
   if (cart.find(product) != cart.end()) {
     cart.erase(product);
   }

   double total = 0;
   for (auto& item : cart) {
     total += item.first.price * item.second;
   }

   cart_total = total;
}

void clear_cart() {
    cart.clear();
    cart_total = 0.0;
}

int get_cart_items() {
    return cart.size();
}

double get_cart_total() {
    double total = 0;
    for (auto& item : cart) {
        total += item.first.price * item.second;
    }
    return total;
}

