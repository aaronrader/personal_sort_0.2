#include "sort.h"

std::vector<int> insertion(std::vector<int>& arr, int& loops, int& comparisons, int& swaps) {
  for (int i = 1; i < arr.size(); ++i) {
    ++loops;
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      ++loops;
      ++comparisons;
      ++swaps;
      swap(arr[j], arr[j - 1]);
      --j;
    }
  }
  return arr;
}