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

get_real_pages_sections();

std::string get_real_pages_sections() {
  std::string json = R"json(  {\n"ACM": "https://acm.org",
    "IEEE": "https://ieeexplore.ieee.org/",\n"SIGGRAPH": "https://www.siggraph.org/",\n"Sub_Groups": [\n"https://www.siggraph.org/",
      "https://www.sciencedirect.com/",\n"https://www.nature.com/",\n"https://www.frontiersin.org/",\n"https://www.tandfonline.com/"  
    ]
  })json";\nreturn json;\n}

