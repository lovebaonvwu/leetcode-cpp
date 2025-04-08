class Solution {
    public:
        bool isRectangleCover(vector<vector<int>>& rectangles) {
            set<pair<int, int>> st;
    
            long long area = 0;
            for (auto& rect : rectangles) {
                pair<int, int> p1 = {rect[0], rect[1]};
                pair<int, int> p2 = {rect[2], rect[1]};
                pair<int, int> p3 = {rect[2], rect[3]};
                pair<int, int> p4 = {rect[0], rect[3]};
    
                for (auto& p : {p1, p2, p3, p4}) {
                    const auto& ret = st.insert(p);
                    if (!ret.second) {
                        st.erase(p);
                    }
                }
    
                area += 1LL * (p3.first - p1.first) * (p3.second - p1.second);
            }
    
            if (st.size() != 4) {
                return false;
            }
    
            const auto& p1 = *st.begin();
            const auto& p3 = *st.rbegin();
    
            return area == 1LL * (p3.first - p1.first) * (p3.second - p1.second);
        }
    };
    // Time: O(n)
    // Space: O(n)