/*
Max Sum Contiguous Subarray

Find the contiguous subarray within an array, A of length N which has the largest sum.
Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:
    6

Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.

*/


int Solution::maxSubArray(const vector<int> &A) {
    int i=0,j=1;
    int res=INT_MIN;
    int cur_sum=0;
    for(int i=0;i<A.size();i++){
        if(cur_sum <= 0 )
            cur_sum = A[i];
        else
            cur_sum+= A[i];

        res= max(res, cur_sum);
    }
    return res;
}
