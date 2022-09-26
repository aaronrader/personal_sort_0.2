#include "sort.h"

std::vector<int> bubble(std::vector<int>& arr, int& loops, int& comparisons, int& swaps) {
  for (int i = 0; i < arr.size() - 1; ++i) {
    ++loops;
    bool swapped = false;
    for (int j = 0; j < arr.size() - i - 1; ++j) {
      ++loops;
      ++comparisons;
      if (arr[j] > arr[j + 1]) {
        ++swaps;
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      return arr;
  }
  return arr;
}