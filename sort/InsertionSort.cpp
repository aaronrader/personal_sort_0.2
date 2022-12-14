/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains insertion sort definition
*/

#include "sort.hpp"

std::vector<int> insertion(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
  for (int i = 1; i < static_cast<int>(arr.size()); ++i) {
    ++loops;
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      ++loops;
      ++comparisons;
      ++swaps;
      swap(arr[j + 1], arr[j]);
      --j;
    }
    if (j >= 0)
      ++comparisons;

    ++swaps;
    arr[j + 1] = key;
  }
  return arr;
}