/*
Tuesday, March 17th, 2026

Topic: Array

This is the fastest solution that uses O(1) space. We reverse the entire array, 
then reverse the first k elements and then reverse the rest of the elements.

ex:
original array: [1,2,3,4,5,6,7]
reverse 1: [7,6,5,4,3,2,1]
reverse 2: [5,6,7,4,3,2,1]
reverse 3: [5,6,7,1,2,3,4]
final array: [5,6,7,1,2,3,4]
*/

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};