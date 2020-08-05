class TrieNode {
 public:
  TrieNode() {}

  ~TrieNode() {
    for (int i = 0; i < n; ++i) {
      if (children[i]) {
        delete children[i];
      }
    }
  }
  static const int n = 26;

  bool is_word = false;

  TrieNode* children[n] = {};
};

class WordDictionary {
 public:
  /** Initialize your data structure here. */
  WordDictionary() : root(new TrieNode) {}

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode* cur = root;

    for (auto c : word) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode;
      }

      cur = cur->children[c - 'a'];
    }

    cur->is_word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return search(word, 0, root); }

 private:
  TrieNode* root;
  bool search(string s, int index, TrieNode* root) {
    if (index == s.size()) {
      return root->is_word;
    }

    if (s[index] != '.') {
      if (!root->children[s[index] - 'a']) {
        return false;
      }

      return search(s, index + 1, root->children[s[index] - 'a']);
    }

    for (int i = 0; i < 26; ++i) {
      if (root->children[i] && search(s, index + 1, root->children[i])) {
        return true;
      }
    }

    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// Runtime: 232 ms, faster than 49.33%
// Memory Usage: 105.3 MB, less than 16.15%