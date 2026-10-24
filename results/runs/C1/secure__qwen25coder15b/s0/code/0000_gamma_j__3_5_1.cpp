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

void displayWelcomeMessage();
void renderNavigationMenu();
void handleUserInput();
void updateUI();

void displayWelcomeMessage() {
  std::cout << "Welcome to the Gamma-J Web Store!" << std::endl;
}

void renderNavigationMenu() {
  std::cout << "Welcome to the Gamma-J Web Store!" << std::endl;
  std::cout << "Main Menu:\n";
  std::cout << "1. Products\n";
  std::cout << "2. Cart\n";
  std::cout << "3. Checkout\n";
}

void handleUserInput() {
  std::string userInput;
  std::cout << "Enter your action: ";
  std::cin >> userInput;

  switch (userInput) {
    case "1":
      updateUI("Products");
      displayProducts();
      break;
    case "2":
      updateUI("Cart");
      addToCart();
      break;
    case "3":
      updateUI("Checkout");
      checkout();
      break;
    default:
      std::cout << "Invalid action. Please try again." << std::endl;
  }
}

void updateUI(const std::string& currentState) {
  if (currentState == "Products") {
    displayProducts();
  } else if (currentState == "Cart") {
    addToCart();
  } else if (currentState == "Checkout") {
    checkout();
  }
}

