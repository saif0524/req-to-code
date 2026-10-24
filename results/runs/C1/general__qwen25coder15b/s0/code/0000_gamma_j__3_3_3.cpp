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

struct shared::cart_item {
  int product_id;
  int quantity;
  double price;
};
struct shared::cart; using shared::cart_item;
bool has_product(int product_id); void update_quantity(int product_id, int quantity);
using shared::cart; using shared::cart_item; double calculate_total() { shared::cart cart; double total_cost = 0.0; cart.items().for_each([&](const shared::cart_item& item) { total_cost += item.quantity() * item.price(); }); return total_cost; }

void add_to_cart(int product_id, int quantity);
void remove_from_cart(int product_id, int quantity);
void update_cart(int product_id, int quantity);
void display_cart();
double calculate_total();

void add_to_cart(int product_id, int quantity) {
  shared::cart.add(product_id, quantity);
}

void remove_from_cart(int product_id, int quantity) { shared::cart.remove(product_id, quantity); }

void update_cart(int product_id, int quantity) {
  if (!has_product(product_id)) {
    add_to_cart(product_id, quantity);
  } else {
    update_quantity(product_id, quantity);
  }
}

void display_cart() {
  shared::cart.items().for_each([&](const shared::cart_item& item) {
    std::cout << "Product ID: " << item.product_id() << ", Quantity: " << item.quantity() << ", Total Cost: " << item.total_cost() << std::endl;
  });
}

double calculate_total() { shared::cart cart; double total_cost = 0.0; cart.items().for_each([&](const shared::cart_item& item) { total_cost += item.quantity() * item.price(); }); return total_cost; }

