class TrieNode
{
public:
    TrieNode()
    {
    }

private:
    friend class Trie;
    unordered_map<string, TrieNode *> next;
    string s;
};

class Trie
{
public:
    Trie() : root(new TrieNode) {}

    void insert(const vector<string> &path)
    {
        TrieNode *cur = root;
        for (auto &s : path)
        {
            if (cur->next.find(s) == cur->next.end())
            {
                cur->next[s] = new TrieNode;
            }

            cur = cur->next[s];
        }
    }

    void build()
    {
        build(this->root);
    }

    void add()
    {
        add(this->root);
    }

    vector<vector<string>> getRet()
    {
        return ret;
    }

private:
    void build(TrieNode *root)
    {
        if (root->next.empty())
        {
            return;
        }

        vector<string> v;
        for (auto &[folder, child] : root->next)
        {
            build(child);
            v.push_back(folder + "(" + child->s + ")");
        }

        sort(begin(v), end(v));

        for (auto subfolder : v)
        {
            root->s += move(subfolder);
        }

        ++freq[root->s];
    }

    void add(TrieNode *node)
    {
        if (freq[node->s] > 1)
        {
            return;
        }

        if (!path.empty())
        {
            ret.push_back(path);
        }

        for (auto &[folder, child] : node->next)
        {
            path.push_back(folder);
            add(child);
            path.pop_back();
        }
    }

    TrieNode *root;
    unordered_map<string, int> freq;
    vector<vector<string>> ret;
    vector<string> path;
};

class Solution
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Trie tree;
        for (auto &path : paths)
        {
            tree.insert(path);
        }

        tree.build();
        tree.add();

        return tree.getRet();
    }
};
// Time: O(n)
// Space: O(n)