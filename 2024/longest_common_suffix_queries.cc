class Trie {
 public:
  Trie() : min_len(-1), min_index(-1) { memset(children, 0, sizeof(children)); }

  void insert(const string& s, int index) {
    Trie* cur = this;

    if (cur->min_len == -1 || s.size() < cur->min_len) {
      cur->min_len = s.size();
      cur->min_index = index;
    }

    for (auto c : s) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new Trie;
      }

      cur = cur->children[c - 'a'];

      if (cur->min_len == -1 || s.size() < cur->min_len) {
        cur->min_len = s.size();
        cur->min_index = index;
      }
    }
  }

  int search(const string& s) {
    Trie* cur = this;
    for (auto c : s) {
      if (!cur->children[c - 'a'])
        break;
      cur = cur->children[c - 'a'];
    }
    return cur->min_index;
  }

 private:
  Trie* children[26];
  int min_len;
  int min_index;
};

class Solution {
 public:
  vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery) {
    Trie root;
    for (int i = 0; i < wordsContainer.size(); ++i) {
      reverse(begin(wordsContainer[i]), end(wordsContainer[i]));
      root.insert(wordsContainer[i], i);
    }

    vector<int> ans;
    for (auto& w : wordsQuery) {
      reverse(begin(w), end(w));
      ans.push_back(root.search(w));
    }

    return ans;
  }
};
// 361 ms
// 819.33 MB