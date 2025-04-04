class Solution {
    public:
        bool isSelfCrossing(vector<int>& distance) {
            distance.insert(distance.begin(), 4, 0);
            int n = distance.size();
    
            int i = 4;
            while (i < n && distance[i] > distance[i - 2]) {
                ++i;
            }
    
            if (i == n) {
                return false;
            }
    
            if (distance[i] >= distance[i - 2] - distance[i - 4]) {
                distance[i - 1] = distance[i - 1] - distance[i - 3];
            }
    
            ++i;
    
            while (i < n && distance[i] < distance[i - 2]) {
                ++i;
            }
    
            return !(i == n);
        }
    };
    // Time: O(n)
    // Space: O(1)