class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> st(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 1; k > 0; ++i) {
      if (!st.count(i)) {
        --k;
        ans = i;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 56.71%
// Memory Usage: 10.9 MB, less than 26.81%

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> st(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0, j = 0; k > 0 && j < arr.size(); ++j) {
      while (i + 1 != arr[j] && k > 0) {
        ++i;
        --k;
        ans = i;
      }

      i = arr[j];
    }

    if (k > 0) {
      ans = arr[arr.size() - 1];

      while (k-- > 0) {
        ans += 1;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 56.71%
// Memory Usage: 11.1 MB, less than 22.93%

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int ans = 0;
    for (int i = 0, j = 0; k > 0 && j < arr.size(); ++j) {
      while (i + 1 != arr[j] && k > 0) {
        ++i;
        --k;
        ans = i;
      }

      i = arr[j];
    }

    if (k > 0) {
      ans = arr[arr.size() - 1];

      while (k-- > 0) {
        ans += 1;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 94.74%
// Memory Usage: 9.6 MB, less than 92.89%