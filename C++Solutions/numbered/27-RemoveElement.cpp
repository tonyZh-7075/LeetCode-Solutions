/*
Monday, March 30th, 2026

Topic: Array, Two Pointers

Basic Idea:
We can use two pointers to solve this problem.
1. We can use a pointer to iterate through the array and another pointer to keep track of the position where we can place the next element that is not equal to val.
2. We can iterate through the array and whenever we encounter an element that is not equal to val, we can place it at the position indicated by the second pointer and increment the second pointer.
3. We can return the value of the second pointer, which will represent the new size of the array.

Time Complexity: O(n), where n is the number of elements in the array.

Notes:
- The order of the elements can be changed.
- The elements that are equal to val are not considered in the new array.
*/

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