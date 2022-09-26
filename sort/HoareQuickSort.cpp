#include "Sort.h"

int hoare_partition(std::vector<int>& arr, int lowIndex, int highIndex, int& loops, int& comparisons, int& swaps) {
  int leftIndex = lowIndex - 1;
  int rightIndex = highIndex + 1;
  int pivot = arr[(highIndex + lowIndex) / 2];

  while(true) {
    do {
      ++loops;
      ++comparisons;
      ++leftIndex;
    } while (arr[leftIndex] < pivot);

    do {
      ++loops;
      ++comparisons;
      --rightIndex;
    } while (arr[rightIndex] > pivot);

    if (leftIndex >= rightIndex)
      return rightIndex;

    ++swaps;
    swap(arr[leftIndex], arr[rightIndex]);
  }
}

void hoare_quicksort(std::vector<int>& arr, int lowIndex, int highIndex, int& loops, int& comparisons, int& swaps) {
  if (lowIndex >= highIndex)
    return;

  int pivotIndex = hoare_partition(arr, lowIndex, highIndex, loops, comparisons, swaps);

  hoare_quicksort(arr, lowIndex, pivotIndex, loops, comparisons, swaps);
  hoare_quicksort(arr, pivotIndex + 1, highIndex, loops, comparisons, swaps);
}

std::vector<int> hoare_quick(std::vector<int>& arr, int& loops, int& comparisons, int& swaps) {
  if (arr.size() < 2)
    return arr;

  hoare_quicksort(arr, 0, arr.size() - 1, loops, comparisons, swaps);
  return arr;
}