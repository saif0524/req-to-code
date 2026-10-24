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

void generateCollegeJobPages();
void generateWomenInComputingPages();
void generateResourcesPages();
void generateArticlesPages();
void generateHighSchoolCoursesPages();

void generateCollegeJobPages() {
  std::string html = "<html><head><title>Exploring College Jobs & Money</title></head><body>\n";
  html += "<h1>Exploring College Jobs & Money</h1>\n";
  html += "<p>Discover the latest job opportunities and financial information for college students.</p>\n";
  html += "<ul>\n";
  html += "  <li>Job listings</li>\n";
  html += "  <li>Financial aid information</li>\n";
  html += "  <li>College scholarship opportunities</li>\n";
  html += "</ul>\n";
  html += "</body></html>";
  std::cout << html << std::endl;
}

void generateWomenInComputingPages() {
  std::string html = "<html><head><title>Women in Computing</title></head><body>\n";
  html += "<h1>Women in Computing</h1>\n";
  html += "<p>Explore the achievements and challenges faced by women in the field of computing.</p>\n";
  html += "<ul>\n";
  html += "  <li>Historical milestones</li>\n";
  html += "  <li>Current contributions</li>\n";
  html += "  <li>Opportunities for advancement</li>\n";
  html += "</ul>\n";
  html += "</body></html>";
  std::cout << html << std::endl;
}

void generateResourcesPages() {
  std::string html = "<html><head><title>Resources</title></head><body>\n";
  html += "<h1>Resources</h1>\n";
  html += "<p>Explore various resources to support your learning and career in computing.</p>\n";
  html += "<ul>\n";
  html += "  <li><a href="college-jobs.html">Exploring College Jobs & Money</a></li>\n";
  html += "  <li><a href="women-in-computing.html">Women in Computing</a></li>\n";
  html += "  <li><a href="articles.html">Articles</a></li>\n";
  html += "  <li><a href="high-school-courses.html">High School Courses</a></li>\n";
  html += "</ul>\n";
  html += "</body></html>";
  std::cout << html << std::endl;
}

void generateArticlesPages() {
  std::vector<std::string> articles = {
    "<h1>Article 1</h1><p>This is the first article.</p>",
    "<h1>Article 2</h1><p>This is the second article.</p>",
    "<h1>Article 3</h1><p>This is the third article.</p>"
  };

  std::string html = "<html><head><title>Articles</title></head><body>\n";
  html += "<h1>Articles</h1>\n";
  html += "<ul>\n";

  for (const auto& article : articles) {
    html += "  <li>" + article + "</li>\n";
  }

  html += "</ul>\n";
  html += "</body></html>";

  std::cout << html << std::endl;
}

void generateHighSchoolCoursesPages() {
  std::string html = "<html><head><title>High School Courses</title></head><body>\n";
  html += "<h1>High School Courses</h1>\n";
  html += "</body></html>";
  std::cout << html << std::endl;
}

