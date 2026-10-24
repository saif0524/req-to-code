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

registerCustomer(const std::string& username, const std::string& password, const std::string& email);
loginCustomer(const std::string& username, const std::string& password);
logoutCustomer();
createProfile(const std::string& username, const std::string& password, const std::string& email);
updateProfile(const std::string& username, const std::string& email, const std::string& address, const std::string& city, const std::string& state, const std::string& zip, const std::string& country);

std::string registerCustomer(const std::string& username, const std::string& password, const std::string& email) {
    // Check if the customer already exists
    if (findCustomer(username) != nullptr) {
     return "Customer already exists.";
    }

    // Create a new customer account
    Customer* newCustomer = new Customer();
    newCustomer->username = username;
    newCustomer->password = password;
    newCustomer->email = email;

    // Store the new customer in the system
    customers.push_back(newCustomer);

    return "Registration successful.";
}

std::string loginCustomer(const std::string& username, const std::string& password) {
    // Find the customer with the given username
    Customer* customer = findCustomer(username);

    // If the customer is found
    if (customer != nullptr) {
      // If the provided password matches the stored password
      if (customer->password == password) {
        return "Login successful.";
     }
      // If the provided password does not match the stored password
      else {
        return "Invalid password.";
     }
    }
    // If the customer is not found
    else {
     return "Customer not found.";
    }
}

void logoutCustomer() {
     currentCustomer = nullptr;
}

std::string createProfile(const std::string& username, const std::string& password, const std::string& email) {
     // Check if the customer already exists
     if (findCustomer(username) != nullptr) {
         return "Customer already exists.";
     }

     // Create a new customer account
     Customer* newCustomer = new Customer();
     newCustomer->username = username;
     newCustomer->password = password;
     newCustomer->email = email;

     // Store the new customer in the system
     customers.push_back(newCustomer);

     return "Registration successful.";
}

void updateProfile(const std::string& username, const std::string& email, const std::string& address, const std::string& city, const std::string& state, const std::string& zip, const std::string& country) {
    Customer* customer = findCustomer(username);
    if (customer != nullptr) {
        customer->email = email;
        customer->address = address;
        customer->city = city;
        customer->state = state;
        customer->zip = zip;
        customer->country = country;
    } else {
        return "Customer not found.";
    }
    return "Profile updated successfully.";
}

