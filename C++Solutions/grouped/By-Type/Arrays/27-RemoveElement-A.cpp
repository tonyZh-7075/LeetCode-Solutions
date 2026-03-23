#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cursize = nums.size();
        for (int i = 0; i < cursize; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < nums.size(); j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                cursize--;
            }
        }
        return cursize;
    }
};