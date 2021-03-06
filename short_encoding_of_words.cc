class Trie {
 public:
  Trie() {}

  ~Trie() {
    for (int i = 0; i < 26; ++i) {
      delete next[i];
    }
  }

  int insert(const string& word) {
    Trie* root = this;
    bool newBranch = false;

    for (auto c : word) {
      if (!root->next[c - 'a']) {
        newBranch = true;
        root->next[c - 'a'] = new Trie;
      }

      root = root->next[c - 'a'];
    }

    root->isWord = true;

    return newBranch ? word.size() : 0;
  }

 private:
  Trie* next[26] = {0};
  bool isWord = false;
};

class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    sort(words.begin(), words.end(),
         [](auto& a, auto& b) { return a.size() > b.size(); });

    Trie root;

    int ans = 0;

    for (auto& word : words) {
      reverse(word.begin(), word.end());

      int cnt = root.insert(word);
      if (cnt) {
        ans += cnt + 1;
      }
    }

    return ans;
  }
};
// Runtime: 76 ms, faster than 51.00%
// Memory Usage: 75.4 MB, less than 21.00%

class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    for (auto& word : words) {
      reverse(word.begin(), word.end());
    }

    sort(words.begin(), words.end());

    int ans = 0;

    for (int i = 0; i < words.size() - 1; ++i) {
      if (words[i] == (words[i + 1].substr(0, words[i].size()))) {
        continue;
      }

      ans += words[i].size() + 1;
    }

    return ans += words.back().size() + 1;
  }
};
// Runtime: 28 ms, faster than 98.00%
// Memory Usage: 13.6 MB, less than 98.00%