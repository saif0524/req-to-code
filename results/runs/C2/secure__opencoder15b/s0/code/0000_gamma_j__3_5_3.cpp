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

void displayCategories();
void displayProducts();
void searchProducts(std::string searchTerm);
void displayProductDetails(std::string productName);
bool validateInput(std::string input);

void displayCategories() {
    for (const auto& category : categories) {
     std::cout << category << std::endl;
    }
}

void displayProducts() {
    for (const auto& product : products) {
     std::cout << product.getName() << std::endl;
    }
}

void searchProducts(std::string searchTerm) {
    for (const auto& product : products) {
      if (product.getName().find(searchTerm) != std::string::npos) {
        std::cout << product.getName() << std::endl;
     }
    }
}

void displayProductDetails(std::string productName) {
    for (const auto& product : products) {
      if (product.getName() == productName) {
        std::cout << "Product Name: " << product.getName() << std::endl;
        std::cout << "Product Description: " << product.getDescription() << std::endl;
        std::cout << "Product Price: " << product.getPrice() << std::endl;
     }
    }
}

bool validateInput(std::string input) {
    if (input.empty()) {
     std::cout << "Input cannot be empty" << std::endl;
     return false;
    }
    std::cout << "Input is valid" << std::endl;
    return true;
}

std::shared_ptr<std::vector<Product>> products = getProducts();

for (const auto& product : *products) {
    std::cout << product.getName() << std::endl;
}

void searchProducts(std::string searchTerm) {
     std::shared_ptr<std::vector<Product>> products = getProducts();

     for (const auto& product : *products) {
        if (product.getName().find(searchTerm) != std::string::npos) {
         std::cout << product.getName() << std::endl;
        }
     }
}

bool validateInput(std::string input) {
     if (input.empty()) {
     std::cout << "Input cannot be empty" << std::endl;
     return false;
     }
     std::cout << "Input is valid" << std::endl;
     return true;
}

bool validateInput(std::string input) {
     if (input.empty()) {
         std::cout << "Input cannot be empty" << std::endl;
         return false;
     }
     std::cout << "Input is valid" << std::endl;
     return true;
}

bool validateInput(std::string input) {
   if (input.empty()) {
     std::cout << "Input cannot be empty" << std::endl;
     return false;
   }
   std::cout << "Input is valid" << std::endl;
   return true;
}

