class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    set<int> st(special.begin(), special.end());
    if (st.find(bottom) != st.end()) {
      st.insert(bottom - 1);
      bottom -= 1;
    } else {
      st.insert(bottom);
    }

    if (st.find(top) != st.end()) {
      st.insert(top + 1);
      top += 1;
    } else {
      st.insert(top);
    }

    int ans = 0;
    for (auto it = next(begin(st)); it != st.end(); ++it) {
      auto cur = prev(it);

      if (*cur + 1 < *it) {
        if (*it - *cur > ans) {
          if (*cur != bottom && *it != top) {
            ans = *it - *cur - 1;
          } else {
            ans = *it - *cur;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 857 ms, faster than 25.00%
// Memory Usage: 97 MB, less than 25.00%
// 2022.5.16 at 奥盛大厦

class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    special.insert(end(special), {bottom - 1, top + 1});

    sort(begin(special), end(special));

    int ans = 0;
    for (int i = 1; i < special.size(); ++i) {
      ans = max(ans, special[i] - special[i - 1] - 1);
    }

    return ans;
  }
};
// Runtime: 200 ms, faster than 50.00%
// Memory Usage: 58.1 MB, less than 25.00%
// 2022.5.16 at 奥盛大厦