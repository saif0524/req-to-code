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

void updateProduct(const std::string& productName, const std::string& newProductName) {
     for (auto& product : products) {
       if (product.name == productName) {
         product.name = newProductName;
         break;
       }
     }
}

void updateProductDetails(const std::string& productName, const std::string& newProductDetails) {
     for (auto& product : products) {
       if (product.name == productName) {
         product.details = newProductDetails;
         break;
       }
     }
}

void addProductToCategory(const std::string& categoryName, const std::string& productName) {
     for (auto& category : categories) {
       if (category.name == categoryName) {
         for (auto& product : products) {
          if (product.name == productName) {
            product.category = categoryName;
            product.details = newProductDetails;
            return "Product added to category";
          }
         }
       }
     }
     return "Category or product not found";
}

void removeProductFromCategory(const std::string& categoryName, const std::string& productName) {
     for (auto& category : categories) {
       if (category.name == categoryName) {
         for (auto& product : products) {
          if (product.name == productName) {
            product.category = "";
            product.details = "";
            return "Product removed from category";
          }
         }
       }
     }
     return "Category or product not found";
}

void updateProductDetails(const std::string& productName, const std::string& newProductDetails) {
     for (auto& product : products) {
        if (product.name == productName) {
         product.details = newProductDetails;
         break;
        }
     }
}

void updateProduct(const std::string& productName, const std::string& newProductName) {
     for (auto& product : products) {
        if (product.name == productName) {
         product.name = newProductName;
         break;
        }
     }
}

void updateCategory(const std::string& categoryName, const std::string& newCategoryName) {
     for (auto& category : categories) {
       if (category.name == categoryName) {
         category.name = newCategoryName;
         break;
       }
     }
}

void removeProductFromCategory(const std::string& categoryName, const std::string& productName) {
     for (auto& category : categories) {
       if (category.name == categoryName) {
         for (auto& product : products) {
           if (product.name == productName) {
             product.category = "";
             product.details = "";
             return "Product removed from category";
           }
         }
       }
     }
     return "Category or product not found";
}

