class Trie {
  Trie* next[26] = {};
  bool is_word = false;

 public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie* node = this;

    for (auto ch : word) {
      ch -= 'a';

      if (!node->next[ch]) {
        node->next[ch] = new Trie();
      }

      node = node->next[ch];
    }

    node->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* node = this;

    for (auto ch : word) {
      ch -= 'a';
      if (!node->next[ch]) {
        return false;
      }

      node = node->next[ch];
    }

    return node->is_word;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie* node = this;

    for (auto ch : prefix) {
      ch -= 'a';
      if (!node->next[ch]) {
        return false;
      }

      node = node->next[ch];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
  unordered_map<char, Trie*> mp;
  bool is_word = false;

 public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie* node = this;

    for (auto ch : word) {
      ch -= 'a';

      if (node->mp.find(ch) == node->mp.end()) {
        node->mp[ch] = new Trie();
      }

      node = node->mp[ch];
    }

    node->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* node = this;

    for (auto ch : word) {
      ch -= 'a';
      if (node->mp.find(ch) == node->mp.end()) {
        return false;
      }

      node = node->mp[ch];
    }

    return node->is_word;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie* node = this;

    for (auto ch : prefix) {
      ch -= 'a';
      if (node->mp.find(ch) == node->mp.end()) {
        return false;
      }

      node = node->mp[ch];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// Runtime: 152 ms, faster than 50.80%
// Memory Usage: 33.9 MB, less than 84.23%