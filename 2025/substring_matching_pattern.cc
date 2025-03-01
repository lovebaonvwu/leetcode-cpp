class Solution {
    public:
        bool hasMatch(string s, string p) {
            int idx = p.find('*');
            string head = p.substr(0, idx);
            string tail = p.substr(idx + 1);
    
            if (!head.empty() && !tail.empty()) {
                int idx = s.find(head);
                if (idx == string::npos) {
                    return false;
                }
    
                idx = s.find(tail, idx + head.size());
                if (idx == string::npos) {
                    return false;
                }
            } else if (head.empty()) {
                int idx = s.find(tail);
                if (idx == string::npos) {
                    return false;
                }
            } else if (tail.empty()) {
                int idx = s.find(head);
                if (idx == string::npos) {
                    return false;
                }
            }
    
            return true;
        }
    };
    // 3 ms
    // 9.07 MB