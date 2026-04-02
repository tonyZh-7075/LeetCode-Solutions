/*
Thursday, April 2nd, 2026

Topic: Array, Brute Force

Basic Idea:
To solve the Two Sum problem, we can use a brute-force approach by checking all possible pairs
of numbers in the array to see if they add up to the target. We can use two nested loops to iterate through the array and check each pair of numbers. If we find a pair that sums up to the target, we can return their indices.

Time Complexity: O(n^2), where n is the number of elements in the input array, since we need to check all pairs of numbers.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};