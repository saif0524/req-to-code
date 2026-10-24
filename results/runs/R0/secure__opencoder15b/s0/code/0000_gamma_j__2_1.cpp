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

initialize();
start();
stop();
add_product(const std::string& name, double price, int quantity);
remove_product(const std::string& name);

void initialize() {
  // Set up the necessary hardware and software components.
}

void start() {
   // Set up the necessary hardware and software components.
   initialize();
   // Begin accepting orders and customers.
}

void stop() {
    // Shut down all running processes.
    // Clear any running orders or customers.
}

void add_product(const std::string& name, double price, int quantity) {
    // Check if the product already exists in the store.
    for (const auto& product : products) {
        if (product.name == name) {
            // If the product already exists, return an error message.
            return "Product already exists in the store.";
        }
    }

    // If the product does not exist, add it to the store.
    products.push_back({name, price, quantity});
    return "Product added successfully.";
}

void remove_product(const std::string& name) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->name == name) {
            products.erase(it);
            return "Product removed successfully.";
        }
    }
    return "Product does not exist in the store.";
}

