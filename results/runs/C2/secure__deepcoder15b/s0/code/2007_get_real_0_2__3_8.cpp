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

double radius -> double;
double base, double height -> double;
double length, double width -> double;
double radius -> double;
int sides, double side -> double;

double radius(double r) { if (r <= 0) return 0.0; return (4.0 / 3.0) * M_PI * r * r * r; }

double area(double base, double height) { return (base * height) / 2.0; }

using namespace std;

double radius(double r) { if (r <= 0) return 0.0; return (4.0 / 3.0) * M_PI * r * r * r; }

double area(double base, double height) { return (base * height) / 2.0; }

double length, width;

int sides, double side;

// Get inputs
int main() {
    // Read length and width
    double length_input, width_input;
    // Read base and height
    double base_input, height_input;
    // Read sides and side length
    int sides_input;
    double side_input;
    // Read and process inputs
    while (true) {
        // Read line
        std::getline(std::cin, length_input, 1);
        // Read line
        std::getline(std::cin, width_input, 1);
        // Read line
        std::getline(std::cin, base_input, 1);
        // Read line
        std::getline(std::cin, height_input, 1);
        // Read line
        std::getline(std::cin, sides_input, 1);
        // Read line
        std::getline(std::cin, side_input, 1);
        // Check inputs
        if (side_input <= 0 || sides_input <= 1) {
            std::cout << "Invalid input" << std::endl;
        } else {
            // Calculate area for the given shape
            if (sides_input == 3) { // Triangle
                area(base_input, height_input);
            } else if (sides_input == 4) { // Square
                area(base_input, base_input);
            }
            // Or handle other shapes as needed
        }
    }

    // Output the calculated area
    return 0;
}

double radius(double r) { return (4.0 / 3.0) * M_PI * r * r * r; }

using namespace std; // to simplify the code

double radius(double r) { 
    if (r <= 0) return 0.0; 
    return (4.0 / 3.0) * M_PI * r * r * r; 
}

double area(double base, double height) { 
    return (base * height) / 2.0; 
}

double length, width; // Assuming length and width are read from input
int sides, double side; // Assuming sides and side are read from input

// Get inputs
while (true) {
    std::getline(std::cin, length_input, 1);
    std::getline(std::cin, width_input, 1);
    std::getline(std::cin, base_input, 1);
    std::getline(std::cin, height_input, 1);
    std::getline(std::cin, sides_input, 1);
    std::getline(std::cin, side_input, 1);
    // Check inputs
    if (side_input <= 0 || sides_input <= 1) {
        std::cout << 

