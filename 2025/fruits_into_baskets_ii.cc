class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (baskets[j] != -1) {
                        if (baskets[j] >= fruits[i]) {
                            ++cnt;
                            baskets[j] = -1;
                            break;
                        }
                    }
                }
            }
    
            return n - cnt;
        }
    };
    // 0 ms
    // 48.94 MB
