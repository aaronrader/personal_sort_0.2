/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains typedef, utility functions, and sort function declarations
*/

#pragma once
#include<vector>

typedef unsigned long long stats_t;

template<typename t> void swap(t& lhs, t& rhs) {
  t temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template<typename t> bool isSorted(std::vector<t>& arr) {
  for (int i = 0; i < static_cast<int>(arr.size()) - 1; ++i) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

std::vector<int> bubble(std::vector<int> &arr, stats_t& loops, stats_t& comparisons, stats_t& swaps);
std::vector<int> insertion(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps);
std::vector<int> selection(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps);
std::vector<int> lomuto_quick(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps);
std::vector<int> hoare_quick(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps);