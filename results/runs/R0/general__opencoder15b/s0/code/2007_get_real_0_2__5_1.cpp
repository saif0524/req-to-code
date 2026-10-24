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

double getRealResponseTime();

double getRealResponseTime() {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::packaged_task<double()> task([](){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0.0;
  });

  std::future<double> result = task.get_future();

  start = std::chrono::system_clock::now();
  std::thread t([&](){
    task();
  });

  end = std::chrono::system_clock::now();

  t.join();

  return std::chrono::duration<double>(end-start).count();
}

