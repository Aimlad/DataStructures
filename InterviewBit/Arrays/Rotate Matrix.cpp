/*
Rotate Matrix
https://www.interviewbit.com/problems/rotate-matrix/

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Solution:
1: Transform the matrix
2: Reverse row
*/

void Solution::rotate(vector<vector<int> > &A) {
    for(int i=0;i<A.size();i++){
        for(int j=0; j<i;j++){
            swap(A[i][j],A[j][i]);
        }
    }
    for(int i=0;i<A.size();i++){
        int j=0, k=A.size()-1;
        while(j<k){
            swap(A[i][j], A[i][k]);
            j++;k--;
        }
    }

}
