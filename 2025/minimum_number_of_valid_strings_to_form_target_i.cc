class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
        word = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }
private:
    friend class Trie;
    TrieNode* next[26];
    bool word;
};

class Trie {
public:
    Trie() : root(new TrieNode) {

    }

    ~Trie() {
        delete root;
    }

    void insert(const string& s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new TrieNode;
            }
            cur = cur->next[c - 'a'];
        }
        cur->word = true;
    }

    bool find(const string& s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                return false;
            }

            cur = cur->next[c - 'a'];
        }

        return true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie root;
        for (auto& word : words) {
            root.insert(word);
        }

        int n = target.size();

        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (root.find(target.substr(j, i - j))) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] == INT_MAX / 2 ? -1 : dp[n];
    }
};
// Memory Limit Exceeded

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
        word = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }
private:
    friend class Trie;
    TrieNode* next[26];
    bool word;
};

class Trie {
public:
    Trie() : root(new TrieNode) {

    }

    ~Trie() {
        delete root;
    }

    void insert(const string& s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new TrieNode;
            }
            cur = cur->next[c - 'a'];
        }
        cur->word = true;
    }

    bool find(const string& s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                return false;
            }

            cur = cur->next[c - 'a'];
        }

        return true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie root;
        for (auto& word : words) {
            root.insert(word);
        }

        int n = target.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] == INT_MAX) {
                    continue;
                }
                if (root.find(target.substr(j, i - j))) {
                    dp[i] = min(dp[i], dp[j] + 1);
                    break;
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
// Memory Limit Exceeded

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
        word = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }
private:
    friend class Trie;
    TrieNode* next[26];
    bool word;
};

class Trie {
public:
    Trie() : root(new TrieNode) {

    }

    ~Trie() {
        delete root;
    }

    void insert(const string& s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new TrieNode;
            }
            cur = cur->next[c - 'a'];
        }
        cur->word = true;
    }

    bool find(const string& s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                return false;
            }

            cur = cur->next[c - 'a'];
        }

        return true;
    }

    int getMaxMatchLength(const string& s) {
        TrieNode* cur = root;
        int ret = 0;
        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                break;
            }

            cur = cur->next[c - 'a'];
            ++ret;
        }

        return ret;
    }
private:
    TrieNode* root;
};

class Solution {

    int dfs(vector<int>& cached, Trie& root, const string& target, int idx) {
        if (idx == target.size()) {
            return 0;
        }

        if (cached[idx] != -1) {
            return cached[idx];
        }

        int maxMatchLength = root.getMaxMatchLength(target.substr(idx));
        int ret = INT_MAX;
        for (int i = 1; i <= maxMatchLength; ++i) {
            int len = dfs(cached, root, target, idx + i);
            if (len != INT_MAX) {
                ret = min(ret, 1 + len);
            }
        }

        return cached[idx] = ret;
    }

public:
    int minValidStrings(vector<string>& words, string target) {
        Trie root;
        for (auto& word : words) {
            root.insert(word);
        }

        int n = target.size();
        vector<int> cached(n, -1);

        int ans = dfs(cached, root, target, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};
// 1405 ms
// 476.31 MB