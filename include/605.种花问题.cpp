/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int black = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.emplace_back(0);
        flowerbed.emplace_back(1);
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                n -= (black - 1) / 2;
                black = 0;
            } else {
                black++;
            }
        }
        return n <= 0;
    }
};
// @lc code=end

