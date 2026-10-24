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

void voucher_management(std::vector<std::string> &vouchers, std::vector<std::string> &providers, std::vector<std::string> &patients, std::vector<std::string> &problems, std::vector<std::string> &results);
std::string calculate_refund(std::string &voucher, std::string &provider, std::string &patient, std::string &problem);
std::string generate_voucher(std::string &provider, std::string &patient, std::string &problem);
void update_voucher_status(std::string &voucher, std::string &status);
std::string check_voucher_status(std::string &voucher);

void voucher_management(std::vector<std::string> &vouchers, std::vector<std::string> &providers, std::vector<std::string> &patients, std::vector<std::string> &problems, std::vector<std::string> &results) {
    for (int i = 0; i < vouchers.size(); i++) {
        std::string voucher = vouchers[i];
        std::string provider = providers[i];
        std::string patient = patients[i];
        std::string problem = problems[i];

        std::string refund = calculate_refund(voucher, provider, patient, problem);
        std::string status = check_voucher_status(voucher);

        if (status == "refunded") {
            results[i] = refund;
        }
    }
}

std::string calculate_refund(std::string &voucher, std::string &provider, std::string &patient, std::string &problem) {
    std::string refund = std::to_string(std::hash<std::string>()(voucher + provider + patient + problem));
    std::string status = check_voucher_status(voucher);
    if (status == "refunded") {
        return "Voucher has already been refunded.";
    }
    update_voucher_status(voucher, "refunded");
    return refund;
}

std::string update_voucher_status(std::string &voucher, std::string &status) {
    std::string hash = std::to_string(std::hash<std::string>()(voucher + status));
    std::string voucher_status = check_voucher_status(voucher);
    if (voucher_status == "refunded") {
        return "Voucher has already been refunded.";
    }
    update_voucher_status(voucher, "refunded");
    return hash;
}

std::string check_voucher_status(std::string &voucher) {
    std::string status = check_voucher_status(voucher);
    if (status == "refunded") {
        return "Voucher has already been refunded.";
    }
    return status;
}

std::string generate_voucher(std::string &provider, std::string &patient, std::string &problem) {
    std::string voucher = std::to_string(std::hash<std::string>()(provider + patient + problem));
    update_voucher_status(voucher, "generated");
    return voucher;
}

std::string update_voucher_status(std::string &voucher, std::string &status) {
     std::string hash = std::to_string(std::hash<std::string>()(voucher + status));
     std::string voucher_status = check_voucher_status(voucher);
     if (voucher_status == "refunded") {
         return "Voucher has already been refunded.";
     }
     update_voucher_status(voucher, "refunded");
     return hash;
}

std::string check_voucher_status(std::string &voucher) {
     std::string status = check_voucher_status(voucher);
     if (status == "refunded") {
         return "Voucher has already been refunded.";
     }
     return status;
}

std::string check_voucher_status(std::string &voucher) {
    std::string status = check_voucher_status(voucher);
    if (status == "refunded") {
        return "Voucher has already been refunded.";
    }
    return status;
}

