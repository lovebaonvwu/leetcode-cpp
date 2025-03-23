class Solution {
    public:
        int maxContainers(int n, int w, int maxWeight) {
            return min(n*n, maxWeight / w);
        }
    };
    // Time: O(1)
    // Space: O(1)