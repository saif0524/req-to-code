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

No additional declarations needed as all required functions are included.

vector<string> ListCategories(string categories);
vector<string> SearchProducts(string searchTerm, string productName, string category);
void AddProduct(string productName, string category);
void RemoveProduct(string productName);
void ManageCategories(string category);

vector<string> ListCategories(string categories)  // Lists all available categories.  // Split the input string by spaces and collect each word as a category.  vector<string> result;  stringstream ss(categories);  string word;  while (ss >> word) {  result.push_back(word);  }  return result;  }

vector<string> SearchProducts(string searchTerm, string productName, string category) {
  vector<string> result;
  vector<string> categories = splitByFirst(

void AddProduct(string productName, string category) {
  vector<string> result;
  string productStr = string(1, ' ') + productName + 

void AddProduct(string productName, string category) {  vector<string> result;  string productStr = string(1, ' ') +  
  (

void ManageCategories(string category) {
  // Remove all categories that match the search term
  vector<string> removeList;
  for (const string& cat : categories) {
    if (cat == category) {
      removeList.push_back(cat);
    }
  }
  // Remove the collected categories
  for (const string& cat : removeList) {
    auto it = categories.begin();
    while (it != categories.end() && *it != cat) {
      it++;
    }
    categories.erase(it);
  }
  }
  "

