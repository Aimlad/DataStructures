/*
Maximum Absolute Difference
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.


Solution:
f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways
(Since we are looking at max value, we don’t even care if the value becomes negative
as long as we are also covering the max value in some way).
(A[i] + i) - (A[j] + j)  --- (1)
(A[i] - i) - (A[j] - j)  --- (2)
(A[j] - j) -(A[i] - i)   --- (3)
(A[j] + j) - (A[i] + i)  --- (4)
Note that case 1 and 4 are equivalent and so are case 2 and 3.( because, we are finding for some i)
*/

int Solution::maxArr(vector<int> &A) {

    /* Brute Force Approach
    int res=-1,x;
    for(int i=0;i<A.size();i++){
        for(int j=i+1; j< A.size(); j++){
            x= abs(A[i]-A[j])+abs(i-j);
            res= max(res,x);
        }
    }
    return res;
    */

    int size= A.size();
    int max1 = INT_MIN,max2 = INT_MIN,min1 = INT_MAX,min2 = INT_MAX,ans= INT_MIN;
    for(int i=0;i<size; i++){
        max1= max(max1, A[i]+i);
        min1= min(min1, A[i]+i);
        max2= max(max2, A[i]-i);
        min2= min(min2, A[i]-i);
    }
    ans= max(ans,max1-min1);
    ans=max(ans,max2-min2);
    return ans;
}
