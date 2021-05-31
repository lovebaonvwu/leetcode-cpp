class TrieNode {
 public:
  TrieNode() { memset(next, 0, sizeof(next)); }
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      delete next[i];
    }
  }

  friend class Trie;

 private:
  TrieNode* next[26];
  vector<string> suggest;
};

class Trie {
 public:
  Trie() : root(new TrieNode) {}
  ~Trie() { delete root; }

  void insert(const string& s) {
    TrieNode* cur = root;

    for (auto c : s) {
      if (!cur->next[c - 'a']) {
        cur->next[c - 'a'] = new TrieNode;
      }
      cur = cur->next[c - 'a'];
      cur->suggest.push_back(s);
    }
  }

  vector<vector<string>> search(const string& s) {
    vector<vector<string>> result(s.size());

    for (int i = 0; i < s.size() && root->next[s[i] - 'a']; ++i) {
      root = root->next[s[i] - 'a'];

      sort(root->suggest.begin(), root->suggest.end());

      root->suggest.resize(min(3, (int)root->suggest.size()));
      result[i] = root->suggest;
    }

    return result;
  }

 private:
  TrieNode* root;
};

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {
    Trie root;

    for (auto& p : products) {
      root.insert(p);
    }

    return root.search(searchWord);
  }
};
// Runtime: 136 ms, faster than 42.29%
// Memory Usage: 116.3 MB, less than 28.98%