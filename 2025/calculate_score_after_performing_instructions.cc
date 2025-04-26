class Solution {
    public:
        long long calculateScore(vector<string>& instructions, vector<int>& values) {
            int n = values.size();
    
            vector<int> visited(n);
    
            long long ans = 0;
    
            for (int i = 0; i >= 0 && i < n && !visited[i];) {
                visited[i] = true;
    
                if (instructions[i] == "jump") {
                    i += values[i];
                } else {
                    ans += values[i++];
                }
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)