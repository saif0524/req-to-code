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

string get_current_date();
int get_distributor_name(int distributor_id);
int get_sales_man_name(int sales_man_id);

string get_current_date() {
    time_t now_time;
    mktime(&now_time);
    int seconds = now_time[3];
    stringstream ss;
    ss << setw(6) << setfill(' ') << seconds << " seconds";
    return ss.str();
  },
  

int get_distributor_name(int distributor_id) {
  for (int i = 0; i < 100; i++) {
if (distributors[i].id == distributor_id) {
return distributors[i].name;
}
}
return -1;
}

int get_sales_man_name(int sales_man_id) {
  static const std::vector<std::pair<int, std::string>> sales_men = {
    {1, 

