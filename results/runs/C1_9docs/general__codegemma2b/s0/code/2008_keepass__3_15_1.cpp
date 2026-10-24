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

void auto_type_sequence(const KeePass::Database& db, KeePass::Entry& entry);
void auto_type_sequence_with_context_menu(KeePass::Entry& entry);
void auto_type_sequence_with_ctrl_v(KeePass::Entry& entry);
void auto_type_sequence_with_system_hotkey(KeePass::Entry& entry);

