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

int writeIntToStream(int int_val, const std::string& stream);
std::string readStringFromStream(const std::string& stream);
std::string writeStringToStream(const std::string& stream);
std::string readFileFromStream(const std::string& stream, std::string& file_name);

int writeIntToStream(int int_val, const std::string& stream) {
  if (stream.empty()) { // Check if stream is null or empty
   throw std::runtime_error(

std::string readStringFromStream(const std::string& stream) 
 
 // Check if the stream is null or empty 
 if (stream.empty()) 
 
 throw std::runtime_error(

std::string writeStringToStream(const std::string& stream) \
    { \\n        if (stream.empty() || stream == nullptr) \\n        { \\n            throw std::runtime_error("Stream cannot be null or empty."); \\n        } \\n        stream->write(str); \\n        return str; \\n    }

std::string readStringFromStream(const std::string& stream) {
  if (stream.empty()) {
    throw std::runtime_error(

