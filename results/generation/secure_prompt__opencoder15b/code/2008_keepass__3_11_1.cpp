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

void modifyEntry(EntryData& entryData, EntryData& originalEntryData);
void saveEntry(EntryData& entryData);
EntryData getEntryData(Entry& entry);
EntryData getOriginalEntryData(Entry& entry);
EntryData getEntryDataFromUI(Entry& entry);

void modifyEntry(EntryData& entryData, EntryData& originalEntryData) {
  // Modifies the entry data with the user's input.
  // ...
}

void saveEntry(EntryData& entryData) {
   // Modifies the entry data with the user's input.
   // ...
   // Saves the modified entry data to the database.
}

EntryData getEntryData(Entry& entry) {
    // Retrieve the entry data from the database.
    // ...
    // Return the entry data as a JSON object.
    return entryData;
}

EntryData getOriginalEntryData(Entry& entry) {
    // Retrieve the original entry data from the database.
    // ...
    // Return the original entry data as a JSON object.
    return entryData;
}

EntryData getEntryDataFromUI(Entry& entry) {
    // Retrieve the entry data from the user interface.
    // ...
    // Return the entry data as a JSON object.
    return entryData;
}

