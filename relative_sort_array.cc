class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> tmp(1001, 0);

    for (const auto& n : arr1) {
      tmp[n]++;
    }

    vector<int> ans;

    for (const auto& n : arr2) {
      while (tmp[n]-- > 0) {
        ans.push_back(n);
      }
    }

    for (int i = 0; i < 1001; ++i) {
      while (tmp[i]-- > 0) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 91.53%
// Memory Usage: 8.9 MB, less than 100.00%

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int i = 0;
    for (const auto& n : arr2) {
      for (; i < arr1.size(); ++i) {
        if (arr1[i] == n) {
          continue;
        }

        bool swapped = false;
        for (int j = i; j < arr1.size(); ++j) {
          if (arr1[j] == n) {
            swapped = true;
            swap(arr1[i], arr1[j]);
            break;
          }
        }

        if (!swapped) {
          break;
        }
      }
    }

    sort(arr1.begin() + i, arr1.end());

    return arr1;
  }
};
// Runtime: 4 ms, faster than 91.53%
// Memory Usage: 8.8 MB, less than 100.00%