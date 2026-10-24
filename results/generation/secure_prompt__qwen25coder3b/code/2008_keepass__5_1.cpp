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

void copyPassword(const std::string& password);
bool checkClipboard(const std::string& password);
void deletePassword();
void handleClipboardChange();
void startTimer();

void copyPassword(const std::string& password) {
  std::unique_ptr<HANDLE, decltype(&CloseClipboard)> clipboardHandle(CloseClipboard, [](HANDLE h) { if (h != INVALID_HANDLE_VALUE) CloseClipboard(h); });
  if (!OpenClipboard(NULL)) return;
  if (!EmptyClipboard()) return;
  if (!SetClipboardData(CF_TEXT, (HANDLE)password.c_str())) return;
  clipboardHandle.reset();

  std::thread timer([clipboardHandle]() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    clipboardHandle.reset();
  });
  timer.detach();
}

bool checkClipboard(const std::string& password) {
  std::unique_ptr<HANDLE, decltype(&CloseClipboard)> clipboardHandle(CloseClipboard, [](HANDLE h) { if (h != INVALID_HANDLE_VALUE) CloseClipboard(h); });
  if (!OpenClipboard(NULL)) return false;
  HANDLE clipboardData = GetClipboardData(CF_TEXT);
  if (clipboardData == NULL) return false;
  std::string clipboardText(reinterpret_cast<const char*>(GlobalLock(clipboardData)), GlobalSize(clipboardData));
  GlobalUnlock(clipboardData);
  CloseClipboard();
  return clipboardText == password;
}

void deletePassword() { password = ""; }

void handleClipboardChange() {
  std::thread clipboardMonitor([clipboardHandle]() {
    while (true) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      if (checkClipboard(password)) {
        deletePassword();
      }
    }
  });
  clipboardMonitor.detach();
}

void startTimer() {
  std::thread timer([clipboardHandle]() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    clipboardHandle.reset();
  });
  timer.detach();
}

