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

void selectEntry(Entry& entry);
void editEntry(Entry& entry);
void updateEntry(Entry& entry);
void saveEntry(Entry& entry);
void displayEntryForm(Entry& entry);

void selectEntry() { return; }

void editEntry(Entry& entry) { return; }

void updateEntry(Entry& entry) { entry.update(); saveEntry(entry); }

void saveEntry(Entry& entry) { entry.save(); }

void displayEntryForm(Entry& entry) { return; }

