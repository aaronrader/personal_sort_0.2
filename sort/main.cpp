/*
* Author:   Aaron Rader
* Date:     08/2023
* Project:  sort
* Summary:
*     This program will read in a series of whitespace separated integers or use a predefined set
*     if no file is provided. It will then sort the data using various sorting algorithms and
*     output information regarding the performance of each algorithm.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "SelectionSort.cpp"
#include "InsertionSort.cpp"
#include "BubbleSort.cpp"
#include "LomutoQuickSort.cpp"
#include "HoareQuickSort.cpp"
#include "MergeSort.cpp"

using namespace sort;

void print(stats_t& loops, stats_t& comparisons, stats_t& swaps, bool& sorted) {
  std::cout << "The sort looped " << loops << " times, made " << comparisons << " comparisons, and performed "
    << swaps << " swaps." << std::endl;
  std::cout << "Array is " << (sorted ? "sorted." : "not sorted.") << std::endl;
}

int main(int argc, char* argv[]) {
  //store command line arguments in a vector
  std::vector<std::string> args;
  for (int i = 1; i < argc; ++i)
    args.push_back(argv[i]);

  //set up a container for unsorted numbers populated with default values
  std::vector<int> numbers{ 2, 3, 1, 5, 4, 6, 3, 7, 9, 8 };

  //check for a file containing the numbers
  if (!args.empty()) {
    std::ifstream inFile(args[0]);
    //check if the file is good
    if (!inFile) {
      std::cout << "Error: file could not be opened.";
      return EXIT_FAILURE;
    }

    //store file contents into the numbers vector
    numbers.clear();
    int number;
    while (inFile >> number)
      numbers.push_back(number);

    //return fail if the data contains too many elements to sort
    if (numbers.size() >= std::numeric_limits<int>::max()) {
      std::cout << "Array contains too many elements. Maximum number of elements: "
        << std::numeric_limits<int>::max() - 1 << std::endl;
      return EXIT_FAILURE;
    }
  }

  //Title Information
  std::cout << "Sorting Algorithms Compared - Aaron Rader, 2023\n" << std::endl;

  //Block to test for a sorted array
  //numbers.clear();
  //for (int i = 0; i < 100; ++i)
  //  numbers.push_back(i + 1);

  //Print the data
  //for (auto i : numbers)
  //  std::cout << i << ", ";
  //std::cout << std::endl;

  std::cout.imbue(std::locale("")); //ensures a thousand's separator on numeric output

  stats_t loops = 0;
  stats_t comparisons = 0;
  stats_t swaps = 0;
  BubbleSorter bubble_sorter;
  InsertionSorter insertion_sorter;
  SelectionSorter selection_sorter;
  LomutoQuickSorter lomuto_sorter;
  HoareQuickSorter hoare_sorter;
  MergeSorter merge_sorter;
  std::vector<int> holdingArr = numbers;
  bool sorted = Sorter::isSorted(holdingArr);

  std::cout << "Original Data" << std::endl;
  std::cout << "Array contains " << holdingArr.size() << " elements." << std::endl;
  std::cout << "Array is " << (sorted ? "sorted." : "not sorted.") << std::endl;
  std::cout << std::endl;

  //Bubble Sort
  std::cout << "Bubble Sort" << std::endl;
  bubble_sorter.sort(holdingArr, loops, comparisons, swaps);
  sorted = Sorter::isSorted(holdingArr);
  print(loops, comparisons, swaps, sorted);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  //Insertion Sort
  std::cout << "Insertion Sort" << std::endl;
  insertion_sorter.sort(holdingArr, loops, comparisons, swaps);
  sorted = Sorter::isSorted(holdingArr);
  print(loops, comparisons, swaps, sorted);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  //Selection Sort
  std::cout << "Selection Sort" << std::endl;
  selection_sorter.sort(holdingArr, loops, comparisons, swaps);
  sorted = Sorter::isSorted(holdingArr);
  print(loops, comparisons, swaps, sorted);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  //Lomuto's Quick Sort
  std::cout << "Lomuto's Quick Sort" << std::endl;
  lomuto_sorter.sort(holdingArr, loops, comparisons, swaps);
  sorted = Sorter::isSorted(holdingArr);
  print(loops, comparisons, swaps, sorted);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  //Hoare's Quick Sort
  std::cout << "Hoare's Quick Sort" << std::endl;
  hoare_sorter.sort(holdingArr, loops, comparisons, swaps);
  sorted = Sorter::isSorted(holdingArr);
  print(loops, comparisons, swaps, sorted);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  //Merge Sort
  std::cout << "Merge Sort" << std::endl;
  merge_sorter.sort(holdingArr, loops, comparisons, swaps);
  sorted = Sorter::isSorted(holdingArr);
  print(loops, comparisons, swaps, sorted);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;
}