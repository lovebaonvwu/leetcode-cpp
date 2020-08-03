class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    if (k > arr.size() - 1) {
      k = arr.size() - 1;
    }

    int ans = max(arr[0], arr[1]);

    for (int i = 2, cnt = k - 1; i < arr.size() && cnt > 0; ++i) {
      if (arr[i] > ans) {
        cnt = k - 1;
        ans = arr[i];
      } else {
        --cnt;
      }
    }

    return ans;
  }
};
// Runtime: 268 ms, faster than 60.00%
// Memory Usage: 63.2 MB, less than 100.00%

class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int ans = arr[0];
    int wins = 0;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > ans) {
        ans = arr[i];
        wins = 0;
      }

      if (++wins == k) {
        break;
      }
    }

    return ans;
  }
};
// Runtime: 272 ms, faster than 60.00%
// Memory Usage: 63.3 MB, less than 100.00%