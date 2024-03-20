class Solution {
 public:
  string minimizeStringValue(string s) {
    vector<int> cnt(26);
    for (auto c : s) {
      if (c != '?') {
        ++cnt[c - 'a'];
      }
    }

    priority_queue<pair<int, char>, vector<pair<int, char>>,
                   greater<pair<int, char>>>
        pq;
    for (int i = 0; i < cnt.size(); ++i) {
      pq.push({cnt[i], i + 'a'});
    }

    vector<char> candidate;
    for (auto c : s) {
      if (c == '?') {
        auto [cnt, ch] = pq.top();
        pq.pop();

        candidate.push_back(ch);
        pq.push({cnt + 1, ch});
      }
    }

    sort(begin(candidate), end(candidate));
    for (int i = 0, j = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        s[i] = candidate[j++];
      }
    }

    return s;
  }
};
// 101 ms
// 22.14 MB