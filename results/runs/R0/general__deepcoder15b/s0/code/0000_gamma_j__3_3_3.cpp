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

pair<int, double> DisplayCartInfo(const vector<item>& cart);
void ClearCart(vector<item>& cart);

pair<int, double> DisplayCartInfo(const vector<item>& cart) 
    { 
        int count = 0; 
        double total = 0.0; 

        for (const auto& item : cart) 
        { 
            count++; 
        }

        for (const auto& item : cart) 
        { 
            total += item->price; 
        }

        return make_pair(count, total); 
    }

void ClearCart(vector<item>& cart) {
  for (auto& item : cart) {
    item->price = 0.0; 
  }
  return;
  }

