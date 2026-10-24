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

void create_voucher(int client_id, int partner_id, int service_provider_id, int visit_id, int claim_id);
void submit_sales_details(int voucher_id, int client_id, int partner_id, int service_provider_id, int visit_id, int claim_id);
void validate_claim_form(int claim_id);
void generate_financial_report(int voucher_id, int client_id, int partner_id, int service_provider_id, int visit_id, int claim_id);
void get_client_feedback(int client_id);

