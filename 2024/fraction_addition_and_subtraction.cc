class Solution {
public:
    string fractionAddition(string expression) {
        vector<char> signs;
        vector<int> numerators;
        vector<int> denominators;
        int num = 0;
        if (expression[0] == '-') {
            signs.push_back('-');
        } else {
            num = expression[0] - '0';
            signs.push_back('+');
        }

        bool before = true;
        for (int i = 1; i < expression.size(); ++i) {
            if (expression[i] == '+' || expression[i] == '-') {
                signs.push_back(expression[i]);
                if (before) {
                    numerators.push_back(num);
                } else {
                    denominators.push_back(num);
                }
                before = true;
                num = 0;
            } else if (expression[i] == '/') {
                numerators.push_back(num);
                before = false;
                num = 0;
            } else {
                num = num * 10 + (expression[i] - '0');
            }
        }

        if (before) {
            numerators.push_back(num);
        } else {
            denominators.push_back(num);
        }

        char prevSign = signs[0];
        int prevNumerator = numerators[0];
        int prevDenominator = denominators[0];

        for (int i = 1; i < signs.size(); ++i) {
            char curSign = signs[i];
            int curNumerator = numerators[i];
            int curDenominator = denominators[i];

            int tmpNumerator = prevNumerator * curDenominator;
            int tmpDenominator = prevDenominator * curDenominator;
            curNumerator *= prevDenominator;
            curDenominator *= prevDenominator;

            if (prevSign == curSign) {
                prevNumerator = tmpNumerator + curNumerator;
                prevDenominator = tmpDenominator;
            } else {
                prevNumerator = abs(tmpNumerator - curNumerator);
                prevDenominator = tmpDenominator;
            }

            if (curNumerator >= tmpNumerator) {
                prevSign = curSign;
            }
        }

        int gcd = __gcd(prevNumerator, prevDenominator);
        prevNumerator /= gcd;
        prevDenominator /= gcd;

        if (prevSign == '-') {
            return prevSign + to_string(prevNumerator) + "/" + to_string(prevDenominator);
        }

        return to_string(prevNumerator) + "/" + to_string(prevDenominator);
    }
};
// 3 ms
// 7.88 MB
