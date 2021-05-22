/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> last_index;
        for (int i = 0; i < s.length(); ++i) {
            last_index[s[i]] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            end = max(end, last_index[s[i]]);
            if (end == i) {
                ans.emplace_back(end - start + 1);
                start = end = end + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    auto ans = s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}