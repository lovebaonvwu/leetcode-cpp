class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    unordered_map<string, unordered_set<string>> mp;

    bank.push_back(start);

    for (int i = 0; i < bank.size(); ++i) {
      for (int j = i + 1; j < bank.size(); ++j) {
        if (differByOne(bank[i], bank[j])) {
          mp[bank[i]].insert(bank[j]);
          mp[bank[j]].insert(bank[i]);
        }
      }
    }

    queue<string> q;
    q.push(start);

    int ans = 0;

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        string next = q.front();
        q.pop();

        if (next == end) {
          return ans;
        }

        for (auto& s : mp[next]) {
          q.push(s);
        }

        mp.erase(next);
      }

      ++ans;
    }

    return -1;
  }

 private:
  bool differByOne(const string& a, const string& b) {
    int cnt = 0;

    for (int i = 0; i < a.size() && cnt < 2; ++i) {
      if (a[i] != b[i]) {
        ++cnt;
      }
    }

    return cnt == 1;
  }
};
// Runtime: 4 ms, faster than 19.54%
// Memory Usage: 6.7 MB, less than 9.77%
// 2022.2.15 at 奥盛大厦