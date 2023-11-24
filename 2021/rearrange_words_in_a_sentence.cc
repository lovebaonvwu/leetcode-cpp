class Solution {
 public:
  string arrangeWords(string text) {
    text[0] = tolower(text[0]);

    stringstream ss(text);
    string word;
    int i = 0;

    vector<pair<string, int>> words;

    while (ss >> word) {
      words.push_back({word, i++});
    }

    sort(words.begin(), words.end(), [](auto a, auto b) {
      if (a.first.size() < b.first.size()) {
        return true;
      } else if (a.first.size() > b.first.size()) {
        return false;
      } else {
        return a.second < b.second;
      }
    });

    words[0].first[0] = toupper(words[0].first[0]);
    string ans = words[0].first;

    for (int i = 1; i < words.size(); ++i) {
      ans += ' ';
      ans += words[i].first;
    }

    return ans;
  }
};
// Runtime: 300 ms, faster than 18.05%
// Memory Usage: 18.4 MB, less than 100.00%

class Solution {
 public:
  string arrangeWords(string text) {
    text[0] = tolower(text[0]);

    vector<string> words;
    string word;
    text += ' ';
    for (int i = 0; i < text.size(); ++i) {
      if (text[i] == ' ') {
        words.push_back(word);
        word = "";
      } else {
        word += text[i];
      }
    }

    stable_sort(words.begin(), words.end(),
                [](auto a, auto b) { return a.size() < b.size(); });

    words[0][0] = toupper(words[0][0]);
    string ans = words[0];

    for (int i = 1; i < words.size(); ++i) {
      ans += ' ';
      ans += words[i];
    }

    return ans;
  }
};
// Runtime: 216 ms, faster than 37.33%
// Memory Usage: 19.2 MB, less than 100.00%

class Solution {
 public:
  string arrangeWords(string text) {
    text[0] = tolower(text[0]);

    stringstream iss(text), oss;
    string w;

    map<int, vector<string>> m;
    while (iss >> w) {
      m[w.size()].emplace_back(w);
    }

    for (auto& v : m) {
      for (auto& s : v.second) {
        oss << s << " ";
      }
    }

    string ans = oss.str();
    ans[0] = toupper(ans[0]);

    ans.pop_back();

    return ans;
  }
};
// Runtime: 68 ms, faster than 99.01%
// Memory Usage: 17.4 MB, less than 100.00%