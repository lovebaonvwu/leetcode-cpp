class Solution {
    public:
        string smallestPalindrome(string s) {
            int n = s.size();
    
            string head = s.substr(0, n / 2);
            sort(begin(head), end(head));
            string body = (n & 1) ? string(1, s[n / 2]) : "";
            string tail = (n & 1) ? s.substr((n + 1) / 2) : s.substr(n / 2);
            sort(rbegin(tail), rend(tail));
    
            return head + body + tail;
        }
    };
    // Time: O(nlogn)
    // Space: O(n)