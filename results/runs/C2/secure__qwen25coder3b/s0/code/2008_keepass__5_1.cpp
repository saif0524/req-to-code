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
  HANDLE clipboardHandle = OpenClipboard(NULL);
  if (!clipboardHandle) return;
  EmptyClipboard();
  if (!SetClipboardData(CF_TEXT, (HANDLE)password.c_str())) return;
  CloseClipboard();

  std::thread timer([clipboardHandle]() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    CloseClipboard();
  });
  timer.detach();
}

bool checkClipboard(const std::string& password) {
  HANDLE clipboardHandle = OpenClipboard(NULL);
  if (!clipboardHandle) return false;
  HANDLE clipboardData = GetClipboardData(CF_TEXT);
  if (clipboardData == NULL) return false;
  std::string clipboardText(reinterpret_cast<const char*>(GlobalLock(clipboardData)), GlobalSize(clipboardData));
  GlobalUnlock(clipboardData);
  CloseClipboard();
  return clipboardText == password;
}

class KeePassClipboardManager {
private:
  std::string password;

public:
  void copyPassword(const std::string& password) {
    HANDLE clipboardHandle = OpenClipboard(NULL);
    if (!clipboardHandle) return;
    EmptyClipboard();
    if (!SetClipboardData(CF_TEXT, (HANDLE)password.c_str())) return;
    CloseClipboard();

    std::thread timer([clipboardHandle]() {
      std::this_thread::sleep_for(std::chrono::seconds(10));
      CloseClipboard();
    });
    timer.detach();
  }

  bool checkClipboard(const std::string& password) {
    HANDLE clipboardHandle = OpenClipboard(NULL);
    if (!clipboardHandle) return false;
    HANDLE clipboardData = GetClipboardData(CF_TEXT);
    if (clipboardData == NULL) return false;
    std::string clipboardText(reinterpret_cast<const char*>(GlobalLock(clipboardData)), GlobalSize(clipboardData));
    GlobalUnlock(clipboardData);
    CloseClipboard();
    return clipboardText == password;
  }

  void deletePassword() {
    password = "";
  }

  void handleClipboardChange() {
    static std::thread clipboardMonitor([clipboardHandle]() {
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
};

void handleClipboardChange() {
  using namespace std;
  static std::thread clipboardMonitor([clipboardHandle]() {
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
  std::unique_ptr<std::thread> timer(new std::thread([clipboardHandle]() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    clipboardHandle.reset();
  }));
  timer->detach();
}

