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

double AddItemToCart(const struct item& item, const vector<item>& cart);
double RemoveItemFromCart(const struct item& item, const vector<item>& cart, const double& total);
pair<int, double> DisplayCartInfo(const vector<item>& cart);
void ClearCart(vector<item>& cart);

double AddItemToCart(const struct item& item, const vector<item>& cart) {
  auto [count, total] = DisplayCartInfo(cart);
  count++;
  total += item->price;
  return total;
  },
  

pair<int, double> RemoveItemFromCart(const struct item& item, const vector<item>& cart) \ \ \ { 
  auto [count, total] = DisplayCartInfo(cart); \ \ \ count--; \ \ \ total -= item->price; \ \ \ return make_pair(count, total); \ \ \ }

pair<int, double> DisplayCartInfo(const vector<item>& cart)
    { 
        int count = 0;
        double total = 0.0;

        for (const auto& item : cart)
        {
            count++;
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

