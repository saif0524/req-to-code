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

bool is_mandatory_info_complete(const std::string& claim_info);
double calculate_claim_amount(const std::string& claim_info, const std::string& treatment_matrix);
void process_claim(const std::string& claim_info, const std::string& treatment_matrix);
void enter_claim(const std::string& claim_info);

bool is_mandatory_info_complete(const std::string& claim_info) { 
    std::vector<std::string> claim_info_parts = split(claim_info, '|'); 
    for (const auto& field : required_fields) { 
        if (std::find(claim_info_parts.begin(), claim_info_parts.end(), field) == claim_info_parts.end()) { 
            return false; 
        } 
    } 
    return true; 
}

double calculate_claim_amount(const std::string& claim_info, const std::string& treatment_matrix) { 
    std::vector<std::string> claim_info_parts = split(claim_info, '|'); 
    std::map<std::string, double> treatment_map = parse_treatment_matrix(treatment_matrix); 
    double claim_amount = 0.0; 
    for (const auto& treatment : claim_info_parts) { 
        auto it = treatment_map.find(treatment); 
        if (it != treatment_map.end()) { 
            claim_amount += it->second; 
        } 
    } 
    return claim_amount; 
}

bool is_mandatory_info_complete(const std::string& claim_info) { 
     std::vector<std::string> claim_info_parts = split(claim_info, '|'); 
     for (const auto& field : required_fields) { 
         if (std::find(claim_info_parts.begin(), claim_info_parts.end(), field) == claim_info_parts.end()) { 
             return false; 
         } 
     } 
     return true; 
 } 
 double calculate_claim_amount(const std::string& claim_info, const std::string& treatment_matrix) { 
     std::vector<std::string> claim_info_parts = split(claim_info, '|'); 
     std::map<std::string, double> treatment_map = parse_treatment_matrix(treatment_matrix); 
     double claim_amount = 0.0; 
     for (const auto& treatment : claim_info_parts) { 
         auto it = treatment_map.find(treatment); 
         if (it != treatment_map.end()) { 
             claim_amount += it->second; 
         } 
     } 
     return claim_amount; 
 } 
 void process_claim(const std::string& claim_info, const std::string& treatment_matrix) { 
     if (!is_mandatory_info_complete(claim_info)) { 
         throw std::invalid_argument("Mandatory information is not complete."); 
     } 
     double claim_amount = calculate_claim_amount(claim_info, treatment_matrix); 
     // Process the claim and store the claim_amount in a database or file. 
 }

bool is_mandatory_info_complete(const std::string& claim_info) { 
     std::vector<std::string> claim_info_parts = split(claim_info, '|'); 
     for (const auto& field : required_fields) { 
         if (std::find(claim_info_parts.begin(), claim_info_parts.end(), field) == claim_info_parts.end()) { 
             return false; 
         } 
     } 
     return true; 
 } 
 double calculate_claim_amount(const std::string& claim_info, const std::string& treatment_matrix) { 
     std::vector<std::string> claim_info_parts = split(claim_info, '|'); 
     std::map<std::string, double> treatment_map = parse_treatment_matrix(treatment_matrix); 
     double claim_amount = 0.0; 
     for (const auto& treatment : claim_info_parts) { 
         auto it = treatment_map.find(treatment); 
         if (it != treatment_map.end()) { 
             claim_amount += it->second; 
         } 
     } 
     return claim_amount; 
 } 
 void process_claim(const std::string& claim_info, const std::string& treatment_matrix) { 
     if (!is_mandatory_info_complete(claim_info)) { 
         throw std::invalid_argument("Mandatory information is not complete."); 
     } 
     double claim_amount = calculate_claim_amount(claim_info, treatment_matrix); 
     // Process the claim and store the claim_amount in a database or file. 
 } 
 void enter_claim(const std::string& claim_info) { 
     // Implementation of the enter_claim function. 
 }

