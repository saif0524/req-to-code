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

std::vector<std::string> claim_entry; double standard_price = 100.0;

std::vector<claim_entry> update_claim_status(std::vector<claim_entry> &entry, int claim_num, int status);
std::vector<claim_entry> reject_claim(std::vector<claim_entry> &entry, int claim_num, std::string reason);
std::vector<claim_entry> quarantine_claim(std::vector<claim_entry> &entry, int claim_num, std::string reason);

vector<claim_entry> update_claim_status(vector<claim_entry>& entry, int claim_num, int status) {
    if (entry[claim_num].status != 0) {
        entry[claim_num].status = status;
    }
    return entry;
    }

vector<claim_entry> reject_claim(vector<claim_entry>& entry, int claim_num, std::string reason) {
    if (claim_num < 0 || claim_num >= entry.size()) {
        return entry;
    }
    if (entry[claim_num].status == 0) {
        update_claim_status(entry, claim_num, 1);
    }
    return entry;
    }
    

vector<claim_entry> quarantine_claim(vector<claim_entry>& entry, int claim_num, std::string reason) {
    if (claim_num < 0 || claim_num >= entry.size()) {
        return entry;
    }
    if (entry[claim_num].status == 0) {
        update_claim_status(entry, claim_num, 1);
    }
    return entry;
    }
    

