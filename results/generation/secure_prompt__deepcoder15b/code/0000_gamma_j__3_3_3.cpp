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

vector<Product> remove_product(const Product& product, int id);
void update_quantity(const Product& product, int newQuantity);
void display_cart();

vector<Product> remove_product(const vector<Product>& cart, int id) {
  for (auto& p : cart) {
    if (p.id == id) {
      vector<Product> newCart;
      for (auto& q : cart) {
        if (q != p) {
          newCart.push_back(q);
        }
      }
      return newCart;
    }
  }
  return vector<Product>(cart.begin(), cart.end());
}

vector<Product> update_quantity(const Product& product, int newQuantity) {
  vector<Product> temp;
  for (auto& p : cart) {
    if (p.id == product.id) {
      pquantity = newQuantity;
      temp.push_back(p);
      break;
    }
  }
  return temp;
}

void display_cart() \
{ \
  std::string result; \
  for (auto& product : cart) \
  { \
    if (product != std::vector<Product>::constant(0, 

