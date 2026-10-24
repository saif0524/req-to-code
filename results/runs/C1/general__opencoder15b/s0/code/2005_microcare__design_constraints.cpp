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

create_voucher(std::string admin_name, int min_quantity, std::string voucher_name, int voucher_number);
prepare_voucher(int voucher_number, std::string admin_name, std::string voucher_name, std::string new_date);
hold_voucher(int voucher_number, std::string admin_name);
amend_voucher(int voucher_number, std::string admin_name, std::string new_date);

void create_voucher(std::string admin_name, int min_quantity, std::string voucher_name, int voucher_number) {
    // Check if the voucher number already exists
    if (!voucher_number_exists(voucher_number)) {
        // Create a new voucher
        voucher[voucher_number] = Voucher(voucher_name, min_quantity, std::nullopt);
    } else {
        // Return an error message
        return_error("The voucher number already exists.");
    }
}

void prepare_voucher(int voucher_number, std::string admin_name, std::string voucher_name, std::string new_date) {
    // Check if the voucher exists
    if (voucher_number_exists(voucher_number)) {
        // Check if the admin has the authority to prepare the voucher
        if (has_authority(voucher_number, admin_name)) {
            // Prepare the voucher
            prepare_voucher(voucher_number, admin_name, voucher_name, new_date);
            // Update the voucher's validity date
            voucher[voucher_number].validity_date = new_date;
        } else {
            // Return an error message
            return_error("You do not have the authority to amend this voucher.");
        }
    } else {
        // Return an error message
        return_error("The voucher does not exist.");
    }
}

void hold_voucher(int voucher_number, std::string admin_name) {
    // Check if the voucher exists
    if (voucher_number_exists(voucher_number)) {
        // Check if the admin has the authority to hold the voucher
        if (has_authority(voucher_number, admin_name)) {
            // Hold the voucher
            voucher[voucher_number].is_held = true;
            // Log the hold action
            log_hold_action(voucher_number, admin_name);
        } else {
            // Return an error message
            return_error("You do not have the authority to hold this voucher.");
        }
    } else {
        // Return an error message
        return_error("The voucher does not exist.");
    }
}

void amend_voucher(int voucher_number, std::string admin_name, std::string new_date) {
     // Check if the voucher exists
     if (voucher_number_exists(voucher_number)) {
         // Check if the admin has the authority to amend the voucher
         if (has_authority(voucher_number, admin_name)) {
             // Prepare the voucher
             prepare_voucher(voucher_number, admin_name, voucher_name, new_date);
             // Amend the voucher's validity date
             voucher[voucher_number].validity_date = new_date;
         } else {
             // Return an error message
             return_error("You do not have the authority to amend this voucher.");
         }
     } else {
         // Return an error message
         return_error("The voucher does not exist.");
     }
}

