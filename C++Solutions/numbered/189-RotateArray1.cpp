/*
Tuesday, March 17th, 2026

Topic: Array

This is a solution that uses extra space. We create a new array and fill it with the rotated values.

ex:
original array: [1,2,3,4,5,6,7]
k = 3
duplicate the array: [1,2,3,4,5,6,7,1,2,3,4,5,6,7]
take the elements from index 4 to index 10 (exclusive) and put them in the
new array: [5,6,7,1,2,3,4]

this is very efficient time wise but takes O(n) space. 
*/

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int newk = k % n;
        int i = nums.size() - newk;
        nums.insert(nums.end(), nums.begin(), nums.end());

        nums = vector<int>(nums.begin() + i, nums.begin() + i + n);
    }
};