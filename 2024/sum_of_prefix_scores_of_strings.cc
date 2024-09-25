class TrieNode {
public:
    TrieNode() : prefixCount(0) {
        memset(next, 0, sizeof(next));
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }

    friend class Trie;
private:
    TrieNode* next[26];
    int prefixCount;
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
            ++cur->prefixCount;
        }
    }

    int search(const string& s) {
        int ret = 0;

        TrieNode* cur = root;

        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                break;
            }
            
            cur = cur->next[c - 'a'];
        }

        ret += cur->prefixCount;

        return ret;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie root;
        for (auto word : words) {
            root.insert(word);
        }

        vector<int> ans;
        for (auto word : words) {
            string prefix;
            int count = 0;
            for (auto c : word) {
                prefix += c;
                count += root.search(prefix);
            }

            ans.push_back(count);
        }

        return ans;
    }
};
// Time Limit Exceeded

class TrieNode {
public:
    TrieNode() : prefixCount(0) {
        memset(next, 0, sizeof(next));
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }

    friend class Trie;
private:
    TrieNode* next[26];
    int prefixCount;
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
            ++cur->prefixCount;
        }
    }

    int search(const string& s) {
        int ret = 0;

        TrieNode* cur = root;

        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                break;
            }
            
            cur = cur->next[c - 'a'];
        }

        ret += cur->prefixCount;

        return ret;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie root;
        for (auto word : words) {
            root.insert(word);
        }

        unordered_map<string, int> cached;

        vector<int> ans;
        for (auto word : words) {
            string prefix;
            int count = 0;
            for (auto c : word) {
                prefix += c;
                if (cached.find(prefix) == cached.end()) {
                    cached[prefix] = root.search(prefix);
                }
                count += cached[prefix];
            }

            ans.push_back(count);
        }

        return ans;
    }
};
// Time Limit Exceeded

class TrieNode {
public:
    TrieNode() : prefixCount(0) {
        memset(next, 0, sizeof(next));
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }

    friend class Trie;
private:
    TrieNode* next[26];
    int prefixCount;
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
            ++cur->prefixCount;
        }
    }

    int search(const string& s) {
        int ret = 0;

        TrieNode* cur = root;

        for (auto c : s) {
            if (!cur->next[c - 'a']) {
                break;
            }
            
            cur = cur->next[c - 'a'];
            ret += cur->prefixCount;
        }

        return ret;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie root;
        for (auto word : words) {
            root.insert(word);
        }

        vector<int> ans;
        for (auto word : words) {
            ans.push_back(root.search(word));
        }

        return ans;
    }
};
// 945 ms
// 733.42 MB
