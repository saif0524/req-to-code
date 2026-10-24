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

string source, string destination, string data, int expected_length, string message;
string source, string destination, string data, int expected_length, string message;
int parameter1, int parameter2, string expected_type1, string expected_type2;
string source, string destination, string data, int expected_length;
tuple string parameters, error_code;

string receiveData(string source, string destination, string data, int expected_length, string message) {
  if (data.length() < expected_length) {
    return "Invalid data length: source to destination should be at least " + expected_length + " bytes";
  }
  string destinationBuffer(expected_length);
  for (int i = 0; i < expected_length; i++) {
destinationBuffer[i] = data[i];
}
  return destinationBuffer;
}

static bool receiveData(string source, string destination, string data, int expected_length, string message) {
if (data.length() < expected_length) {
return "Invalid data length: source to destination should be at least " + expected_length + " bytes";
}
string destinationBuffer(expected_length);
for (int i = 0; i < expected_length; i++) {
destinationBuffer[i] = data[i];
}
return destinationBuffer;
}

string source(string data, int expected_length) {
  if (data.length() < expected_length) {
    return "Invalid data length: source should be at least " + expected_length + " bytes";
  }
  string sourceBuffer(expected_length);
  for (int i = 0; i < expected_length; i++) {
    sourceBuffer[i] = data[i];
  }
  return sourceBuffer;
}

