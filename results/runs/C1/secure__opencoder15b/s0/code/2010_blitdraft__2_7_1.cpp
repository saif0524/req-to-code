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

std::string generateHelpLink(std::string topic);
void displayHelpWindow(std::string topic);
void updateHelpSystem(std::string topic);
std::string getHelpContent(std::string topic);

std::string generateHelpLink(std::string topic) {
   std::string link = "<a href=\"help/\" + topic + \">\";\nreturn link;\n}

void displayHelpWindow(std::string topic) {
    std::string link = generateHelpLink(topic);
    std::string content = getHelpContent(topic);
    std::string json = "{\"link\":\"" + link + \"\",\"content\":\"" + content + \"\"}";
    return json;
}

void updateHelpSystem(std::string topic) {
    std::string link = generateHelpLink(topic);
    std::string content = getHelpContent(topic);
    std::string json = "{" + link + "," + content + "}";
    return json;
}

std::string getHelpContent(std::string topic) {
    std::string content = "";
    // Add your implementation here.
    return content;
}

