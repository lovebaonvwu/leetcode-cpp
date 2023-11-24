class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    vector<queue<int>> bits(32);

    sort(arr.begin(), arr.end());

    for (int n : arr) {
      int cnt = 0;
      for (int i = 0, t = n; i < 32; ++i) {
        if (t & 1) {
          ++cnt;
        }
        t = t >> 1;
      }

      bits[cnt].push(n);
    }

    vector<int> ans;

    for (auto v : bits) {
      while (!v.empty()) {
        ans.push_back(v.front());
        v.pop();
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 100.00%
// Memory Usage: 14 MB, less than 100.00%

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int cnt_a = bitset<32>(a).count();
      int cnt_b = bitset<32>(b).count();

      return cnt_a == cnt_b ? a < b : cnt_a < cnt_b;
    });

    return arr;
  }
};
// Runtime: 20 ms, faster than 85.71%
// Memory Usage: 9.4 MB, less than 100.00%

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int cnt_a = 0;
      int cnt_b = 0;

      for (int i = 0; i < 32; ++i) {
        if (a & (1 << i))
          ++cnt_a;
        if (b & (1 << i))
          ++cnt_b;
      }

      return cnt_a == cnt_b ? a < b : cnt_a < cnt_b;
    });

    return arr;
  }
};
// Runtime: 40 ms, faster than 14.29%
// Memory Usage: 9.3 MB, less than 100.00%