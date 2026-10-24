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

bool checkDuplicateSalesman(const std::string& salesmanName);
bool checkDuplicateSalesmanName(const std::string& salesmanName);
bool checkDuplicateSalesmanId(const std::string& salesmanId);
bool checkDuplicateSalesmanNameId(const std::string& salesmanName, const std::string& salesmanId);
bool checkDuplicateSalesmanIdName(const std::string& salesmanId, const std::string& salesmanName);

bool checkDuplicateSalesman(const std::string& salesmanName) {
    // Iterate through the salesman names in the database
    for (const auto& salesman : salesmanNames) {
        // Check if the current salesman name is already present in the database
        if (salesman == salesmanName) {
            // A duplicate salesman name is found
            return false;
        }
    }
    // No duplicate salesman name is found
    return true;
}

bool checkDuplicateSalesmanName(const std::string& salesmanName) {
     // Iterate through the salesman names in the database
     for (const auto& salesman : salesmanNames) {
         // Check if the current salesman name is already present in the database
         if (salesman == salesmanName) {
             // A duplicate salesman name is found
             return false;
         }
     }
     // No duplicate salesman name is found
     return true;
}

bool checkDuplicateSalesmanId(const std::string& salesmanId) {
    // Iterate through the salesman IDs in the database
    for (const auto& salesmanId : salesmanIds) {
        // Check if the current salesman ID is already present in the database
        if (salesmanId == salesmanId) {
            // A duplicate salesman ID is found
            return false;
        }
    }
    // No duplicate salesman ID is found
    return true;
}

bool checkDuplicateSalesmanNameId(const std::string& salesmanName, const std::string& salesmanId) {
    // Iterate through the salesman names in the database
    for (const auto& salesman : salesmanNames) {
        // Check if the current salesman name is already present in the database
        if (salesman == salesmanName) {
            // A duplicate salesman name is found
            return false;
        }
    }
    // Iterate through the salesman IDs in the database
    for (const auto& salesmanId : salesmanIds) {
        // Check if the current salesman ID is already present in the database
        if (salesmanId == salesmanId) {
            // A duplicate salesman ID is found
            return false;
        }
    }
    // No duplicate salesman name or ID is found
    return true;
}

bool checkDuplicateSalesmanIdName(const std::string& salesmanId, const std::string& salesmanName) {
    // Iterate through the salesman IDs in the database
    for (const auto& salesmanId : salesmanIds) {
        // Check if the current salesman ID is already present in the database
        if (salesmanId == salesmanId) {
            // A duplicate salesman ID is found
            return false;
        }
    }
    // Iterate through the salesman names in the database
    for (const auto& salesman : salesmanNames) {
        // Check if the current salesman name is already present in the database
        if (salesman == salesmanName) {
            // A duplicate salesman name is found
            return false;
        }
    }
    // No duplicate salesman ID or name is found
    return true;
}

