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

struct VideoData;
struct DataStorage;

void load(VideoData video):;
void save(DataStorage):;

void load(VideoData video) {
  DataStorage entry;
  save(&entry);
  entry = new VideoData{\ video};
  save(&entry);
  }

void save(DataStorage &storage) {
  // Clear the existing data storage
  ClearDataStorage(storage);
  // Write each video to the file
  for (const VideoData &video : storage) {
    // Write the video's ID and data
    writeVideoData(video, storage);
  }
  }
  // This is the JSON structure
  "reasoning": [
    "The save function needs to write all videos to a file."
    "First, it clears the existing data storage to free up space."
    "Then, it iterates through each video in the storage"
    "and writes each video's data to the file."
    "This ensures all videos are saved correctly without affecting each other."
    "The steps ensure all data is written in order"
    "and efficiently to the specified file."
    "The function returns without errors as all operations"
    "are handled properly."
    "The code uses the shared DataStorage struct and"
    "manages each VideoData object individually."
    "It writes each video's ID and other data"
    "to the specified file, ensuring all content"
    "is saved without any loss or modification."
    "The function returns the complete saving process"
    "as described in the reasoning section."
  ],
  "reasoning": [
    

