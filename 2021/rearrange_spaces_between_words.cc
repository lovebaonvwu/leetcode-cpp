class Solution {
 public:
  string reorderSpaces(string text) {
    int spaces = 0;

    stringstream ss(text);

    string s;

    vector<string> words;

    while (ss >> s) {
      words.push_back(s);
    }

    for (auto c : text) {
      if (isspace(c)) {
        ++spaces;
      }
    }

    if (words.size() == 1) {
      return words[0].append(spaces, ' ');
    }

    int cnt = spaces / (words.size() - 1);

    string ans;
    for (auto& word : words) {
      ans += word;

      if (spaces) {
        ans.append(min(cnt, spaces), ' ');
        spaces -= min(cnt, spaces);
      }
    }

    if (spaces) {
      ans.append(spaces, ' ');
    }

    return ans;
  }
};
// Runtime: 3 ms, faster than 9.31%
// Memory Usage: 6.2 MB, less than 82.11%
// 2021.8.31 at 奥盛大厦