/*
Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.


Solution:
    > Initially copy the int vector values to string vector
    > Sort the string vector. Append s1+s2 and s2+s1 and compare which ever is largestNumber
    > Print the values
*/




bool cmp(string s1,string s2){
    string ss1, ss2;

    ss1 = s1+s2;
    ss2 = s2+s1;
    return ss1>=ss2;            // Lexicographically Compare the values
}
string Solution::largestNumber(const vector<int> &A) {
    int zero_count =0;
    vector<string> res;

    for(int i=0;i<A.size(); i++){
        if(A[i] ==0)
            zero_count++;
        res.push_back(to_string(A[i]));
    }
    if(zero_count == A.size())
        return "0";
    sort(res.begin(), res.end(),cmp);

    for(int i=0;i<res.size(); i++){
        cout<<res[i];
    }
    return "";
}
