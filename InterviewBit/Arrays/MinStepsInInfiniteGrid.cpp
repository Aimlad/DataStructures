/*
Min Steps in Infinite Grid
You are in an infinite 2D grid where you can move in any of the 8 directions

 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which you need to cover the points..
Give the minimum number of steps in which you can achieve it. You start from the first point.

Input 1:

 A = [0, 1, 1]
 B = [0, 1, 2]

 Output 1:

 2
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if(A.size() != B.size())
        return -1;
    int dist=0;
    for(int i=0,j=0;i<A.size()-1,j<B.size()-1; i++,j++){
            dist= dist +max(abs(A[i]-A[i+1]), abs(B[j]-B[j+1]));
    }
    return dist;

}
