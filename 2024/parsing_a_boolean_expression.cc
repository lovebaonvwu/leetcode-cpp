class Solution {

    char evaluate(const vector<char>& values, char op) {
        if (op == '!') {
            return values[0] == 't' ? 'f' : 't';
        } else if (op == '&') {
            for (auto val : values) {
                if (val == 'f') {
                    return 'f';
                }
            }

            return 't';
        } else if (op == '|') {
            for (auto val : values) {
                if (val == 't') {
                    return 't';
                }
            }

            return 'f';
        }

        return 'f';
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (char ch : expression) {
            if (ch == ',') {
                continue;
            }

            if (ch == ')') {
                vector<char> values;
                while (!stk.empty() && stk.top() != '(') {
                    values.push_back(stk.top());
                    stk.pop();
                }

                stk.pop();
                char op = stk.top();
                stk.pop();

                stk.push(evaluate(values, op));
            } else {
                stk.push(ch);
            }
        }

        return stk.top() == 't';
    }
};
// 10 ms
// 11.84 MB

