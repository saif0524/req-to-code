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

struct Order { std::string status; }; bool isValidOrder(const Order& order) { return order.status == "confirmed" || order.status == "updated"; } void sendConfirmationEmail(const Order& order) { if (!isValidOrder(order)) { return "Invalid order"; } order.setStatus("confirmed"); sendEmail(order); }

void confirmOrder(const Order& order);
void updateOrder(const Order& order);
void sendConfirmationEmail(const Order& order);

void confirmOrder(const Order& order) { if (!isValidOrder(order)) { return "Invalid order"; } order.setStatus("confirmed"); sendConfirmationEmail(order); }

struct Order { std::string status; }; bool isValidOrder(const Order& order) { return order.status == "confirmed" || order.status == "updated"; } void sendConfirmationEmail(const Order& order) { if (!isValidOrder(order)) { return "Invalid order"; } order.setStatus("confirmed"); sendEmail(order); }

void sendConfirmationEmail(const Order& order) { using namespace std; if (!isValidOrder(order)) { return "Invalid order"; } order.setStatus("confirmed"); sendEmail(order); }

