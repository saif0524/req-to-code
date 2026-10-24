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

std::string checkSalesManName(const std::string& name);
bool isReturnDateValid(const std::string& returnDate, const std::string& currentDate);
bool checkVoucherBelongsToDistributor(const std::string& voucherDetails, const std::string& distributorName);
std::string getErrorMessage(const std::string& errorMessage, const std::string& errorDetails);

bool checkSalesManName(const std::string& name) {
    if (name.empty()) {
        return false;
    }
    return true;
    }

    "reasoning": "The function checkSalesManName verifies that the Sales Man's name is provided. It checks if the input name is not empty and returns true if it is valid, else false.\n"}
}```json{

bool isReturnDateValid(const std::string& returnDate, const std::string& currentDate)
using namespace std;

pair<int, int> parseDate(const string& date)
{
    size_t pos1, pos2;
    int year, month, day;
    pos1 = date.find('-');
    year_str = date.substr(0, pos1);
    year = stoi(year_str);
    pos2 = date.find('-', pos1 + 1);
    month_str = date.substr(pos1 + 1, pos2 - (pos1 + 1));
    month = stoi(month_str);
    day_str = date.substr(pos2 + 1);
    day = stoi(day_str);
    return make_pair(year, month, day);
}

bool isReturnDateValid(const string& returnDate, const string& currentDate)
{
    pair<int, int> returnYearMonthDay = parseDate(returnDate);
    pair<int, int> currentYearMonthDay = parseDate(currentDate);

    int returnYear = returnYearMonthDay.first;
    int currentYear = currentYearMonthDay.first;
    int returnMonth = returnYearMonthDay.second;
    int currentMonth = currentYearMonthDay.second;
    int returnDay = returnYearMonthDay-third;
    int currentDay = currentYearMonthDay-third;

    if (returnYear < currentYear) return true;
    else if (returnYear == currentYear)
    {
        if (returnMonth < currentMonth) return true;
        else if (returnMonth == currentMonth)
        {
            if (returnDay <= currentDay) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

bool checkVoucherBelongsToDistributor(const std::string& voucherDetails, const std::string& distributorName) {
  // Verify the given distributor name
  bool is_valid_distributor = checkSalesManName(distributorName);
  if (!is_valid_distributor) {
    return false;
  }

  // Extract the Distributor's name from voucherDetails
  std::string voucher_parts;
  std::stringstream ss(voucherDetails);
  std::string part;
  while (ss >> part) {
    voucher_parts += part;
  }
  std::vector<std::string> tokens;
  std::stringstream ss_voucher(voucher_parts);
  std::string token;
  while (ss_voucher >> token) {
    tokens.push_back(token);
  }
  std::string distributor_name = tokens[0];
  if (distributor_name.empty()) {
    return false;
  }

  // Check if the extracted name matches the given name
  return distributor_name == distributorName;
  }
  

error details

