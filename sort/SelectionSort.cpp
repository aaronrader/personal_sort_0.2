/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains selection sort definition
*/

#include "sorter.hpp"

namespace sort {

  class SelectionSorter : Sorter {
  public:
    std::vector<int> sort(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) override {
      for (int i = 0; i < static_cast<int>(arr.size()) - 1; ++i) {
        ++loops;
        int minIndex = i;
        for (int j = i + 1; j < static_cast<int>(arr.size()); ++j) {
          ++loops;
          ++comparisons;
          if (arr[j] < arr[minIndex]) {
            minIndex = j;
          }
        }
        if (minIndex != i) {
          ++swaps;
          swap(arr[i], arr[minIndex]);
        }
      }
      return arr;
    }
  };
}