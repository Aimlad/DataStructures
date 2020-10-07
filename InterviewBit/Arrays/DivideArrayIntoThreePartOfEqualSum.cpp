/*

Partitions - Interview Bit
Count the number of ways to divide an array into three contiguous parts having equal sum

Input 1:
 A = 5
 B = [1, 2, 3, 0, 3]
Input 2:
 A = 4
 B = [0, 1, -1, 0]

 Output 1:
 2
Output 2:
 1


 Solution:
 >> If sum of all the elements of the array is not divisible by 3, return 0.

 >> It is obvious that the sum of each part of each contiguous part will be equal
    to the sum of all elements divided by 3.

 >> Let’s create an array cnt[ ], where cnt[ i ] equals 1, if the sum of elements from
    i-th to n-th equals Array_Sum/3 else 0. Now, calculate the cumulative sum of the cnt array from the last index.

 >> Thus, we receive very simple solution: for each prefix of initial array 1…i with
    the sum that equals Array_Sum/3 we need to add to the answer sums[ i+2 ].


*/


int Solution::solve(int A, vector<int> &B) {
    long long sum=0;
    for(int i=0;i<A; i++){
        sum+=B[i];
    }

    if(sum % 3 != 0)
        return 0;

    sum = sum/3;
    int count[A], temp=0;
    memset(count,0,sizeof(count));
    for(int i=A-1; i>=0;i--){
        temp+=B[i];
        if(temp == sum)
            count[i]=1;
    }

    temp=0;

    for(int i=A-2; i>=0;i--){
        count[i]+=count[i+1];
    }
    int res=0;
    for(int i=0;i+2 <A; i++){
        temp+=B[i];
        if(temp == sum)
            res+=count[i+2];
    }

    return res;

}
