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

int readIntFromStream(int& int_val, const std::string& stream);
int writeIntToStream(int int_val, const std::string& stream);
std::string readStringFromStream(const std::string& stream);
std::string writeStringToStream(const std::string& stream);
std::string readFileFromStream(const std::string& stream, std::string& file_name);

std::string writeIntToStream(int int_val, const std::string& stream) 
    { 
        std::string s = std::to_string(int_val); 
        return writeStringToStream(s, stream); 
    }

std::string writeStringToStream(const std::string& stream) \
    { \\n        if (stream.empty() || stream == nullptr) \\n        { \\n            throw std::runtime_error("Stream cannot be null or empty."); \\n        } \\n        stream->write(str); \\n        return str; \\n    }

