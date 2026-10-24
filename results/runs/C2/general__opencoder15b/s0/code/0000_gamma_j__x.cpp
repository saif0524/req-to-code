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

void connectToWebOrder();
void placeOrder(Order order);
Order getOrderDetails(int orderId);
void updateInventory(Order order);
Customer getCustomerDetails(int customerId);

class Database {
    private:
        Connection* connection;

    public:
        Database() {
            connection = connectToDatabase();
        }

        void disconnect() {
            disconnectFromDatabase(connection);
        }

        Order getOrderDetails(int orderId) {
            Order order = getOrderFromDatabase(connection, orderId);
            updateInventory(order);
            return order;
        }

        void updateInventory(Order order) {
            Inventory inventory = getInventoryFromDatabase(connection);

            for (Item item : order.getItems()) {
                inventory[item.getId()] -= item.getQuantity();
            }

            updateInventoryInDatabase(connection, inventory);
        }

        Customer getCustomerDetails(int customerId) {
            Customer customer = getCustomerDetailsFromAccountSystem(connection, customerId);
            return customer;
        }
}

void placeOrder(Order order) {
   // Connect to the WebOrder database
   connectToWebOrder();

   // Place the order in the WebOrder database
   placeOrderInDatabase(order);

   // Update the inventory of the store with the order details
   updateInventory(order);
}

void getOrderDetails(int orderId) {
    // Connect to the WebOrder database
    connectToWebOrder();

    // Retrieve the order details from the WebOrder database
    Order order = getOrderFromDatabase(orderId);

    // Update the inventory of the store with the order details
    updateInventory(order);

    // Return the order details as a JSON object
    return order;
}

void updateInventory(Order order) {
    // Connect to the WebOrder database
    connectToWebOrder();

    // Retrieve the current inventory of the store
    Inventory inventory = getInventoryFromDatabase();

    // Iterate through the list of items in the order
    for (Item item : order.getItems()) {
        // Reduce the quantity of the item from the inventory
        inventory[item.getId()] -= item.getQuantity();
    }

    // Update the inventory of the store in the database
    updateInventoryInDatabase(inventory);
}

Customer getCustomerDetails(int customerId) {
    // Connect to the account system
    connectToAccountSystem();

    // Retrieve the customer details from the account system
    Customer customer = getCustomerDetailsFromAccountSystem(customerId);

    // Return the customer details as a JSON object
    return customer;
}

