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

using std::ifstream; using std::string; using std::vector; using std::getline;

void get_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);
bool validate_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);
void save_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);
std::vector<std::string> get_salesman_list();
void update_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);

void get_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  std::cout << "Enter salesman code: ";
  std::cin >> salesman_code;
  std::cout << "Enter name: ";
  std::cin >> name;
  std::cout << "Enter date of birth: ";
  std::cin >> dob;
  std::cout << "Enter age: ";
  std::cin >> age;
  std::cout << "Enter gender: ";
  std::cin >> gender;
  std::cout << "Enter communication address: ";
  std::cin >> communication_address;
  std::cout << "Enter contact number: ";
  std::cin >> contact_no;
  std::cout << "Enter email ID: ";
  std::cin >> email_id;
  std::cout << "Enter sales team: ";
  std::cin >> sales_team;
}

bool validate_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  if (salesman_code.empty() || name.empty() || dob.empty() || age < 0 || gender.empty() || communication_address.empty() || contact_no.empty() || email_id.empty() || sales_team.empty()) {
    return false;
  }
  return true;
}

void save_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  std::ofstream file("salesmen.txt", std::ios::app);
  if (!file.is_open()) {
    return; // Return if the file does not exist
  }
  file << salesman_code << ',' << name << ',' << dob << ',' << age << ',' << gender << ',' << communication_address << ',' << contact_no << ',' << email_id << ',' << sales_team << '
';
  file.close();
  std::cout << "Salesman details saved successfully.";
}

using namespace std;

std::vector<std::string> get_salesman_list() {
  std::vector<std::string> salesmen;
  std::ifstream file("salesmen.txt");
  if (!file.is_open()) {
    return {}; // Return an empty list if the file does not exist
  }
  std::string line;
  while (std::getline(file, line)) {
    salesmen.push_back(line);
  }
  file.close();
  return salesmen;
}

void update_salesman_details(std::string& new_salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  std::cout << "Enter new salesman code: ";
  std::cin >> new_salesman_code;

  if (validate_salesman_details(name, dob, age, gender, communication_address, contact_no, email_id, sales_team)) {
    save_salesman_details(new_salesman_code, name, dob, age, gender, communication_address, contact_no, email_id, sales_team);
    std::cout << "Salesman details updated successfully.";
  } else {
    std::cout << "Invalid salesman details. Details not updated.";
  }
}

