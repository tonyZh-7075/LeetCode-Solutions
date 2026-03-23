#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowindex = 0;
        for (int fastindex = 0; fastindex < nums.size(); fastindex++)
        {
            if (val != nums[fastindex]) {
                nums[slowindex] = nums[fastindex];
                slowindex++;
            }
        }
        return slowindex;
    }
};