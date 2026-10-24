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

void initialize_keepass(int message, int* data);
string generate_password(int length, int* allowed_chars);
void create_data_storage(int* data);

initialize_keepass function implementation:

void initialize_keepass(int message, int* data)
{
  if (*data == NULL)
  {
    message = 0;
    return;
  }

  static mono instance = create_mono();

  string password;
  int length = message;

  if (length < 8 || length > 16)
  {
    return;
  }

  string random_chars(8);
  for (int i = 0; i < 8; i++)
  {
    random_chars[i] = generate_random_char(9);
  }

  password = random_chars;

  if (message < 8 || message > 16)
  {
    return;
  }

  *data = password;

  return message;
}

string generate_password(int length, int* allowed_chars) {
  if (*allowed_chars == NULL) {
    return "";
  }
  if (length == NULL || length < 8 || length > 16) {
    return "";
  }
  mono instance = create_mono();
  string password;
  for (int i = 0; i < length; i++) {
    string random_char = generate_random_char(allowed_chars);
    password += random_char;
  }
  *allowed_chars = password;
  return password;
  }
  

void create_data_storage(int* data)
{
  int len = 16;
  string buffer(len);
  *data = buffer;
}

