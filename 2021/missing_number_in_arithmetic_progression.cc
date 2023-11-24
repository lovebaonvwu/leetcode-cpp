class Solution {
 public:
  int missingNumber(vector<int>& arr) {
    if (arr[0] == arr[1]) {
      return arr[0];
    }

    int ans = 0;

    if (arr[0] < arr[1]) {
      int diff = INT_MAX;

      for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] < diff) {
          diff = arr[i] - arr[i - 1];
        }
      }

      for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] != diff) {
          ans = (arr[i] + arr[i - 1]) / 2;
          break;
        }
      }
    } else {
      int diff = INT_MIN;

      for (int i = arr.size() - 1; i > 0; --i) {
        if (arr[i] - arr[i - 1] > diff) {
          diff = arr[i] - arr[i - 1];
        }
      }

      for (int i = arr.size() - 1; i > 0; --i) {
        if (arr[i] - arr[i - 1] != diff) {
          ans = (arr[i] + arr[i - 1]) / 2;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  int missingNumber(vector<int>& arr) {
    int diff = (arr[arr.size() - 1] - arr[0]) / (int)arr.size();

    int lo = 0;
    int hi = arr.size() - 1;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      if (arr[mid] == arr[0] + diff * mid) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return arr[0] + diff * lo;
  }
};
// Runtime: 8 ms, faster than 100.00%
// Memory Usage: 8.8 MB, less than 100.00%

class Solution {
 public:
  int missingNumber(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int diff = INT_MAX;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - arr[i - 1] < diff) {
        diff = arr[i] - arr[i - 1];
      }
    }

    int ans = 0;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - arr[i - 1] != diff) {
        ans = (arr[i] + arr[i - 1]) / 2;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 100.00%
// Memory Usage: 8.8 MB, less than 100.00%