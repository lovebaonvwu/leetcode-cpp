class Solution {
 public:
  string clearStars(string s) {
    priority_queue<pair<char, int>, vector<pair<char, int>>,
                   greater<pair<char, int>>>
        pq;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
        auto [_, index] = pq.top();
        pq.pop();
        s[-index] = '-';
      } else {
        pq.push({s[i], -i});
      }
    }

    string ans = "";
    for (auto c : s) {
      if (c != '-' && c != '*')
        ans += c;
    }

    return ans;
  }
};
// 210 ms
// 26.03 MB