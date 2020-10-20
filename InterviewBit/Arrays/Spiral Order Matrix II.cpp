/*
Spiral Order Matrix II
https://www.interviewbit.com/problems/spiral-order-matrix-ii

*/

vector<vector<int> > Solution::generateMatrix(int N) {
    int count =1;
    vector<vector<int> > A(N,vector<int> (N, 0));

    int i=0,j=0;
    int re=N, ce=N, rs=0, cs=0;
    while(count < N*N+1){
        for(;j<ce;j++){
            A[i][j]=count;
            count++;
        }
        rs++;i++;j--;
        for(;i<re;i++){
            A[i][j]=count;
            count++;
        }
        ce--;i--;j--;
        for(;j>=cs;j--){
            A[i][j]=count;
            count++;
        }
        re--;i--;j++;
        for(;i>=rs;i--){
            A[i][j]=count;
            count++;
        }
        cs++;j++;i++;

    }
    return A;
}

    /*
    vector<vector<int> > res(A);
    for(int i=0; i<A; i++) res[i].resize(A);

    int top = 0, bottom = A-1, left = 0, right = A-1, n = 1;
    while(n <= A*A){
        for(int i=left; i<=right; i++) res[top][i] = n++;
        top++;
        for(int i=top; i<=bottom; i++) res[i][right] = n++;
        right--;
        for(int i=right; i>=left; i--) res[bottom][i] = n++;
        bottom--;
        for(int i=bottom; i>=top; i--) res[i][left] = n++;
        left++;
    }
    return res;
    */
