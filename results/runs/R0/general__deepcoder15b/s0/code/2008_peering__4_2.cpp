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

int calculateTotalDataLength(const message& m);
size_t processMessages(const vector<message>& messages);
string handleFTPRequest(const string& path);
double calculateAverageDataLength(const int64_t* lengths);

int calculateTotalDataLength(const message& m) {
    return m.data;
}

size_t processMessages(const vector<Message>& messages) {
    size_t count = 0;
    for (const Message& m : messages) {
        count++;
    }
    return count;
    }

Processed FTP request with the given path

double calculateAverageDataLength(const int64_t* lengths) 
    { 
        if (lengths.empty()) 
        { 
            return 0.0; 
        } 
        int64_t sum = 0; 
        for (int64_t len : lengths) 
        { 
            sum += len; 
        } 
        return static_cast<double>(sum) / lengths.size(); 
    },
    

