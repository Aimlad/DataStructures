/*
238. Product of Array Except Self
Given an array nums of n integers where n > 1,
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array
(including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space
for the purpose of space complexity analysis.)

Solution:
1: *** resultant array is not considered as extra space
2: Take ans array, start multiplying from start
3: Take temp value and set at 1. Keep multiplying temp with ans array, starting from end
4: Keep updating the value of temp
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }

        int temp=1;


        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]*temp;
            temp=temp*nums[i];
        }
        return ans;
    }
};
