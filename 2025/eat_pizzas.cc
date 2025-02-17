class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            sort(begin(pizzas), end(pizzas));
    
            int n = pizzas.size();
            int days = n / 4;
    
            long long ans = 0;
            
            int oddDays = (days + 1) / 2;
            int evenDays = days / 2;
            for (int i = n - 1, cnt = oddDays; i >= 0 && cnt > 0; --i, --cnt) {
                ans += pizzas[i];
            }
    
            for (int i = n - 1 - oddDays - 1; i >= 3 * oddDays && evenDays > 0; i -= 2 , --evenDays) {
                ans += pizzas[i];
            }
    
            return ans;
        }
    };
    // 75 ms
    // 180.20 MB

