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
void getCollegeJobsPage();
void getWomenInComputingPage();
void getRealPeoplePage();
void getArticlesPage();

std::string getRealHomePage() {
  std::string response = httpGet("https://getreal.website/");\nstd::string content = htmlDecode(response);\nstd::string json = htmlToJson(content);\nreturn json;
}

std::string getCollegeJobsPage() {
   std::string response = httpGet("https://getreal.website/jobs");\nstd::string content = htmlDecode(response);\nstd::string json = htmlToJson(content);\nreturn json;
}

std::string getWomenInComputingPage() {
    std::string response = httpGet("https://getreal.website/women-in-computing");\nstd::string content = htmlDecode(response);\nstd::string json = htmlToJson(content);\nreturn json;
}

std::string getRealPeoplePage() {
    std::string response = httpGet("https://getreal.website/real-people");\nstd::string content = htmlDecode(response);\nstd::string json = htmlToJson(content);\nreturn json;
}

std::string getArticlesPage() {
    std::string response = httpGet("https://getreal.website/articles");\nstd::string content = htmlDecode(response);\nstd::string json = htmlToJson(content);\nreturn json;
}

