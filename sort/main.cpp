#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include "sort.h"

template<typename t> void print(std::vector<t> arr, int &loops, int &comparisons, int &swaps) {
  //for (auto i : arr)
  //  std::cout << i << ", ";
  //std::cout << std::endl;

  std::cout << "Array is " << (isSorted(arr) ? "sorted." : "not sorted.") << std::endl;
  std::cout << "The sort looped " << loops << " times, made " << comparisons << " comparisons, and performed "
    << swaps << " swaps." << std::endl;
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
  }

  //Block to test for a sorted array
  numbers.clear();
  for (int i = 0; i < 100; ++i)
    numbers.push_back(i + 1);

  int loops = 0;
  int comparisons = 0;
  int swaps = 0;
  std::vector<int> holdingArr = numbers;

  std::cout << "Original Data" << std::endl;
  print(holdingArr, loops, comparisons, swaps);
  std::cout << std::endl;

  std::cout << "Bubble Sort" << std::endl;
  bubble(holdingArr, loops, comparisons, swaps);
  print(holdingArr, loops, comparisons, swaps);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  std::cout << "Insertion Sort" << std::endl;
  insertion(holdingArr, loops, comparisons, swaps);
  print(holdingArr, loops, comparisons, swaps);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  std::cout << "Selection Sort" << std::endl;
  selection(holdingArr, loops, comparisons, swaps);
  print(holdingArr, loops, comparisons, swaps);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  std::cout << "Lomuto's Quick Sort" << std::endl;
  lomuto_quick(holdingArr, loops, comparisons, swaps);
  print(holdingArr, loops, comparisons, swaps);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;

  std::cout << "Hoare's Quick Sort" << std::endl;
  hoare_quick(holdingArr, loops, comparisons, swaps);
  print(holdingArr, loops, comparisons, swaps);
  std::cout << std::endl;
  holdingArr = numbers;
  loops = 0;
  comparisons = 0;
  swaps = 0;
}