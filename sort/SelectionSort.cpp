#include "Sort.h"

std::vector<int> selection(std::vector<int>& arr, int& loops, int& comparisons, int& swaps) {
  for (size_t i = 0; i < arr.size() - 1; ++i) {
    ++loops;
    int minIndex = i;
    bool hasSwapped = false;
    for (size_t j = i + 1; j < arr.size(); ++j) {
      ++loops;
      ++comparisons;
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        hasSwapped = true;
      }
    }
    if (hasSwapped) {
      ++swaps;
      swap(arr[i], arr[minIndex]);
    }
  }
  return arr;
}