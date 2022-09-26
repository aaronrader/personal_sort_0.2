#include "Sort.h"

int lomuto_partition(std::vector<int>& arr, int lowIndex, int highIndex, int& loops, int& comparisons, int& swaps) {
  int pivot = arr[highIndex];

  int currentPosition = lowIndex - 1;

  for (size_t i = lowIndex; i < highIndex; ++i) { //no need to compare pivot to itself
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

void lomuto_quicksort(std::vector<int>& arr, int lowIndex, int highIndex, int& loops, int& comparisons, int& swaps) {
  if (lowIndex >= highIndex) return;

  int partitionIndex = lomuto_partition(arr, lowIndex, highIndex, loops, comparisons, swaps); //returns the index of the highest
                                                            //value in the lower array

  //sort with lower array
  lomuto_quicksort(arr, lowIndex, partitionIndex - 1, loops, comparisons, swaps);
  //sort with higher array
  lomuto_quicksort(arr, partitionIndex + 1, highIndex, loops, comparisons, swaps);
}

//main entry
std::vector<int> lomuto_quick(std::vector<int> &arr, int& loops, int& comparisons, int& swaps) {
  if (arr.size() < 2)
    return arr;

  lomuto_quicksort(arr, 0, arr.size() - 1, loops, comparisons, swaps);
  return arr;
}