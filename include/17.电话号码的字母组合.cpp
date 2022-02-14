/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    vector<string> num2chars{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void doCombination(const string& digits, const string& prifix, vector<string>& ans) {
        auto len = prifix.length();
        if (len == digits.length()) {
            ans.emplace_back(prifix);
            return;
        }
        for (auto c : num2chars[digits[len] - '2']) {
            auto tmp = prifix + c;
            doCombination(digits, tmp, ans);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> ans;
        doCombination(digits, "", ans);
        return ans;
    }
};
// @lc code=end

