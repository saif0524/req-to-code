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

string assign privilege(string user);
string updateInventory(string product, string description);
string createCustomer(string name, string email, string password);
string getCustomerDetails(string customer, string& name, string& email);

string assign privilege(string user) 
    { 
        return "You have been assigned the privilege to manage the account.\

string updateInventory(string product, string description) 
    { 
        return "Product: " + product + ", Description: " + description + "; \n}

createCustomer function will create a customer account with the given name, email, and password. It will generate a random password and combine it with the account details to return the account creation result.

string getCustomerDetails(string customer, string& name, string& email) {
    string result = json(

