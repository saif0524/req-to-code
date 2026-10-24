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

string generateHelpLinks(int userId);
string displayHelpLinks(string link, int userX, int userY);
vector<string> createHelpTopics(const string& manualContent, vector<string>& topics);
void handleClick(string linkId, int userX, int userY);
string generateManualContent(const string& manualContent, vector<string>& topics);

string generateHelpLinks(int userId) {
    string linkText = "Help link for user " + to_string(userId) + ";\nstring linkContent = generateManualContent(linkText, vector<string>{"manual content"});\nreturn "{{
    " + linkContent + \n" }} with reasoning: 1 to 3 steps explaining how and why you implement it this way, and " + linkText + \n"code": the complete function definition only.\n}";
    }
    }

The displayHelpLinks function will call generateHelpLinks to get the formatted string, then split it into reasoning and code parts to create a JSON object.

string createHelpTopics(const string& manualContent, vector<string>& topics) {
    vector<string> helpTopics;
    for (string topic : topics) {
        string linkText = "Help link for user " + to_string(1) + ";\nstring linkContent = generateManualContent(linkText, vector<string>{"reasoning": "3 to 6 short steps explaining how and why you implement it this way, "code": the complete function definition only.
    });
        string reasoning, code;
        string::stream linkContentStream = linkContent;
        size_t pos = 0;
        while (linkContentStream>>= 

The handleClick function will extract the linkId, generate the link content, split it, generate the user's link content, and combine everything.

string generateManualContent(const string& manualContent, vector<string>& topics) \ 
    // Generate content for each Help topic.\n    // The function returns a JSON object with 'reasoning' and 'code' fields.\n    // 'reasoning' contains the steps, 'code' contains the complete function definition.\n    // Example steps:\n    // 1. Extract manual content.\n    // 2. Create reasoning steps.\n    // 3. Write the code.\n    return JSON.stringify({
"reasoning": {
"step 1 explanation here..."\n            "step 2 explanation here..."\n            "... more steps ..."\n        },\n        "code": "// Your function code here..."\n    });\n}

