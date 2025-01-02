class Solution {
public:
    bool queryString(string s, int n) {
        while (n > 0) {
            auto p = bitset<32>(n--).to_string();
            if (s.find(p.substr(p.find('1'))) == string::npos) {
                return false;
            }
        }

        return true;
    }
};
// 0 ms
// 8.91 MB

