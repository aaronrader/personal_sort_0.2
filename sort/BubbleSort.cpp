/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains bubble sort definition
*/

#include "sort.hpp"

std::vector<int> bubble(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
  for (int i = 0; i < static_cast<int>(arr.size()) - 1; ++i) {
    ++loops;
    bool swapped = false;
    for (int j = 0; j < static_cast<int>(arr.size()) - i - 1; ++j) {
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