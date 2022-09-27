/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains selection sort definition
*/

#include "Sort.h"

std::vector<int> selection(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
  for (int i = 0; i < static_cast<int>(arr.size()) - 1; ++i) {
    ++loops;
    int minIndex = i;
    bool hasSwapped = false;
    for (int j = i + 1; j < static_cast<int>(arr.size()); ++j) {
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