#pragma once
#include<vector>

template<typename t> void swap(t& lhs, t& rhs) {
  t temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template<typename t> bool isSorted(std::vector<t>& arr) {
  for (int i = 0; i < arr.size() - 1; ++i) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

std::vector<int> bubble(std::vector<int> &arr, int &loops, int &comparisons, int &swaps);
std::vector<int> insertion(std::vector<int>& arr, int& loops, int& comparisons, int& swaps);
std::vector<int> selection(std::vector<int>& arr, int& loops, int& comparisons, int& swaps);
std::vector<int> lomuto_quick(std::vector<int>& arr, int& loops, int& comparisons, int& swaps);
std::vector<int> hoare_quick(std::vector<int>& arr, int& loops, int& comparisons, int& swaps);