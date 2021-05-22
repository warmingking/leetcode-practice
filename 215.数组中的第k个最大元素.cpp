/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int idx = 1; // 第几大
            int element = nums[left];
            for (int l = left, r = l + 1; r < right; r++) {
                if (nums[r] < element) {
                    nums[l] ^= nums[r];
                    nums[r] ^= nums[l];
                    nums[l] ^= nums[r];
                    l++;
                } else {
                    idx++;
                }
            }
            nums[right - idx] = element;
            if (idx == k) {
                return element;
            } else if (idx < k) {
                k -= idx;
                right -= idx;
            } else {
                left = right - idx + 1;
            }
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> input{7,6,5,4,3,2,1};
    auto ans = s.findKthLargest(input, 2);
    return 0;
}
// @lc code=end

