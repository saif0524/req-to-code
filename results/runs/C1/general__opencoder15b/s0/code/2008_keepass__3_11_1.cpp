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

void modifyEntry(EntryData& entryData);
void saveChanges(EntryData& entryData);
void cancelChanges(EntryData& entryData);
void updateEntry(EntryData& entryData);
EntryData getEntryData();

void modifyEntry(EntryData& entryData) {
  // Open the form for modifying an entry
  // Allow the user to change the context of the entry
  // Save the changes made to the entry context in the form
  saveChanges(entryData);
  // Close the form without saving any changes
  cancelChanges(entryData);
  // Update the entry context with the new changes made in the form
  updateEntry(entryData);
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why I implement it this way, and 'code': the complete function definition only
}

void cancelChanges(EntryData& entryData) {
   // Close the form without saving any changes
   saveChanges(entryData);
   // Close the form without saving any changes
   cancelChanges(entryData);
   // Update the entry context with the new changes made in the form
   updateEntry(entryData);
}

void updateEntry(EntryData& entryData) {
    // Update the entry context with the new changes made in the form
    // Your implementation here
    saveChanges(entryData);
    // Your implementation here
    cancelChanges(entryData);
    // Your implementation here
    updateEntry(entryData);
}

