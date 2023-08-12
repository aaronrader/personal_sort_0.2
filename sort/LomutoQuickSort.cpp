/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains Lomuto's quick sort definition
*/

#include "sorter.hpp"

namespace sort {

  class LomutoQuickSorter : Sorter {

    int lomuto_partition(std::vector<int>& arr, int lowIndex, int highIndex, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
      int pivot = arr[highIndex]; //use the high index as the pivot position

      int currentPosition = lowIndex - 1;

      for (int i = lowIndex; i < highIndex; ++i) { //no need to compare pivot to itself
        ++loops;
        ++comparisons;
        if (arr[i] <= pivot) {
          //raise current correct position
          ++currentPosition;
          ++swaps;
          swap(arr[i], arr[currentPosition]);
        }
      }

      //put the pivot in the correct position
      ++currentPosition;
      ++swaps;
      swap(arr[currentPosition], arr[highIndex]);
      //pivot is the highest value in this part of the array
      return currentPosition;
    }

    void lomuto_quicksort(std::vector<int>& arr, int lowIndex, int highIndex, stats_t& loops, stats_t& comparisons, stats_t& swaps) {
      if (lowIndex >= highIndex) return;

      //returns the index of the highest value in the lower array
      int pivotIndex = lomuto_partition(arr, lowIndex, highIndex, loops, comparisons, swaps);

      //sort with lower array
      lomuto_quicksort(arr, lowIndex, pivotIndex - 1, loops, comparisons, swaps);
      //sort with higher array
      lomuto_quicksort(arr, pivotIndex + 1, highIndex, loops, comparisons, swaps);
    }

    //main entry
  public:
    std::vector<int> sort(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) override {
      if (arr.size() < 2)
        return arr;

      lomuto_quicksort(arr, 0, static_cast<int>(arr.size()) - 1, loops, comparisons, swaps);
      return arr;
    }
  };
}