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

void getArticlesPage() {
    // Create a JSON object with the URL of the articles page and a short description
    Json::Value articlesPage;
    articlesPage[

