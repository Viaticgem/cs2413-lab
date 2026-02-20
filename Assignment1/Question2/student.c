#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
    int n = numsSize;
    int i, j;
    int max = nums[0];   // Initialize to first element
    int amount;

    for (i = 0; i < n; i++) {
        amount = 1;      // Count nums[i] itself
        for (j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                amount++;
            }
        }
        if (amount > n / 2) {
            max = nums[i];
            break;       // Majority element found, can exit early
        }
    }

    return max;
}
