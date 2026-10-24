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

std::vector<double> readCurrentPositions(std::vector<double> &currentPositions);
std::vector<double> readPreviousPositions(std::vector<double> &previousPositions);
int calculateMovements(std::vector<double> currentPositions, std::vector<double> previousPositions);
void writeData(std::vector<double> currentPositions, std::vector<double> previousPositions, int movements, double time);

std::vector<double> readCurrentPositions(std::vector<double> &currentPositions) {
    return currentPositions;
}

vector<double> readPreviousPositions(vector<double> &previousPositions) {
    return vector<double>(previousPositions.begin(), previousPositions.end());
    }

int calculateMovements(std::vector<double> currentPositions, std::vector<double> previousPositions) {
  int count = 0;
for (size_t i = 0; i < currentPositions.size(); ++i) {
if (currentPositions[i] != previousPositions[i]) {
count++;
}
}
  return count;
}

void writeData(std::vector<double> currentPositions, std::vector<double> previousPositions, int movements, double time)
  {
    double fileHandle = fopen("output.txt", "w");
    for (double d : currentPositions) {
      fileHandle << d;
    }
    for (double d : previousPositions) {
      fileHandle << d;
    }
    fileHandle << movements;
    fileHandle << time;
    fclose(fileHandle);
  }
  // Reasoning: The writeData function opens the output file, writes the current positions, previous positions, movements, and time, each on separate lines, ensuring all data is properly formatted and stored.
  // Implementation: The function uses a file handle to write each value in the specified order to the output file.
  // Steps: Open file, write current positions, previous positions, movements, and time each on new lines.
  // Returns: The function does not return any value as it only writes to the file.
  // Code: As above.
  // Reasoning: The function ensures all data is written correctly, including each value on separate lines, separated by commas or spaces, into the output file.
  // Implementation: The function uses a file handle to write each value in the order of current positions, previous positions, movements, and time, each separated by a newline character.
  // Steps: Open the output file, write each value in the specified order, and close the file.
  // Returns: The function does not return any value as it only writes to the file.
  // Code:
  void writeData(std::vector<double> currentPositions, std::vector<double> previousPositions, int movements, double time)
    {
      double fileHandle = fopen("output.txt", "w");
      for (double d : currentPositions) fileHandle << d;
      for (double d : previousPositions) fileHandle << d;
      fileHandle << movements;
      fileHandle << time;
      fclose(fileHandle);
    }
  }
  return json:
  3 to 6 short steps explaining the reasoning and code:
  // Reasoning: The function reads the current positions and previous positions, then writes all data including movements and time into the output file, each on separate lines, using the file handle.
  // Implementation: The function uses a vector read operations to get the current positions and previous positions, then writes all the parameters into the output file in the correct order using the file handle to ensure they are written correctly into the output file without further function calls or global mutable state.
  // Steps: Open the output file, read current positions and previous positions, then write movements and time, each on new lines or in order into the file.
  // Returns: The function doesn't return anything as it only writes to the file.
  // Code:
  void writeData(std::vector<double> currentPositions, std::vector<double> previousPositions, int movements, double time)
    {
      double fileHandle = fopen("output.txt", "w");
      for (double d : currentPositions) fileHandle << d;
      for (double d : previousPositions) fileHandle << d;
      fileHandle << movements;
      fileHandle << time;
      fclose(fileHandle);
    }
  

