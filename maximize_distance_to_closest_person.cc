class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    int ans = 0;
    int last = -1;

    for (int i = 0; i < n; ++i) {
      if (seats[i]) {
        ans = last < 0 ? i : max(ans, (i - last) / 2);

        last = i;
      }
    }

    if (seats[n - 1] == 0) {
      ans = max(ans, n - 1 - last);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 89.33%
// Memory Usage: 10 MB, less than 58.82%

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();

    vector<int> left(n);
    vector<int> right(n);

    int pos = -1;

    for (int i = 0; i < n; ++i) {
      if (seats[i] == 0) {
        left[i] = pos < 0 ? INT_MAX : i - pos;
      } else {
        pos = i;
      }
    }

    pos = n;
    for (int i = n - 1; i >= 0; --i) {
      if (seats[i] == 0) {
        right[i] = pos == n ? INT_MAX : pos - i;
      } else {
        pos = i;
      }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (seats[i] == 0) {
        ans = max(ans, min(left[i], right[i]));
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 46.42%
// Memory Usage: 10.8 MB, less than 11.76%