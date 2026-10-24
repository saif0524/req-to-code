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

int64_t total_time, int64_t hit_count, int64_t total_time_per_hit;

struct JSON {
    JSON() : total_time(0), hit_count(0), average_time_per_hit(0) {}
    int64_t total_time;
    int64_t hit_count;
    int64_t average_time_per_hit;
};

track_hits(int64_t timestamp, int64_t duration);
evaluate_hits();
get_content_changes();

int64_t track_hits(int64_t timestamp, int64_t duration) {
    // Calculate the total time spent on the website
    int64_t total_time = timestamp + duration;

    // Return the total time spent on the website in JSON format
    return {"total_time": total_time};
}

int64_t evaluate_hits() {
     int64_t total_time = timestamp + duration;
     int64_t hit_count = 0;
     int64_t total_time_per_hit = 0;

     // Evaluate the hits and time spent on the website
     for (int64_t time : times) {
         if (time > 300) {
             hit_count++;
             total_time_per_hit += time;
         }
     }

     // Calculate the average time spent on the website per hit
     if (hit_count > 0) {
         total_time_per_hit /= hit_count;
     }

     // Return the total time spent on the website and the hit count in JSON format
     return {"total_time": total_time, "hit_count": hit_count, "average_time_per_hit": total_time_per_hit};
}

int64_t get_content_changes() {
     int64_t total_time = timestamp + duration;
     int64_t hit_count = 0;
     int64_t total_time_per_hit = 0;

     // Evaluate the hits and time spent on the website
     for (int64_t time : times) {
         if (time > 300) {
             hit_count++;
             total_time_per_hit += time;
         }
     }

     // Calculate the average time spent on the website per hit
     if (hit_count > 0) {
         total_time_per_hit /= hit_count;
     }

     // Return the total time spent on the website and the hit count in JSON format
     return {"total_time": total_time, "hit_count": hit_count, "average_time_per_hit": total_time_per_hit};
}

