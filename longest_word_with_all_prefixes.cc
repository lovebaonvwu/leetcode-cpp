class Node
{
public:
    map<char, Node*> children;
    string word;
    bool isWord;

    Node() : children({}), word(""), isWord(false)
    {

    }
};

class Solution 
{
    Node* root;
    string ans;

    void Insert(const string& word)
    {
        Node* cur = root;
        for (auto c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                cur->children[c] = new Node;
            }
            cur = cur->children[c];
        }
        cur->word = word;
        cur->isWord = true;
    }

    void dfs(Node* root)
    {
        if (!root)
        {
            return;
        }

        for (auto& [c, next] : root->children)
        {
            if (next->isWord)
            {
                dfs(next);
                if (next->word.size() > ans.size())
                {
                    ans = next->word;
                }
            }
        }
    }
public:
    string longestWord(vector<string>& words) 
    {
        root = new Node;

        for (auto& w : words)
        {
            Insert(w);
        }

        dfs(root);

        return ans;
    }
};
// Runtime 243 ms
// Memory 88 MB
// 2022.12.15 at 奥盛大厦