/*
Add One To Number

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]
as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    int carry=1;
    vector<int> res;
    for(int i= A.size()-1; i>=0; i--){
        // cout<<"yo";
        A[i]= A[i]+carry;
        carry=0;
        if(A[i] == 10){
            carry=1;
            A[i]= 0;
        }
    }
    if(carry == 1){
        int temp;
        for(int i=0;i<A.size();i++){
            temp=A[i];
            A[i]=carry;
            carry=temp;
        }
        A.push_back(carry);
    }
    int i=0;
    if(A[i]==0){
        while(A[i]==0 && i< A.size())
            i++;
        while(i<A.size()){
            res.push_back(A[i]);
            i++;
        }
    }
    return res;


}
