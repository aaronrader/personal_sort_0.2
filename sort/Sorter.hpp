/*
* Author:   Aaron Rader
* Date:     09/2022
* Project:  sort
* Summary:  Contains typedef, utility functions, and sort function declarations
*/

#pragma once
#include<vector>

namespace sort {
  typedef unsigned long long stats_t;

  class Sorter {
  public:
    template<typename t> static inline void swap(t& lhs, t& rhs) {
      t temp = lhs;
      lhs = rhs;
      rhs = temp;
    }

    template<typename t> static inline bool isSorted(std::vector<t>& arr) {
      for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1])
          return false;
      }
      return true;
    }

    virtual std::vector<int> sort(std::vector<int>& arr, stats_t& loops, stats_t& comparisons, stats_t& swaps) = 0;
  };
}