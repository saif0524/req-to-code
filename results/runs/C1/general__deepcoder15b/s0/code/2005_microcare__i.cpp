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

vector<Distributor> all_distributors; // To be used in deleteDistributor function

vector<Distributor> getAllDistributors(const string& codes);
Distributor getDistributorByCode(const string& code);
bool updateDistributorStatus(const string& code, bool newStatus);
bool addDistributor(const string& code, string name, string type, string nameProp, string address, int contact, string email, bool status);
bool deleteDistributor(const string& code);

vector<Distributor> getAllDistributors(const string& codes) {
    vector<Distributor> result;
    vector<Distributor> new_distributors;
    for (const string& code : codes) {
        if (find(new_distributors.begin(), new_distributors.end(), get<0>(code))) {
            Distributor d;
            d.name = code;
            d.type = "hospital";
            d.address = address;
            d.contact = contact;
            d.email = email;
            d.status = (status ? true : false);
            if (status) {
                d.update(true);
            } else {
                d.update(false);
            }
            new_distributors.push_back(d);
        } else {
            new_distributors.push_back(d);
            d.name = code;
            d.type = type;
            d.nameProp = name;
            d.address = address;
            d.contact = contact;
            d.email = email;
            d.status = status;
            if (status) {
                d.update(true);
            } else {
                d.update(false);
            }
        }
    }
    result = new_distributors;
    return result;
    }
    

vector<Distributor> getDistributorByCode(const string& code) {
    auto all_distributors = getAllDistributors(code);
    if (all_distributors.empty() || all_distributors.size() != 1) {
        return null;
    }
    Distributor d;
    d.name = code;
    d.type = 

bool updateDistributorStatus(const string& code, bool newStatus) {
  vector<Distributor> distributors;
  if (find(distributors.begin(), distributors.end(), get<0>(code))) {
    update(distributors[0], newStatus);
  }
  return true;
  }
  

vector<Distributor> addDistributor(const string& code, string name, string type, string nameProp, string address, int contact, string email, bool status) {
    vector<Distributor> new_distributors;
    Distributor d;
    if (find(new_distributors.begin(), new_distributors.end(), get<0>(code))) {
        d.name = name;
        d.type = type;
        d.nameProp = nameProp;
        d.address = address;
        d.contact = contact;
        d.email = email;
        d.status = status;
        if (status) {
            d.update(newStatus);
        } else {
            d.update(false);
        }
        new_distributors.push_back(d);
    } else {
        new_distributors.push_back(d);
        d.name = name;
        d.type = type;
        d.nameProp = nameProp;
        d.address = address;
        d.contact = contact;
        d.email = email;
        d.status = status;
        if (status) {
            d.update(newStatus);
        } else {
            d.update(false);
        }
    }
    return true;
    }
    

bool deleteDistributor(const string& code) {
    vector<Distributor> all_distributors = getAllDistributors(code);
    for (auto& d : all_distributors) {
        if (get<0>(d) == code) {
            delete all_distributors.begin() + get<0>(d);
            return true;
        }
    }
    return false;
  }
  

