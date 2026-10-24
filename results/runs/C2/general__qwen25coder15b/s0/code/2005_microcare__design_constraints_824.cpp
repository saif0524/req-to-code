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

struct salesTransaction { std::string distributorName; std::string salesManName; std::string voucherId; };
struct salesTransaction { std::string distributorName; std::string salesManName; std::string voucherId; }; salesTransaction salesTransaction; // Initialize the sales transaction variable with the sales transaction associated with the voucher.

std::string getDistributorName();
std::string getSalesManName();
std::string getSalesReturnDate();
bool checkVoucherSale(std::string distributorName, std::string salesManName, std::string voucherId);
void acceptVoucher(std::string voucherId);

struct salesTransaction { std::string distributorName; std::string salesManName; std::string voucherId; }; salesTransaction salesTransaction; // Initialize the sales transaction variable with the sales transaction associated with the voucher.

using namespace std;
std::string getSalesManName() { return salesManName; }

std::string getSalesReturnDate() { return salesTransaction.salesReturnDate; }

bool checkVoucherSale(std::string distributorName, std::string salesManName, std::string voucherId) { if (salesTransaction.distributorName == distributorName && salesTransaction.salesManName == salesManName) { return true; } else { return false; } }

void acceptVoucher(std::string voucherId) { if (checkVoucherSale(getDistributorName(), getSalesManName(), voucherId)) { salesTransaction.voucherId = voucherId; std::cout << "Voucher accepted for return." << std::endl; } else { std::cout << "Voucher not accepted for return." << std::endl; } }

