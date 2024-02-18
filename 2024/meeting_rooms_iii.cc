class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(begin(meetings), end(meetings));
    vector<long long> room(n);
    vector<int> cnt(n);

    for (int k = 0; k < meetings.size(); ++k) {
      long long start = meetings[k][0];
      long long end = meetings[k][1];

      bool find = false;
      long long minstart = LLONG_MAX;
      int nextAvailable = 0;

      for (int i = 0; i < n; ++i) {
        if (start >= room[i]) {
          room[i] = end;
          ++cnt[i];
          find = true;
          break;
        }

        if (room[i] < minstart) {
          minstart = room[i];
          nextAvailable = i;
        }
      }

      if (!find) {
        room[nextAvailable] += end - start;
        ++cnt[nextAvailable];
      }
    }

    int ans = 0;
    int maxcnt = 0;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] > maxcnt) {
        maxcnt = cnt[i];
        ans = i;
      }
    }

    return ans;
  }
};
// 324 ms
// 100.34 MB