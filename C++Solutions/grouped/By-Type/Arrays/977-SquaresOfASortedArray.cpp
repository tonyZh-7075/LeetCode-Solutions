class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int cur = nums.size() - 1;
        vector<int> solution(nums.size(), 0);

        for (int i = 0, int j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums [i] < nums[j] * nums[j]) {
                solution[cur] = nums[j] * nums[j];
                cur--;
                j--;
            } else {
                solution[cur] = nums[i] * nums[i];
                cur--;
                i++;
            }
        }
        return solution;
    }
};