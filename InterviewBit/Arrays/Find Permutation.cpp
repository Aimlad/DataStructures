/*
Find Permutation

Given a positive integer n and a string s consisting only of letters D or I,
you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.

Input 1:

n = 3

s = ID

Return: [1, 3, 2]


Solution:
Now, starting with each character of the input string, we need to substitute an
appropriate number(from 1 to n) corresponding to each character(I or D).

So, Suppose we started with a set corresponding to all the elements from that we
need to make permutation(i.e all integer from 1 to n).

As I denotes the next number should be larger, we need to substitute smallest
remaining number from our set corresponding to subsequent I as it automatically makes the next element to be larger.

Similar things will happens with character D, we need to substitute the largest remaining number from our set.
*/

vector<int> Solution::findPerm(const string A, int B) {
    int start=1,end=B;
    vector<int> res;
    for(int i=0;i<A.length();i++){
        if(A[i] == 'I'){
            res.push_back(start);
            start++;
        }
        else if(A[i] == 'D'){
            res.push_back(end);
            end--;
        }
        else{
            vector<int> empty;
            return empty;
        }
    }
    if(start==end)
        res.push_back(start);
    return res;
}
