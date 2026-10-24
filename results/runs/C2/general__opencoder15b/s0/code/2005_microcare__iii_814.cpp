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

void submit_claim(const std::string& vsp_name, const std::string& date_of_submission, int no_of_mentioned_forms, int no_of_available_forms);
void process_claim(const std::string& treatment_form_no);
std::string get_claim_details();
void update_claim_status(const std::string& status);
std::string get_claim_no();

void submit_claim(const std::string& vsp_name, const std::string& date_of_submission, int no_of_mentioned_forms, int no_of_available_forms) {
    // Access the claim details from the database using the treatment_form_no
    std::string claim_details = get_claim_details(treatment_form_no);

    // Process the claim details and update the claim status
    update_claim_status(claim_details, "Processed");
}

std::string get_claim_details() {
    // Access the claim details from the database using the treatment_form_no
    std::string claim_details = process_claim(treatment_form_no);

    // Return the claim details as a JSON string
    return claim_details;
}

void update_claim_status(const std::string& status) {
    // Access the claim details from the database using the treatment_form_no
    std::string claim_details = get_claim_details(treatment_form_no);

    // Update the claim status
    claim_details.update_status(status);
}

std::string get_claim_no() {
    // Access the claim details from the database using the treatment_form_no
    std::string claim_details = process_claim(treatment_form_no);

    // Extract the claim number from the claim details
    std::string claim_no = claim_details.get_claim_no();

    // Return the claim number as a JSON string
    return claim_no;
}

void process_claim(const std::string& treatment_form_no) {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = get_claim_details(treatment_form_no);

   // Process the claim details and update the claim status
   update_claim_status(claim_details, "Processed");
}

std::string get_claim_details() {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = process_claim(treatment_form_no);

   // Return the claim details as a JSON string
   return claim_details;
}

void update_claim_status(const std::string& status) {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = get_claim_details(treatment_form_no);

   // Update the claim status
   claim_details.update_status(status);
}

std::string get_claim_no() {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = process_claim(treatment_form_no);

   // Extract the claim number from the claim details
   std::string claim_no = claim_details.get_claim_no();

   // Return the claim number as a JSON string
   return claim_no;
}

std::string get_claim_details() {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = process_claim(treatment_form_no);

   // Return the claim details as a JSON string
   return claim_details;
}

void update_claim_status(const std::string& status) {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = get_claim_details(treatment_form_no);

   // Update the claim status
   claim_details.update_status(status);
}

std::string get_claim_no() {
   // Access the claim details from the database using the treatment_form_no
   std::string claim_details = process_claim(treatment_form_no);

   // Extract the claim number from the claim details
   std::string claim_no = claim_details.get_claim_no();

   // Return the claim number as a JSON string
   return claim_no;
}

std::string get_claim_details() {
    // Access the claim details from the database using the treatment_form_no
    std::string claim_details = process_claim(treatment_form_no);

    // Return the claim details as a JSON string
    return claim_details;
}

void update_claim_status(const std::string& status) {
     // Access the claim details from the database using the treatment_form_no
     std::string claim_details = get_claim_details(treatment_form_no);

     // Update the claim status
     claim_details.update_status(status);
}

std::string get_claim_no() {
     // Access the claim details from the database using the treatment_form_no
     std::string claim_details = process_claim(treatment_form_no);

     // Extract the claim number from the claim details
     std::string claim_no = claim_details.get_claim_no();

     // Return the claim number as a JSON string
     return claim_no;
}

