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

string getPageContent(string page);
string handlePopup(string page);
vector<string> displayHelpLinks(const vector<string>& links);
string handleHelpLink(string link);

string getPageContent(string page) {
  string currentPageContent;
  // Initialize the current page content
  currentPageContent = 0;
  // Loop through all possible pages to find the current active page
  for (string page : allPages) {
    if (page == page) { // Assuming page is the current active page
      currentPageContent = getPageContent(page);
      break;
    }
  }
  return currentPageContent;
  }
  "reasoning": "The function getPageContent is designed to retrieve the content of the current page by checking all possible pages until it finds the one that is currently active. This ensures that the correct content is returned based on the system's state.

string handlePopup(string page) {
  string content = getPageContent(page);
  return content;
  }
  

vector<string> displayHelpLinks(const vector<string>& links) {
  vector<string> result;
  for (const string& link : links) {
    string text = getPageContent(link);
    result.push_back(text);
  }
  return result;
  }
  

string handleHelpLink(string link) {
  return handlePopup(link);
}

