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

void set_slas_policy(const std::string& policy_name, const std::string& consequences);
void perform_renegotiation(const std::string& policy_name);

void perform_renegotiation(const std::string& policy_name, const std::string& consequences) {
  set_slas_policy(policy_name, consequences);
}

