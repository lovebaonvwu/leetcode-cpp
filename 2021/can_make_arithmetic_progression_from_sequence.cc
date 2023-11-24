class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size() - 1; ++i) {
      if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i]) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 16 ms, faster than 75.00%
// Memory Usage: 8.9 MB, less than 100.00%

class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    if (max == min) {
      return true;
    }

    int interval = (max - min) / (arr.size() - 1);

    unordered_set<int> st(arr.begin(), arr.end());

    if (st.size() != arr.size()) {
      return false;
    }

    for (int i = min, n = 0; n < arr.size(); ++n, i += interval) {
      if (!st.count(i)) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 75.00%
// Memory Usage: 9.8 MB, less than 100.00%