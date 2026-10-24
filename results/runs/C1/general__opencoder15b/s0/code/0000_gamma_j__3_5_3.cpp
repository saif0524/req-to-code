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
void displayCategoryDetails(std::string categoryName);

void displayCategories() {
   for (const auto& category : categories) {
     std::cout << category << std::endl;
   }
}

void displayProducts() {
    for (const auto& product : *products) {
        std::cout << product.getName() << std::endl;
    }
}

void searchProducts(std::string searchTerm) {
    std::vector<std::string> matchingProducts;
    for (const auto& product : *products) {
      if (product.getName().find(searchTerm) != std::string::npos) {
        matchingProducts.push_back(product.getName());
      }
    }
    for (const auto& productName : matchingProducts) {
      std::cout << productName << std::endl;
    }
}

void displayProductDetails(std::string productName) {
   std::map<std::string, Product>::iterator it;
   for (it = products.begin(); it != products.end(); ++it) {
     if (it->first == productName) {
       std::cout << "Product Name: " << it->second.getName() << std::endl;
       std::cout << "Product Description: " << it->second.getDescription() << std::endl;
       std::cout << "Product Price: " << it->second.getPrice() << std::endl;
     }
   }
}

void displayCategoryDetails(std::string categoryName) {
    for (const auto& category : categories) {
      if (category == categoryName) {
        std::cout << "Category Name: " << category << std::endl;
        // Add code to display other category details
     }
    }
}

