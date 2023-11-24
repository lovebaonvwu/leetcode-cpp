class Solution {
 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int size = requests.size();
    function<int(int)> test = [&](int mask) {
      int balance[20] = {0};
      for (int i = 0; i < size; ++i) {
        if (mask & (1 << i)) {
          --balance[requests[i][0]];
          ++balance[requests[i][1]];
        }
      }

      for (int i = 0; i < 20; ++i) {
        if (balance[i] != 0) {
          return false;
        }
      }

      return true;
    };

    function<int(int)> count = [&](int k) {
      int res = 0;
      for (int i = 0; i < size; ++i) {
        if ((1 << i) & k) {
          ++res;
        }
      }

      return res;
    };

    int ans = 0;
    for (int i = 0; i < (1 << size); ++i) {
      if (test(i)) {
        ans = max(ans, count(i));
      }
    }

    return ans;
  }
};
// Runtime 428 ms
// Memory 8.5 MB