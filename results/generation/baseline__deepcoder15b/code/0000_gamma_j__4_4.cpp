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

void send_system_query(const string& query_details);
customer get_customer_info(const customer& customer);
void update_order_status(int tracking_number, const customer& customer);
void send_confirmation(const customer& customer);

void send_system_query(const string& query_details) {
    string message = "System Administrator"
    ;
    message << "Subject: Technical Query"
    ;
    message << "Content: " << query_details << ""
    ;
    return message;
    }

struct CustomerData {
    string name;
    string email;
    int phone;
    string address;
}

CustomerInfo get_customer_info(const customer& customer) {
    CustomerData info;
    info.name = customer.name;
    info.email = customer.email;
    info.phone = customer.phone;
    info.address = customer.address;
    return JSON::fromJson({"customer_info": info });
}

void update_order_status(int tracking_number, const customer& customer) {
    string message = "System administrator"
    ;
    message << "Subject: Order status"
    ;
    message << "Content: Tracking number: " << tracking_number << 
    ;
    message << "Customer: " << customer.name << 
    ;
    message << "Email"
    ;
    message << "From: System Administrator"
    ;
    message << "To: " << customer.email << 
    ;
    message << "Reason: Updating order status"
    ;
    return send_system_query(message);
  },
  

void send_confirmation(const customer& customer) {
  string message = "System Administrator\nSubject: Order Confirmation\nContent: Order confirmed successfully. Tracking number: " + tracking_number + 
Customer: " + customer.name + \nEmail: " + customer.email + 
From: System Administrator\nTo: " + customer.email + \nReason: Order confirmation\n";
  return send_system_query(message);
  }

