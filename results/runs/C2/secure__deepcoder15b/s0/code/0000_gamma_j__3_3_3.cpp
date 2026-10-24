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

vector<Product> add_product(const Product& product, int id);
vector<Product> remove_product(const Product& product, int id);
void update_quantity(const Product& product, int newQuantity);
void display_cart();

vector<Product> add_product(const Product& product, int id) 
  { 
    vector<Product> newCart; 
    for (auto& p : cart) 
    { 
      if (p.id != id) 
      { 
        newCart.push_back(p); 
      }
    } 
    newCart.push_back({product}); 
    return newCart;
  }

vector<Product> remove_product(const Product& product, int id) 
  vector<Product> newCart; 
  for (auto& p : cart) 
  { 
    if (p.id != id) 
    { 
      newCart.push_back(p); 
    } 
  } 
  return newCart;

vector<Product> update_quantity(const Product& product, int newQuantity) {
  vector<Product> temp;
  for (auto& p : cart) {
    if (p.id == product.id) {
      temp.push_back({{newQuantity}});
    } else {
      temp.push_back(p);
    }
  }
  return temp;
}

class ShoppingCart {
  vector<Product> cart;

  void add_product(const Product& product, int id) {
    vector<Product> newCart;
    for (auto& p : cart) {
      if (p.id != id) {
        newCart.push_back(p);
      }
    }
    newCart.push_back({product});
    return newCart;
  }

  void remove_product(const Product& product, int id) {
    vector<Product> newCart;
    for (auto& p : cart) {
      if (p.id != id) {
        newCart.push_back(p);
      }
    }
    return newCart;
  }

  void update_quantity(const Product& product, int newQuantity) {
    vector<Product> temp;
    for (auto& p : cart) {
      if (p.id == product.id) {
        temp.push_back({{newQuantity}});
      } else {
        temp.push_back(p);
      }
    }
    return temp;
  }

  void display_cart() {
    int total = 0;
    for (auto& product : cart) {
      std::cout << "Product " << product.id << " quantity: " << product.quantity << " price: " << product.price << std::endl;
      if (product.price != 0) {
        total += product.price;
      }
    }
    std::cout << "Total quantity of items in cart: " << cart.size() << std::endl;
    std::cout << "Total sum of all product prices in cart: " << total << std::endl;
  }
  }

