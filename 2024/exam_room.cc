class ExamRoom {
    int n;
    vector<int> s;
public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (s.empty()) {
            s.push_back(0);
            return 0;
        }

        int d = max(s[0], n - 1 - s[s.size() - 1]);

        for (int i = 0; i < s.size() - 1; ++i) {
            d = max(d, (s[i + 1] - s[i]) / 2);
        }

        if (d == s[0]) {
            s.insert(s.begin(), 0);
            return 0;
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            if ((s[i + 1] - s[i]) / 2 == d) {
                s.insert(s.begin() + i + 1, (s[i + 1] + s[i]) / 2);
                return s[i + 1];
            }
        }

        s.push_back(n - 1);
        return n - 1;
    }
    
    void leave(int p) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == p) {
                s.erase(s.begin() + i);
            }
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
 // 128 ms
 // 27.19 MB
