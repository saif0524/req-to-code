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

string user_group: UserGroup* = create_user_group(string name);
UserGroup* user_group: UserGroup* = add_user(UserGroup* group, string username, string password);
string group: string = get_users(UserGroup* group);
string username: string = get_user(UserGroup* group, string username);
string group: string = validate_user(UserGroup* group, string username, string password);

string get_users(UserGroup* group) {
  string result = "";
  for (UserGroup* member : group) {
    result += to_string(member->id) + "", 
    to_string(member->name), 
    to_string(member->email), 
    to_string(member->password), 
    to_string(member->verify_password), 
    " ",
    "**\**\n};\nreturn result;\n}

string get_user(UserGroup* group, string username) {
  string result = "";
  for (UserGroup* member : group) {
    if (member->username == username) {
      string name = to_string(member->name);
      string email = to_string(member->email);
      string password = to_string(member->password);
      string verify_password = to_string(member->verify_password);
      string id = to_string(member->id);
      result += "user: ", name, ", email: " , email, ", password: " , password, ", verify password: " , verify_password, ", id: " , id;
      return result;
    }
  }
  return "user not found";
}

string validate_user(UserGroup* group, string username, string password)
{
  string result = null;
  UserGroup* member = group;
  while ( member != nullptr )
  {
    if ( member->username == username )
    {
      string name = to_string(member->name);
      string email = to_string(member->email);
      string password = to_string(member->password);
      string verify_password = to_string(member->verify_password);
      if ( password == password && verify_password == verify_password )
      {
        result = "user: ", name, 

