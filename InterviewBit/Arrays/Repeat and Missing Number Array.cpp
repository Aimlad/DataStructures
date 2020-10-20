/*
Repeat and Missing Number Array
https://www.interviewbit.com/problems/repeat-and-missing-number-array/

Refer to IMAGE01.jpg for explanation


*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long n= A.size();
    long long int s1 = n*(n+1)/2;
    long long int s2 = 0;
    //Sum of squares
    long long int s3 = n*(n+1)*(2*n+1)/6;
    long long int s4 = 0;
    for(int i=0;i<n;i++){
        s2+=A[i];
        s4+= (long long int)A[i]*(long long int)A[i];
    }


    long long int P = s1-s2;
    long long int Q = (s3-s4)/ P;

    vector<int> ans;


    ans.push_back((Q-P)/2);
    ans.push_back((Q+P)/2);

    return ans;
}
