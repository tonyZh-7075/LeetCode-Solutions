#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_end = nums.size() - 1;
        int furthest_left_can_go = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (cur_end - i <= nums[i]) {
                furthest_left_can_go = i;
            }
        }
        if (furthest_left_can_go == 0) {
            return true;
        } else if (furthest_left_can_go == nums.size() - 1){
            return false;
        } else {
            vector<int> sub(nums.begin(), nums.begin() + furthest_left_can_go + 1);
            return (canJump(sub));
        }
    }
};