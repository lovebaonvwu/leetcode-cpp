class Trie {
 public:
  Trie() : isWord(false) { memset(children, 0, sizeof(children)); }

  ~Trie() {
    for (int i = 0; i < 26; ++i) {
      if (children[i]) {
        delete children[i];
      }
    }
  }

  void insert(string s) {
    Trie* cur = this;
    for (auto c : s) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new Trie;
      }

      cur = cur->children[c - 'a'];
    }

    cur->isWord = true;
  }

  bool search(string s) {
    Trie* cur = this;

    for (auto c : s) {
      if (!cur->children[c - 'a']) {
        return false;
      }

      cur = cur->children[c - 'a'];
      if (cur->isWord) {
        return true;
      }
    }
    return cur->isWord;
  }

 private:
  Trie* children[26];
  bool isWord;
};

class StreamChecker {
 private:
  Trie root;
  string s = "";
  int max_len = 0;

 public:
  StreamChecker(vector<string>& words) {
    for (auto& word : words) {
      reverse(word.begin(), word.end());
      root.insert(word);

      max_len = max(max_len, static_cast<int>(word.size()));
    }
  }

  bool query(char letter) {
    s = letter + s;

    if (s.size() > max_len) {
      s.pop_back();
    }

    return root.search(s);
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// Runtime: 1268 ms, faster than 15.38%
// Memory Usage: 267.3 MB, less than 13.29%