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

void get_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);
void save_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);
std::vector<std::string> get_salesman_list();
void update_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team);
void delete_salesman(std::string& salesman_code);

void get_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  // Prompt the user to enter the details of a salesman
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

void save_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  std::ofstream file("salesmen.txt", std::ios::app);
  if (!file.is_open()) {
    return;
  }
  file << salesman_code << ',' << name << ',' << dob << ',' << age << ',' << gender << ',' << communication_address << ',' << contact_no << ',' << email_id << ',' << sales_team << std::endl;
  file.close();
  return;
}

std::vector<std::string> get_salesman_list() {

  std::ifstream file("salesmen.txt", std::ios::in);
  if (!file.is_open()) {
    return;
  }

  std::vector<std::string> salesman_list;
  std::string line;
  while (std::getline(file, line)) {
    salesman_list.push_back(line);
  }

  file.close();
  return salesman_list;
}

void update_salesman_details(std::string& salesman_code, std::string& name, std::string& dob, int& age, std::string& gender, std::string& communication_address, std::string& contact_no, std::string& email_id, std::string& sales_team) {
  std::ofstream file("salesmen.txt", std::ios::app);
  if (!file.is_open()) {
    return;
  }
  file << salesman_code << ',' << name << ',' << dob << ',' << age << ',' << gender << ',' << communication_address << ',' << contact_no << ',' << email_id << ',' << sales_team << std::endl;
  file.close();
  return;
}

void delete_salesman(std::string& salesman_code) {
  std::ifstream file("salesmen.txt", std::ios::in);
  if (!file.is_open()) {
    return;
  }
  std::ofstream output_file("temp_salesmen.txt", std::ios::out);
  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string code;
    iss >> code;
    if (code != salesman_code) {
      output_file << line << std::endl;
    }
  }
  file.close();
  output_file.close();
  std::remove("salesmen.txt");
  rename("temp_salesmen.txt", "salesmen.txt");
}

