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

double calculate_return_amount(int numVouchers, double wholeSaleRate);
string generate_report(int batchNo, int voucherNo);

double calculate_return_amount(int numVouchers, double wholeSaleRate) {
    return numVouchers * wholeSaleRate;
    }

string generate_report(int batchNo, int voucherNo)
{ 
    return "\nJSON:\n"
    "reasoning": "3 to 6 short steps explaining how and why you implement it this way, and "code": the complete function definition only.\n"report": { "batchNo": batchNo, "voucherNo": voucherNo, "numberReturned": numVouchers }\n"reasoning": "Generate report with batchNo, voucherNo, and number of vouchers returned."\n},
    

