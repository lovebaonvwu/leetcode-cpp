class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    priority_queue<pair<int, int>> pq;

    for (int i = lo; i <= hi; ++i) {
      int power = 0;

      for (int x = i; x != 1; ++power) {
        x = x & 1 ? 3 * x + 1 : x / 2;
      }

      pq.push({power, i});
    }

    int cnt = pq.size() - k;

    while (cnt-- > 0) {
      pq.pop();
    }

    return pq.top().second;
  }
};
// Runtime: 76 ms, faster than 47.79%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    vector<pair<int, int>> vec;

    for (int i = lo; i <= hi; ++i) {
      int power = 0;

      for (int x = i; x != 1; ++power) {
        x = x & 1 ? 3 * x + 1 : x / 2;
      }

      vec.push_back({power, i});
    }

    sort(vec.begin(), vec.end());

    return vec[k - 1].second;
  }
};
// Runtime: 56 ms, faster than 57.61%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    vector<pair<int, int>> vec;

    for (int i = lo; i <= hi; ++i) {
      int power = 0;

      for (int x = i; x != 1; ++power) {
        x = x & 1 ? 3 * x + 1 : x / 2;
      }

      vec.push_back({power, i});
    }

    nth_element(vec.begin(), vec.begin() + k - 1, vec.end());

    return vec[k - 1].second;
  }
};
// Runtime: 36 ms, faster than 92.16%
// Memory Usage: 8.6 MB, less than 100.00%