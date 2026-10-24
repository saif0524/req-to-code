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

VoucherManagementSystem();
void addVoucher(Voucher voucher);
void removeVoucher(int voucherId);
void updateVoucher(Voucher voucher);
Voucher getVoucher(int voucherId);

VoucherManagementSystem() {
    // Constructor for the VoucherManagementSystem class.
}

void addVoucher(Voucher voucher) {
    // Add a new voucher to the system
    system.vouchers.push_back(voucher);
}

void removeVoucher(int voucherId) {
    for (auto it = system.vouchers.begin(); it != system.vouchers.end(); ++it) {
        if (it->voucherId == voucherId) {
            system.vouchers.erase(it);
            return;
        }
    }
    throw std::runtime_error("Voucher not found");
}

void updateVoucher(Voucher voucher) {
    for (auto it = system.vouchers.begin(); it != system.vouchers.end(); ++it) {
        if (it->voucherId == voucher.voucherId) {
            *it = voucher;
            return;
        }
    }
    throw std::runtime_error("Voucher not found");
}

Voucher getVoucher(int voucherId) {
    for (auto it = system.vouchers.begin(); it != system.vouchers.end(); ++it) {
        if (it->voucherId == voucherId) {
            return *it;
        }
    }
    throw std::runtime_error("Voucher not found");
}

void addVoucher(Voucher voucher) {
     // Add a new voucher to the system
     system.vouchers.push_back(voucher);
}

Voucher getVoucher(int voucherId) {
     for (auto it = system.vouchers.begin(); it != system.vouchers.end(); ++it) {
         if (it->voucherId == voucherId) {
             return *it;
         }
     }
     throw std::runtime_error("Voucher not found");
}

Voucher updateVoucher(Voucher voucher) {
     for (auto it = system.vouchers.begin(); it != system.vouchers.end(); ++it) {
         if (it->voucherId == voucher.voucherId) {
             Voucher temp = *it;
             *it = voucher;
             return temp;
         }
     }
     throw std::runtime_error("Voucher not found");
}

Voucher getVoucher(int voucherId) {
     for (auto it = system.vouchers.begin(); it != system.vouchers.end(); ++it) {
         if (it->voucherId == voucherId) {
             return *it;
         }
     }
     throw std::runtime_error("Voucher not found");
}

