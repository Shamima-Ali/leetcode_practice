class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '-' || c == '+' || c == '*') {
                string a = expression.substr(0, i);
                string b = expression.substr(i+1);

                vector<int> al = diffWaysToCompute(a);
                vector<int> bl = diffWaysToCompute(b);

                for (int x : al) {
                    for (int y : bl) {
                        if (c == '-') {
                            res.push_back(x-y);
                        } else if (c == '+') {
                            res.push_back(x+y);
                        } else if (c == '*') {
                            res.push_back(x*y);
                        }
                    }
                }

            }
        }

        if (res.size() == 0) {
            res.push_back(stoi(expression));
        }

        return res;
    }
};