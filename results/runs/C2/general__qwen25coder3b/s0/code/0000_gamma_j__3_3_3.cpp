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

void addProductToCart(Product& product, ShoppingCart& cart);
void removeProductFromCart(Product& product, ShoppingCart& cart);
void updateCartItemCount(ShoppingCart& cart);
void updateCartTotalCost(ShoppingCart& cart);
void displayCart(const ShoppingCart& cart);

void addProductToCart(Product& product, ShoppingCart& cart) { cart.itemCount += 1; cart.totalCost += product.price; return; }

void removeProductFromCart(Product& product, ShoppingCart& cart) { cart.itemCount -= 1; cart.totalCost -= product.price; return; }

void updateCartItemCount(ShoppingCart& cart) { cart.itemCount = cart.items.size(); return; }

void updateCartTotalCost(ShoppingCart& cart) { cart.totalCost = 0; for (const auto& item : cart.items) { cart.totalCost += item.price; } return; }

struct Product { std::string name; double price; }; struct ShoppingCart { int itemCount; double totalCost; std::vector<Product> items; }; void displayCart(const ShoppingCart& cart) { std::stringstream ss; ss << "Items: " << cart.itemCount << \n"Total Cost: $" << cart.totalCost << \n\n"; for (const auto& item : cart.items) { ss << item.name << " - $" << item.price << \n"; } std::cout << ss.str(); }

