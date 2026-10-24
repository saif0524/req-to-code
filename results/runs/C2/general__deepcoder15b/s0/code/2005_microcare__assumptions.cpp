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

int claimEntry(int claimNumber, const vector<vector<double>> &matrix);
double process(const vector<double> &claimData, const vector<vector<double>> &matrix);
double calculate(double totalAmount);

int claimEntry(int claimNumber, const vector<vector<double>> &matrix) {
    double total = 0.0;
    for (const auto &row : matrix) {
      for (double val : row) {
        total += claimNumber * val;
      }
    }
    return (int)total;
  }
  

double process(const vector<double> &claimData, const vector<vector<double>> &matrix) {
  double total = 0.0;
  if (matrix.empty() || claimData.empty()) {
    return 0.0;
  }
  for (const auto &row : matrix) {
    for (double val : row) {
      total += val * claimData[0];
    }
    // Assuming each row corresponds to a claim number, and each value in the row is multiplied by the corresponding claimData element
  }
  return total;
  }
  

double calculate(double totalAmount) {
  return totalAmount;
  }

