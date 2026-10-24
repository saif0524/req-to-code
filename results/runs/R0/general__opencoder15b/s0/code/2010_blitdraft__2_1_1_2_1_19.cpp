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

bool validateUserCriteria(const User& user);
bool validateUserFields(const User& user);
std::string generateErrorMessage(const User& user);

bool validateUserCriteria(const User& user) { 
  // Check if all the user criteria are filled out. 
  if (user.criteria1.empty() || user.criteria2.empty() || user.criteria3.empty()) { 
    return false; 
  } 
  // Check if all the user fields are filled out. 
  if (user.field1.empty() || user.field2.empty() || user.field3.empty()) { 
    return false; 
  } 
  // Check if the user has at least one of each of the user criteria. 
  if (user.criteria1.empty() && user.criteria2.empty() && user.criteria3.empty()) { 
    return false; 
  } 
  return true; 
}

bool validateUserFields(const User& user) { 
   // Check if all the user fields are filled out. 
   if (user.field1.empty() || user.field2.empty() || user.field3.empty()) { 
     return false; 
   } 
   // Check if all the user fields are filled out. 
   if (user.field1.empty() || user.field2.empty() || user.field3.empty()) { 
     return false; 
   } 
   // Check if the user has at least one of each of the user criteria. 
   if (user.criteria1.empty() && user.criteria2.empty() && user.criteria3.empty()) { 
     return false; 
   } 
   return true; 
}

bool validateUserCriteria(const User& user) { 
   // Check if all the user criteria are filled out. 
   if (user.criteria1.empty() || user.criteria2.empty() || user.criteria3.empty()) { 
     return false; 
   } 
   // Check if all the user fields are filled out. 
   if (user.field1.empty() || user.field2.empty() || user.field3.empty()) { 
     return false; 
   } 
   // Check if the user has at least one of each of the user criteria. 
   if (user.criteria1.empty() && user.criteria2.empty() && user.criteria3.empty()) { 
     return false; 
   } 
   return true; 
}

