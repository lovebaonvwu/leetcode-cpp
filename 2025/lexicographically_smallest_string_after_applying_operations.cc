class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        string ans = s;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            ans = min(ans, cur);

            string add_s = cur;

            for (int i = 1; i < cur.size(); i += 2)
            {
                int d = ((cur[i] - '0') + a) % 10;
                add_s[i] = d + '0';
            }

            if (visited.find(add_s) == visited.end())
            {
                q.push(add_s);
                visited.insert(add_s);
            }

            int n = cur.size();
            string rotate_s = cur.substr(n - b) + cur.substr(0, n - b);

            if (visited.find(rotate_s) == visited.end())
            {
                q.push(rotate_s);
                visited.insert(rotate_s);
            }
        }

        return ans;
    }
};
// Time: O(V * n), where V is the number of unique strings reachable from the initial string s, and n is the length of the string.
// Space: O(V * n), to store the reachable strings in the queue and the visited set.