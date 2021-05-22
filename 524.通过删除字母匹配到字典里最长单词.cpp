/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        map<int, set<string>> ordered_dictionary;
        for (const auto& d : dictionary) {
            ordered_dictionary[0-d.length()].insert(d);
        }
        for (const auto& item : ordered_dictionary) {
            for (const auto& d : item.second) {
                int idx_in_s = 0, idx_in_d = 0;
                while (idx_in_s < s.length() && idx_in_d < d.length()) {
                    if (s[idx_in_s] == d[idx_in_d]) {
                        idx_in_d++;
                        idx_in_s++;
                    } else {
                        idx_in_s++;
                    }
                }
                if (idx_in_d == d.length()) {
                    return d;
                }
            }
        }
        return "";
    }
};
// @lc code=end

