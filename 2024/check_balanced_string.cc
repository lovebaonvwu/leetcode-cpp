class Solution {
public:
    bool isBalanced(string num) {
        int odd = 0;
        int even = 0;
        int n = num.size();
        for (int i = 0; i < n; i += 2) {
            odd += (num[i] - '0');
            even += (i + 1 < n ? num[i + 1] - '0' : 0);
        }
        
        return odd == even;
    }
};
// 0 ms
// 8.15 MB
