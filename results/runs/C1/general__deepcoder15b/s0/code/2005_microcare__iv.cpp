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

bool checkForm(const vector<string>& params, bool& isRejected);
vector<string> captureForm(const vector<string>& params);
vector<string> generateTransaction(const vector<string>& data);

bool checkForm(const vector<string>& params, bool& isRejected) {
  for (size_t i = 0; i < params.size(); i++) {
    string param = params[i];
    if (param.empty() || !is_string(param)) {
      continue;
    }
    if (requiredFields.find(param) != requiredFields.end()) {
      isRejected = true;
    } else if (requiredFields.find(param) == requiredFields.end()) {
      continue;
    }
    // else, check other parameters
  }
  return false;
  }

vector<string> captureForm(const vector<string>& params) {
vector<string> result;
for (size_t i = 0; i < params.size(); i++) {
if (!requiredFields.find(params[i])) {
result.push_back(params[i]);
}
}
return result;
}

