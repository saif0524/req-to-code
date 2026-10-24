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

int select_report_type(int selected_type);
vector<Event> process_events(const vector<Event>& events);
void write_to_file(const vector<Event>& events, const string& path);
vector<int> get_available_months();
int select_month(const vector<int>& months, int month);

int select_report_type(int selected_type) {
    switch (selected_type) {
        case 3: return 3; // Operational history report
        case 4: return 4; //Statistical summary report
        case 5: return 5; //Operational history report
        case 6: return 6; //Statistical summary report
        default: return -1; // handle unexpected input
    }
    }

vector<int> process_events(const vector<Event>& events) {
    int selected_type = select_report_type(selected_type);
    vector<int> months;
    if (selected_type == 4) {
        months = get_available_months();
    }
    vector<vector<Event>> processed_events;
    vector<int> result;
    if (selected_type == 3) {
        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return compare_date(a, b);
        });
        processed_events = {events};
    } else if (selected_type == 4) {
        for (int m : months) {
            sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
                return compare_date(a, b);
            });
            processed_events.push_back(events);
            events.clear();
        }
        processed_events = {processed_events};
    }
    return processed_events;
    }

void write_to_file(const vector<Event>& events, const string& path) {
    // Open the file
    std::string temp = path;
    while (temp != 

vector<int> get_available_months() {
    return {1,2,3,4,5,6,7,8,9,10,11,12};
    }

int select_month(const vector<int>& months, int month) { 
  if (month >= 3 && month <= 6) { 
    return month; 
  } else { 
    return -1; 
  } 
 }

