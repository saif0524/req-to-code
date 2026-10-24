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

void addVoucher(Voucher voucher);
void processClaim(Claim claim);
std::vector<Voucher> getVoucherDetails(Voucher voucher);
void updateVoucher(Voucher voucher);
void deleteVoucher(Voucher voucher);

void addVoucher(Voucher voucher) {
     vouchers.push_back(voucher);
     return JSON{"success": "Voucher added successfully"};
}

void processClaim(Claim claim) {
     for (auto& voucher : vouchers) {
         if (voucher.id == claim.voucherId) {
             voucher.claims.push_back(claim);
             return JSON{"success": "Claim added successfully"};
         }
     }
     return JSON{"error": "Voucher not found"};
}

std::vector<Voucher> getVoucherDetails(Voucher voucher) { 
     for (auto& v : vouchers) { 
         if (v.id == voucher.id) { 
             return std::vector<Voucher>{v}; 
         } 
     } 
     return std::vector<Voucher>(); 
 }

void updateVoucher(Voucher voucher) {
     // Find the voucher in the system's list of Vouchers
     auto it = find_if(vouchers.begin(), vouchers.end(), [&voucher] (const Voucher& v) { return v.id == voucher.id; });

     // If the voucher is found, update the voucher's details
     if (it != vouchers.end()) {
         *it = voucher;
     }

     // If the voucher is not found, return a JSON object with a failure message
     return JSON{"error": "Voucher not found"};
}

void deleteVoucher(Voucher voucher) {
     // Find the voucher in the system's list of Vouchers
     auto it = find_if(vouchers.begin(), vouchers.end(), [voucher] (const Voucher& v) { return v.id == voucher.id; });

     // If the voucher is found, remove it from the system's list of Vouchers
     if (it != vouchers.end()) {
         vouchers.erase(it);
         return JSON{"success": "Voucher deleted successfully"};
     }

     // If the voucher is not found, return a JSON object with a failure message
     return JSON{"error": "Voucher not found"};
}

