/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    int compute(char op, int x, int y) {
        switch (op)
        {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        default:
            return 0;
        }
    }

    vector<int> diffWaysToCompute(string& expression, int low, int high) {
        vector<int> ans;
        int l = low;
        bool hasOp = false;
        int num = 0;
        while (l <= high) {
            if (expression[l] == '+'
            || expression[l] == '-'
            || expression[l] == '*') {
                hasOp = true;
                auto v1 = diffWaysToCompute(expression, low, l - 1);
                auto v2 = diffWaysToCompute(expression, l + 1, high);
                for (int x : v1) {
                    for (int y : v2) {
                        ans.emplace_back(compute(expression[l], x, y));
                    }
                }
            } else if (!hasOp) {
                num = (num * 10) + (expression[l] - '0');
            }
            l++;
        }
        if (!hasOp) {
            ans.emplace_back(num);
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return diffWaysToCompute(expression, 0, expression.length() - 1);
    }
};
// @lc code=end

