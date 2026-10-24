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

void getRealHomePage();
std::string getCollegeJobsPage();
std::string getMoneyRealPeoplePage();
std::string getWomenInComputingPage();
std::string getArticlesPage();

std::string getRealHomePage() {
    // Return the HTML content of the Get Real home page.
    return "<html><body><h1>Get Real</h1></body></html>";
}

std::string getCollegeJobsPage() {
   // Return the HTML content of the College Jobs page.
   return "<html><body><h1>College Jobs</h1></body></html>";
}

std::string getMoneyRealPeoplePage() {
    // Return the HTML content of the Money Real People page.
    return "<html><body><h1>Money Real People</h1></body></html>";
}

std::string getWomenInComputingPage() {
    // Return the HTML content of the Women in Computing page.
    return "<html><body><h1>Women in Computing</h1></body></html>";
}

std::string getArticlesPage() {
    // Return the HTML content of the Articles page.
    return "<html><body><h1>Articles</h1></body></html>";
}

