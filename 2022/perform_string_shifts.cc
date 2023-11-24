class Solution 
{
public:
    string stringShift(string s, vector<vector<int>>& shift) 
    {
        int move = 0;
        for (auto& s : shift)
        {
            if (s[0] == 0)
            {
                move -= s[1];
            }
            else
            {
                move += s[1];
            }
        }

        if (move == 0)
        {
            return s;
        }

        bool moveRight = move > 0;
        if (move < 0)
        {
            move = -move;
        }
        move %= s.size();

        if (moveRight)
        {
            string head = s.substr(s.size() - move);
            string tail = s.substr(0, s.size() - move);

            return head + tail;
        }
        else
        {
            string head = s.substr(move);
            string tail = s.substr(0, move);

            return head + tail;
        }
    }
};
// Runtime 6 ms
// Memory 7.6 MB
// 2022.12.16 at 奥盛大厦