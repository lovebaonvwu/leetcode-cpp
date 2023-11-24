class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    for (int i = 0, cnt = 0; i < arr.size(); ++i) {
      for (int slow = i, fast = i + m, step = 1, cnt = 1; fast < arr.size();
           ++slow, ++fast, ++step) {
        if (arr[slow] != arr[fast]) {
          break;
        } else if (step % m == 0) {
          ++cnt;
        }

        if (cnt == k) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 81.61%
// Memory Usage: 8.4 MB, less than 57.86%

class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    for (int i = 0, j = m, cnt = 0; j < arr.size(); ++i, ++j) {
      if (arr[i] != arr[j]) {
        cnt = 0;
      } else {
        cnt += 1;
      }

      if (cnt == (k - 1) * m) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 81.61%
// Memory Usage: 8.5 MB, less than 34.14%