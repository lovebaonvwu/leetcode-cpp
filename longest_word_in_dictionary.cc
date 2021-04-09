class Trie {
 public:
  Trie() {
    memset(next, 0, sizeof(next));
    isWord = false;
  }

  ~Trie() {
    for (int i = 0; i < 26; ++i) {
      delete next[i];
    }
  }

  void insert(const string& word) {
    Trie* cur = this;
    this->isWord = true;

    for (auto c : word) {
      if (!cur->next[c - 'a']) {
        cur->next[c - 'a'] = new Trie;
      }

      cur = cur->next[c - 'a'];
    }

    cur->word = word;
    cur->isWord = true;
  }

  string bfs() {
    queue<Trie*> q;

    q.push(this);

    string res;

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        for (int i = 0; i < 26; ++i) {
          if (node->next[i] && node->isWord) {
            q.push(node->next[i]);
          }

          if (node->isWord) {
            res = res.size() < node->word.size() ? node->word : res;
          }
        }
      }
    }

    return res;
  }

 private:
  Trie* next[26];
  string word;
  bool isWord;
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    Trie root;

    for (auto& word : words) {
      root.insert(word);
    }

    return root.bfs();
  }
};
// Runtime: 40 ms, faster than 83.72%
// Memory Usage: 30.6 MB, less than 31.99%