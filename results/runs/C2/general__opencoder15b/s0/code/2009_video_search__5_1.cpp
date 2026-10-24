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

std::chrono::duration<double> elapsed;

bool checkQueryTime(std::string query);
bool sendHyperlink(std::string url);
bool checkLoadingTime();
bool checkZeroSeeds(std::vector<TorrentResult> results);
bool checkSortingTime();

bool checkQueryTime(std::string query) { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 5.0; 
 } 

bool checkLoadingTime() { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 10.0; 
 } 

bool checkZeroSeeds(std::vector<TorrentResult> results) { 
     for (const auto& torrent : results) { 
         if (torrent.seeds == 0) { 
             return false; 
         } 
     } 
     return true; 
 } 

bool checkSortingTime() { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 0.1; 
 } 

bool sendHyperlink(std::string url) { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 1.0; 
 }

bool checkQueryTime(std::string query) { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 5.0; 
 } 

bool checkLoadingTime() { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 10.0; 
 } 

bool checkZeroSeeds(std::vector<TorrentResult> results) { 
     for (const auto& torrent : results) { 
         if (torrent.seeds == 0) { 
             return false; 
         } 
     } 
     return true; 
 } 

bool checkSortingTime() { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 0.1; 
 } 

bool sendHyperlink(std::string url) { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 1.0; 
 }

bool checkLoadingTime() { 
    auto start = std::chrono::high_resolution_clock::now(); 
    // Your code here 
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start; 
    return elapsed.count() < 10.0; 
}

template<typename T>
bool checkZeroSeeds(std::vector<T> results) {
    for (const auto& torrent : results) {
        if (torrent.seeds == 0) {
            return false;
        }
    }
    return true;
}

bool checkSortingTime() { 
     auto start = std::chrono::high_resolution_clock::now(); 
     // Your code here 
     auto end = std::chrono::high_resolution_clock::now(); 
     std::chrono::duration<double> elapsed = end - start; 
     return elapsed.count() < 0.1; 
 }

