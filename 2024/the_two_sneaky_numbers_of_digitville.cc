class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> visited(101);
        vector<int> ans;
        for (auto n : nums) {
            if (visited[n]) {
                ans.push_back(n);
            }

            visited[n] = 1;
        }

        return ans;
    }
};
// 8 ms
// 25.50 MB
