/*
//Find Duplicate in Array
https://www.interviewbit.com/problems/find-duplicate-in-array/

Given a read only array of n + 1 integers between 1 and n,
find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:
[3 4 1 4 2]
Sample Output:
1
*/


int Solution::repeatedNumber(const vector<int> &A) {
    /*
    int n = A.size();
    long long int sum = 0;
    for(int i = 0; i<n; i++){
        sum += A[i];
    }
    long long int m = n-1;
    long long int total = (m * (m+1)) / 2;
    cout<<sum-total;
    return sum - total;
    */

    // Floyd Cycle Detection method
    // Same like we do in LL;

    int tortoise = A[0];
    int hare = A[0];

    do{
        tortoise = A[tortoise];
        hare = A[A[hare]];
    }while(tortoise != hare);
    tortoise = A[0];

    while(tortoise != hare){
        tortoise = A[tortoise];
        hare = A[hare];
    }
    return tortoise;
}
