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

create_account(std::string username, std::string password, std::string email);
login(std::string username, std::string password);
logout();
update_profile(std::string username, std::string new_password, std::string new_email);
delete_account(std::string username, std::string password);

std::string create_account(std::string username, std::string password, std::string email) {
   // Check if the account already exists
   if (account_exists(username)) {
     return "Account already exists.";
   }
   // Create a new account
   Customer new_account = Customer(username, password, email);
   // Add the new account to the system
   add_customer(new_account);
   return "Account created successfully.";
}

std::string login(std::string username, std::string password) {
   // Check if the account exists
   if (!account_exists(username)) {
     return "Account does not exist.";
   }
   // Verify the provided password with the stored password
   if (password != get_password(username)) {
     return "Incorrect password.";
   }
   // If both checks pass, log in the customer
   set_logged_in(username);
   return "Logged in successfully.";
}

void logout() {
   logged_in = false;
}

void update_profile(std::string username, std::string new_password, std::string new_email) {
   if (!account_exists(username)) {
     return "Account does not exist.";
   }
   if (password != get_password(username)) {
     return "Incorrect password.";
   }
   // Update the customer's profile information with the given new password and email
   update_customer_profile(username, new_password, new_email);
   return "Profile updated successfully.";
}

void delete_account(std::string username, std::string password) {
   if (!account_exists(username)) {
     return "Account does not exist.";
   }
   if (password != get_password(username)) {
     return "Incorrect password.";
   }
   logout();
   delete_customer(username);
   return "Account deleted successfully.";
}

