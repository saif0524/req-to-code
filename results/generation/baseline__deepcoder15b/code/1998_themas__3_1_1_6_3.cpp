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

std::vector<int> read_data(const std::string &file_path)"
    std::vector<int> read_data(const std::string &file_path) {
    std::vector<int> data;
    std::fileread(data, std::endvector, std:: streams::text, file_path);
    return data;
    };
std::pair<int, int> get_min_max(std::vector<int> data)"
    std::pair<int, int> get_min_max(std::vector<int> data) {
    int min = data[0];
    int max = data[1];
    return {min, max};
    };
std::pair<int, int> valid_range(std::vector<int> data)"
    std::pair<int, int> valid_range(std::vector<int> data) {
    int min = data[0];
    int max = data[1];
    return {min, max};
    };

std::vector<int> read_data(const std::string &file_path) {
    std::vector<int> data;
    std::fileread(data, std::endvector, std:: streams::text, file_path);
    return data;
    }

pair<int, int> get_min_max(std::vector<int> data) {
    int size = data.size();
    if (size == 0) {
        return make_pair(0, 0);
    }
    int min_temp = data[0];
    int max_temp = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < min_temp) {
            min_temp = data[i];
        }
        if (data[i] > max_temp) {
            max_temp = data[i];
        }
    }
    return make_pair(min_temp, max_temp);
    }
    "reasoning": "The function get_min_max extracts the minimum and maximum temperatures from the data vector. It first checks if the data vector is empty and returns (0,0) if it is. Then, it initializes min_temp and max_temp with the first element of the data vector. It then iterates through the remaining elements to find the actual minimum and maximum temperatures, updating min_temp and max_temp accordingly. Finally, it returns the pair (min_temp, max_temp) which contains the extracted minimum and maximum temperatures.", "code": "pair<int, int> get_min_max(std::vector<int> data) {\nint size = data.size();\nif (size == 0) {\nreturn make_pair(0, 0);
    }
    int min_temp = data[0];
    int max_temp = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < min_temp) {
            min_temp = data[i];
        }
        if (data[i] > max_temp) {
            max_temp = data[i];
        }
    }
    return make_pair(min_temp, max_temp);
}
"reasoning": "The function get_min_max extracts the minimum and maximum temperatures from the data vector. It first checks if the data vector is empty and returns (0,0) if it is. Then, it initializes min_temp and max_temp with the first element of the data vector. It then iterates through the remaining elements to find the actual minimum and maximum temperatures, updating min_temp and max_temp accordingly. Finally, it returns the pair (min_temp, max_temp) which contains the extracted minimum and maximum temperatures.", 

pair<int, int> valid_range(std::vector<int> data) {
    int min = data[0];
    int max = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }
    return {min, max};
}

