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

struct ShoppingCart {
  std::map<int, int> products;
  std::map<int, double> productPrices;
  double totalCost;
};

void addProductToCart(int productId, int quantity, ShoppingCart& cart);
void removeProductFromCart(int productId, ShoppingCart& cart);
void updateProductQuantity(int productId, int newQuantity, ShoppingCart& cart);
double calculateTotalCost(const ShoppingCart& cart);
void displayCartContents(const ShoppingCart& cart);

struct ShoppingCart {
  std::map<int, int> products;
  std::map<int, double> productPrices;
  double totalCost;
};

void addProductToCart(int productId, int quantity, ShoppingCart& cart) {
  if (productId <= 0 || quantity <= 0) {
    throw std::invalid_argument("Invalid product ID or quantity");
  }

  auto it = cart.products.find(productId);
  if (it != cart.products.end()) {
    it->second += quantity;
  } else {
    cart.products[productId] = quantity;
  }

  cart.totalCost = calculateTotalCost(cart);
  displayCartContents(cart);
}

void removeProductFromCart(int productId, ShoppingCart& cart) {
  if (productId <= 0) {
    throw std::invalid_argument("Invalid product ID");
  }

  auto it = cart.products.find(productId);
  if (it != cart.products.end()) {
    cart.products.erase(it);
  }

  cart.totalCost = calculateTotalCost(cart);
  displayCartContents(cart);
}

void updateProductQuantity(int productId, int newQuantity, ShoppingCart& cart) { if (productId <= 0 || newQuantity <= 0) { throw std::invalid_argument("Invalid product ID or new quantity"); } auto it = cart.products.find(productId); if (it != cart.products.end()) { it->second = newQuantity; } else { throw std::runtime_error("Product not found in cart"); } cart.totalCost = calculateTotalCost(cart); displayCartContents(cart); }

double calculateTotalCost(ShoppingCart& cart) { double totalCost = 0.0; for (const auto& [productId, quantity] : cart.products) { totalCost += quantity * cart.productPrices.at(productId); } return totalCost; }

void displayCartContents(const ShoppingCart& cart) { std::ostringstream oss; oss << "{\"items\": ["; for (const auto& [productId, quantity] : cart.products) { oss << productId << ","; } oss.seekp(-2, std::ios::end); oss << "]}"; std::cout << oss.str(); }

