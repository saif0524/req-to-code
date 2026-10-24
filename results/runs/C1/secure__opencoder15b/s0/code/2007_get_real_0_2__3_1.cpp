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

get_real_data(std::string university_name);

std::string get_real_data(std::string university_name) {
   // Construct the API URL with the university_name
   std::string url = "https://api.getreal.com/universities/" + university_name + "/courses";\n\n// Make a GET request to the API\nstd::string response = http_get_request(url);

   // Parse the JSON response and extract the relevant data
   // This is a simplified example and may not work for all universities
   nlohmann::json json_response = nlohmann::json::parse(response);

   // Extract the relevant data
   std::string courses = json_response.at("courses");

   // Return the courses data
   return courses;
}

