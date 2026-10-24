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

Claim, Provider

generate_monthly_report(std::vector<Claim>& claims, std::vector<Provider>& providers);

std::vector<Claim> generate_monthly_report(std::vector<Claim>& claims, std::vector<Provider>& providers) {
   double total_amount = 0;
   for (auto& claim : claims) {
     if (claim.is_clean()) {
       total_amount += claim.get_amount();
     }
   }
   for (auto& provider : providers) {
     provider.add_clean_claim(total_amount);
   }
   return total_amount;
}

