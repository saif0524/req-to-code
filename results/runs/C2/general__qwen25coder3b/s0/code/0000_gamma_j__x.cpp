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

void connectToAccountSystem(AccountSystem& accountSystem);
void sendBillingInformation(const Order& order, AccountSystem& accountSystem);
void connectToInventoryManagement(InventoryManagement& inventoryManagement);
void sendOrderItems(const Order& order, InventoryManagement& inventoryManagement);
void loadPlugIns(PlugIns& plugIns);

void connectToAccountSystem(AccountSystem& accountSystem) { accountSystem.connect(); }

void sendBillingInformation(const Order& order, AccountSystem& accountSystem) { accountSystem.sendBilling(order); }

void connectToInventoryManagement(InventoryManagement& inventoryManagement) { inventoryManagement.connect(); return; }

void sendOrderItems(const Order& order, InventoryManagement& inventoryManagement) { inventoryManagement.sendOrderItems(order); }

void loadPlugIns(PlugIns& plugIns) { for (auto& plugin : plugIns) { plugin.load(); plugin.initialize(); } }

