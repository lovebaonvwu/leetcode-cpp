class Solution {
    public:
        bool hasSameDigits(string s) {
            vector<int> d;
            for (auto c : s) {
                d.push_back(c - '0');
            }
    
            while (d.size() > 2) {
                vector<int> t;
                for (int i = 0; i < d.size() - 1; ++i) {
                    t.push_back((d[i] + d[i + 1]) % 10);
                }
                swap(d, t);
            }
    
            return d[0] == d[1];
        }
    };
    // 19 ms
    // 16.98 MB
