class Solution {
 public:
  vector<int> transformArray(vector<int>& arr) {
    while (true) {
      bool test = false;

      int prev = arr[0];
      int cur;

      for (int i = 1; i < arr.size() - 1; ++i) {
        cur = arr[i];

        if (arr[i] > prev && arr[i] > arr[i + 1]) {
          --arr[i];
          test = true;
        } else if (arr[i] < prev && arr[i] < arr[i + 1]) {
          ++arr[i];
          test = true;
        }

        prev = cur;
      }

      if (!test) {
        break;
      }
    }

    return arr;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 100.00%

class Solution {
 public:
  vector<int> transformArray(vector<int>& arr) {
    while (true) {
      bool test = false;
      vector<int> tmp = arr;

      for (int i = 1; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
          --tmp[i];
          test = true;
        } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
          ++tmp[i];
          test = true;
        }
      }
      arr = tmp;

      if (!test) {
        break;
      }
    }

    return arr;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 100.00%