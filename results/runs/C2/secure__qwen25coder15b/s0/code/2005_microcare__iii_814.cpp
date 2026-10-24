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

std::string vsp_name;

std::string get_vsp_name();
std::string get_date_of_submission();
int get_no_of_mentioned_forms();
int get_no_of_available_forms();
void submit_claim(std::string treatment_form_no);

std::string get_vsp_name() { return vsp_name; }

std::string date_of_submission; std::string get_date_of_submission() { return date_of_submission; }

int get_no_of_mentioned_forms() { int mentioned_forms = 0; return mentioned_forms; }

int mentioned_forms = 0; int processed_forms = 0; int get_no_of_available_forms() { return mentioned_forms - processed_forms; }

void submit_claim(std::string treatment_form_no) {
  std::string vsp_name = get_vsp_name();
  std::string date_of_submission = get_date_of_submission();
  int mentioned_forms = get_no_of_mentioned_forms();
  int available_forms = mentioned_forms - processed_forms;
  submit_claim_to_misu_field_office(treatment_form_no, vsp_name, date_of_submission, available_forms);
}

