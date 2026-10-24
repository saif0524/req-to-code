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

vector<string> ListCategories(string categories);
void RemoveProduct(string productName);

vector<string> ListCategories(string categories)  // Lists all available categories.  // Split the input string by spaces and collect each word as a category.  vector<string> result;  stringstream ss(categories);  string word;  while (ss >> word) {  result.push_back(word);  }  return result;  }

vector<string> RemoveProduct(string productName) {
    vector<string> categories = ...;
    if (find(categories.begin(), categories.end(), productName) != categories.end()) {
        int index = find(categories.begin(), categories.end(), productName) - categories.begin();
        vector<string> newCategories;
        for (int i = 0; i < categories.size(); i++) {
            if (i != index) {
                newCategories.push_back(categories[i]);
            }
        }
        return newCategories;
    } else {
        return vector<string>();
    }
    }

