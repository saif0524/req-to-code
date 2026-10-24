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

none

string assign privilege(string user);
string updateInventory(string product, string description);
string upgradeAccount(string currentAccount, string newAccount);
string createCustomer(string name, string email, string password);
string getCustomerDetails(string customer, string& name, string& email);

string assign privilege(string user) { return "Admin privilege"; }

string updateInventory(string product, string description) 
    { 
        return "Product: " + product + ", Description: " + description; 
    }
    return "String updateInventory is correct!"; 

string createCustomer(string name, string email, string password) {
  return "Create customer account for " + name + " with email " + email + " and password " + password + ".";
  }
  

