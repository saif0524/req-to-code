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

void updateCategory(const std::string& categoryName, const std::string& newCategoryName);
void updateProduct(const std::string& productName, const std::string& newProductName);
void updateProductDetails(const std::string& productName, const std::string& newProductDetails);
void addProductToCategory(const std::string& categoryName, const std::string& productName);
void removeProductFromCategory(const std::string& categoryName, const std::string& productName);

void updateCategory(const std::string& categoryName, const std::string& newCategoryName) {
   for (auto& category : categories) {
     if (category.name == categoryName) {
       category.name = newCategoryName;
       break;
     }
   }
}

struct Product {
    std::string name;
    std::string details;
};

struct Category {
    std::string name;
    std::vector<Product> products;
};

void updateProduct(const std::string& productName, const std::string& newProductName) {
    for (auto& category : categories) {
        for (auto& product : category.products) {
            if (product.name == productName) {
                product.name = newProductName;
                break;
            }
        }
    }
}

void updateProductDetails(const std::string& productName, const std::string& newProductDetails) {
     for (auto& category : categories) {
         for (auto& product : category.products) {
             if (product.name == productName) {
                 product.details = newProductDetails;
                 break;
             }
         }
     }
}

void addProductToCategory(const std::string& categoryName, const std::string& productName) {
    for (auto& category : categories) {
      if (category.name == categoryName) {
        for (auto& product : category.products) {
         if (product.name == productName) {
            product.name = newProductName;
            return product;
         }
        }
     }
    }
}

void removeProductFromCategory(const std::string& categoryName, const std::string& productName) {
     for (auto& category : categories) {
         if (category.name == categoryName) {
             for (auto& product : category.products) {
                 if (product.name == productName) {
                     category.products.erase(std::remove(category.products.begin(), category.products.end(), product), category.products.end());
                     break;
                 }
             }
             break;
         }
     }
}

