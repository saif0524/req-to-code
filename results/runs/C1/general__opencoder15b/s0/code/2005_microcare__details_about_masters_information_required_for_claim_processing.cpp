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

double get_drug_price(int drug_code);
std::string get_claim_status(int claim_code);
std::string get_claim_reason(int reason_code);
std::string get_claim_quarantine_reason(int reason_code);
std::string get_claim_rejection_reason(int reason_code);

double get_drug_price(int drug_code) {
   for (int i = 0; i < drugs.size(); i++) {
     if (drugs[i].drug_code == drug_code) {
       return drugs[i].retail_price;
     }
   }
   return -1.0;
}

std::string get_claim_status(int claim_code) {
    for (int i = 0; i < claims.size(); i++) {
      if (claims[i].code == claim_code) {
        return claims[i].status;
     }
    }
    return "";
}

double get_drug_price(int drug_code) {
  for (int i = 0; i < drugs.size(); i++) {
    if (drugs[i].drug_code == drug_code) {
      return drugs[i].retail_price;
    }
  }
  return -1.0;
}

std::string get_claim_status(int claim_code) {
  for (int i = 0; i < claims.size(); i++) {
    if (claims[i].code == claim_code) {
      return claims[i].status;
    }
  }
  return "";
}

std::string get_claim_reason(int reason_code) {
  for (int i = 0; i < claims.size(); i++) {
    if (claims[i].code == reason_code) {
      return claims[i].reason;
    }
  }
  return "";
}

std::string get_claim_quarantine_reason(int reason_code) {
  for (int i = 0; i < claims.size(); i++) {
    if (claims[i].code == reason_code && claims[i].status == "Quarantine") {
      return claims[i].reason;
    }
  }
  return "";
}

std::string get_claim_rejection_reason(int reason_code) {
  for (int i = 0; i < claims.size(); i++) {
    if (claims[i].code == reason_code && claims[i].status == "Rejected") {
      return claims[i].reason;
    }
  }
  return "";
}

double get_drug_price(int drug_code) {
    for (int i = 0; i < drugs.size(); i++) {
      if (drugs[i].drug_code == drug_code) {
        return drugs[i].retail_price;
      }
    }
    return -1.0;
}

double get_drug_price(int drug_code) {
     for (int i = 0; i < drugs.size(); i++) {
       if (drugs[i].drug_code == drug_code) {
         return drugs[i].retail_price;
       }
     }
     return -1.0;
 }

std::string get_claim_status(int claim_code) {
   for (int i = 0; i < claims.size(); i++) {
     if (claims[i].code == claim_code) {
       return claims[i].status;
     }
   }
   return "";
 }

std::string get_claim_reason(int reason_code) {
   for (int i = 0; i < claims.size(); i++) {
     if (claims[i].code == reason_code) {
       return claims[i].reason;
     }
   }
   return "";
 }

std::string get_claim_quarantine_reason(int reason_code) {
   for (int i = 0; i < claims.size(); i++) {
     if (claims[i].code == reason_code && claims[i].status == "Quarantine") {
       return claims[i].reason;
     }
   }
   return "";
 }

std::string get_claim_rejection_reason(int reason_code) {
   for (int i = 0; i < claims.size(); i++) {
     if (claims[i].code == reason_code && claims[i].status == "Rejected") {
       return claims[i].reason;
     }
   }
   return "";
 }

double get_drug_price(int drug_code) {
     for (int i = 0; i < drugs.size(); i++) {
       if (drugs[i].drug_code == drug_code) {
         return drugs[i].retail_price;
       }
     }
     return -1.0;
 }

