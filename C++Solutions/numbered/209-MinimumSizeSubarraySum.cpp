#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int largest = INT32_MAX;
        int windowSum = 0;
        int i = 0;
        int windowLength = 0;

        for (int j = 0; j < nums.size(); j++) {
            windowSum += nums[j];

            while (windowSum >= target) {
                windowLength = j - i + 1;
                largest = min(largest, windowLength);
                windowSum -= nums[i];
                i++;
            }
        }

        if (largest == INT32_MAX) {
            return 0;
        } else {
            return largest;
        }
    }
};