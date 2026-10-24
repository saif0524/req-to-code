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

void run_debug_mode();
void run_test_credit_card_transactions();
void run_test_shipping_orders();
void create_test_environment();

void run_debug_mode() {
    run_test_credit_card_transactions();
    run_test_shipping_orders();
}

void create_test_environment() {
    // Run test credit card transactions.
    run_test_credit_card_transactions();
    // Run test shipping orders.
    run_test_shipping_orders();
    // Additional steps to create a test environment can be added here.
}

