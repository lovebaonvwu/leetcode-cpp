class Solution {
 public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                   vector<vector<int>>& slots2,
                                   int duration) {
    sort(begin(slots1), end(slots1));
    sort(begin(slots2), end(slots2));

    int n1 = slots1.size();
    int n2 = slots2.size();

    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2) {
      int s1 = slots1[i][0];
      int e1 = slots1[i][1];
      int s2 = slots2[j][0];
      int e2 = slots2[j][1];

      if (s1 > e2) {
        ++j;
      } else if (s2 > e1) {
        ++i;
      } else {
        int s = max(s1, s2);
        int e = min(e1, e2);

        if (e - s >= duration) {
          ans.push_back(s);
          ans.push_back(s + duration);
          break;
        }

        if (e1 < e2) {
          ++i;
        } else {
          ++j;
        }
      }
    }

    return ans;
  }
};
// 110 ms
// 43.91 MB