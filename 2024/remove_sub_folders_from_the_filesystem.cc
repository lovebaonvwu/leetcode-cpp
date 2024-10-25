class TrieNode {
public:
    TrieNode() : is_folder(false), root_folder("") {

    }
private:
    friend class Trie;
    unordered_map<string, TrieNode*> children;
    string root_folder;
    bool is_folder;
};

class Trie {
public:
    Trie() : root(new TrieNode) {}

    void insert(const string& s) {
        TrieNode* cur = root;

        int start = 1;
        for (auto index = s.find("/", start);  index != string::npos;) {
            string path = s.substr(start, index - start);
            start = index + 1;
            index = s.find("/", start);

            if (cur->children.find(path) == cur->children.end()) {
                TrieNode* node = new TrieNode;
                cur->children[path] = node;
            }

            cur = cur->children[path];
        }

        cur->is_folder = true;
        cur->root_folder = s.substr(0, s.size() - 1);
    }

    string find(const string& s) {
        TrieNode* cur = root;

        int start = 1;
        for (auto index = s.find("/", start); index != string::npos;) {
            string path = s.substr(start, index - start);
            start = index + 1;
            index = s.find("/", start);

            if (cur->children.find(path) == cur->children.end()) {
                return s.substr(0, s.size() - 1);
            }

            cur = cur->children[path];
            if (cur->is_folder) {
                return cur->root_folder;
            }
        }

        return s.substr(0, s.size() - 1);
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for (auto& f : folder) {
            trie.insert(f + "/");
        }

        unordered_set<string> st;
        for (auto& f : folder) {
            st.insert(trie.find(f + "/"));
        }

        vector<string> ans;
        for (auto& s : st) {
            ans.push_back(s);
        }

        return ans;
    }
};
// 287 ms
// 107.64 MB