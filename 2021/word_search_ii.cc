class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;

    for (auto& w : words) {
      if (find(board, w)) {
        ans.push_back(w);
      }
    }

    return ans;
  }

  bool find(vector<vector<char>>& board, string& w) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (search(board, i, j, 0, w)) {
          return true;
        }
      }
    }

    return false;
  }

  bool search(vector<vector<char>>& board, int i, int j, int d, string& w) {
    if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 ||
        w[d] != board[i][j]) {
      return false;
    }

    if (d == w.size() - 1) {
      return true;
    }

    board[i][j] = '#';

    bool found = search(board, i, j + 1, d + 1, w) ||
                 search(board, i, j - 1, d + 1, w) ||
                 search(board, i + 1, j, d + 1, w) ||
                 search(board, i - 1, j, d + 1, w);
    board[i][j] = w[d];

    return found;
  }
};
// Time Limit Exceeded

struct TrieNode {
  vector<TrieNode*> nodes;
  string* word;

  TrieNode() : nodes(26), word(nullptr) {}
  ~TrieNode() {
    for (auto node : nodes) {
      delete node;
    }
  }
};

class Solution {
  int m;
  int n;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode root;

    for (auto& word : words) {
      TrieNode* cur = &root;

      for (auto c : word) {
        if (!cur->nodes[c - 'a']) {
          cur->nodes[c - 'a'] = new TrieNode();
        }

        cur = cur->nodes[c - 'a'];
      }

      cur->word = &word;
    }

    m = board.size();
    n = board[0].size();

    vector<string> ans;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(board, i, j, &root, ans);
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>>& board,
           int i,
           int j,
           TrieNode* node,
           vector<string>& ans) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] == '#') {
      return;
    }

    const char c = board[i][j];
    if (!node->nodes[c - 'a']) {
      return;
    }

    node = node->nodes[c - 'a'];
    if (node->word) {
      ans.push_back(*node->word);
      node->word = nullptr;
    }

    board[i][j] = '#';

    dfs(board, i, j + 1, node, ans);
    dfs(board, i, j - 1, node, ans);
    dfs(board, i + 1, j, node, ans);
    dfs(board, i - 1, j, node, ans);

    board[i][j] = c;
  }
};
// Runtime: 104 ms, faster than 71.28%
// Memory Usage: 36.7 MB, less than 48.84%

struct TrieNode {
  vector<TrieNode*> nodes;
  string* word;

  TrieNode() : nodes(26), word(nullptr) {}
  ~TrieNode() {
    for (auto node : nodes) {
      delete node;
    }
  }
};

class Solution {
  int m;
  int n;
  vector<string> ans;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode root;

    for (auto& word : words) {
      TrieNode* cur = &root;

      for (auto c : word) {
        auto& next = cur->nodes[c - 'a'];
        if (!next) {
          next = new TrieNode();
        }

        cur = next;
      }

      cur->word = &word;
    }

    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(board, i, j, &root);
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] == '#') {
      return;
    }

    const char c = board[i][j];
    if (!node->nodes[c - 'a']) {
      return;
    }

    node = node->nodes[c - 'a'];
    if (node->word) {
      ans.push_back(*node->word);
      node->word = nullptr;
    }

    board[i][j] = '#';

    dfs(board, i, j + 1, node);
    dfs(board, i, j - 1, node);
    dfs(board, i + 1, j, node);
    dfs(board, i - 1, j, node);

    board[i][j] = c;
  }
};
// Runtime: 116 ms, faster than 67.38%
// Memory Usage: 36.7 MB, less than 48.84%