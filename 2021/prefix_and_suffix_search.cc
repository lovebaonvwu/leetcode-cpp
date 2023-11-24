class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    int index = 0;
    for (auto& word : words) {
      int n = word.size();

      vector<string> prefix(n);
      vector<string> suffix(n);

      prefix[0] = word[0];
      suffix[0] = word[n - 1];

      for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + word[i];
        suffix[i] = word[n - i - 1] + suffix[i - 1];
      }

      for (auto& pre : prefix) {
        for (auto suf : suffix) {
          filter_[pre + '_' + suf] = index;
        }
      }

      ++index;
    }
  }

  int f(string prefix, string suffix) {
    string filter = prefix + '_' + suffix;

    if (filter_.find(filter) != filter_.end()) {
      return filter_[filter];
    }

    return -1;
  }

 private:
  unordered_map<string, int> filter_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// Runtime: 404 ms, faster than 60.19%
// Memory Usage: 128.8 MB, less than 75.73%

class Trie {
 public:
  Trie() : root_(new TrieNode){};

  void insert(const string& prefix, int index) {
    TrieNode* p = root_.get();

    for (auto c : prefix) {
      if (!p->children[c - 'a']) {
        p->children[c - 'a'] = new TrieNode;
      }

      p = p->children[c - 'a'];
      p->index = index;
    }

    p->is_word = true;
  }

  int startWith(const string& prefix) {
    TrieNode* node = find(prefix);

    return node ? node->index : -1;
  }

 private:
  struct TrieNode {
    TrieNode() : index(-1), is_word(false), children(27, nullptr) {}
    ~TrieNode() {
      for (auto child : children) {
        delete child;
      }
    }

    int index;
    bool is_word;
    vector<TrieNode*> children;
  };

  TrieNode* find(const string& prefix) {
    TrieNode* p = root_.get();

    for (auto c : prefix) {
      if (!p->children[c - 'a']) {
        return nullptr;
      }

      p = p->children[c - 'a'];
    }

    return p;
  }

  unique_ptr<TrieNode> root_;
};

class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    int index = 0;
    for (auto& word : words) {
      string prefix = '{' + word;

      for (int i = word.size() - 1; i >= 0; --i) {
        prefix = word[i] + prefix;
        root.insert(prefix, index);
      }

      ++index;
    }
  }

  int f(string prefix, string suffix) {
    return root.startWith(suffix + '{' + prefix);
  }

 private:
  Trie root;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// Runtime: 680 ms, faster than 19.90%
// Memory Usage: 184.4 MB, less than 42.72%