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

void display_overview_page();
void load_help_topic(std::string topic_name);
std::string get_default_help_topic();

void display_overview_page() {
    // Load the overview page HTML content.
    std::string overview_page = load_html_content("overview.html");

    // Display the overview page.
    display_page(overview_page);
}

std::string load_help_topic(std::string topic_name) {
    std::string topic_page = load_html_content("help/" + topic_name + ".html");
    return topic_page;
}

std::string get_default_help_topic() {
   return "overview.html";
}

