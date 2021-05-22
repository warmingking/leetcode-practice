/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    bool isNear(string& s1, string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.emplace_back(beginWord);
        // wordList.emplace_back(endWord);
        int len = wordList.size();
        vector<bool> marked(len, false);
        queue<string> q;
        q.push(beginWord);
        marked[len - 1] = true;
        int level = 1;
        while (!q.empty()) {
            level++;
            auto qs = q.size();
            while (qs--) {
                string s = q.front();
                q.pop();
                for (int i = 0; i < len; ++i) {
                    if (marked[i]) {
                        continue;
                    }
                    if (isNear(s, wordList[i])) {
                        if (wordList[i] == endWord) {
                            return level;
                        }
                        marked[i] = true;
                        q.push(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

