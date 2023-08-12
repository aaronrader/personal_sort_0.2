/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains merge sort definition
*/

#include "sorter.hpp"

namespace sort {

  class MergeSorter : Sorter {
    void merge_elements(std::vector<int>& arr, int lowIndex, int highIndex, int middleIndex, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
      std::vector<int> buffer;

      int left = lowIndex;
      int right = middleIndex + 1;
      int current = lowIndex;

      while (current <= middleIndex && right <= highIndex) {
        ++loops;
        ++comparisons;
        if (arr[current] < arr[right]) {
          buffer.push_back(arr[current]);
          ++left;
          ++current;
        }
        else {
          buffer.push_back(arr[right]);
          ++left;
          ++right;
        }
      }

      while (current <= middleIndex) {
        buffer.push_back(arr[current]);
        ++left;
        ++current;
      }

      while (right <= highIndex) {
        buffer.push_back(arr[right]);
        ++left;
        ++right;
      }

      int i = 0;
      for (current = lowIndex; current < left; ++current) {
        ++swaps;
        arr[current] = buffer[i];
        ++i;
      }
    }

    void mergesort(std::vector<int>& arr, int lowIndex, int highIndex, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
      if (lowIndex >= highIndex) return;

      int middleIndex = (lowIndex + highIndex) / 2;

      mergesort(arr, lowIndex, middleIndex, loops, comparisons, swaps);
      mergesort(arr, middleIndex + 1, highIndex, loops, comparisons, swaps);

      merge_elements(arr, lowIndex, highIndex, middleIndex, loops, comparisons, swaps);
    }

  public:
    std::vector<int> sort(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) override {
      mergesort(arr, 0, static_cast<int>(arr.size()) - 1, loops, comparisons, swaps);
      return arr;
    }
  };
}