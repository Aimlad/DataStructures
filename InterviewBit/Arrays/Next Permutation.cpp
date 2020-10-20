/*
Next Permutation

Implement the next permutation, which rearranges numbers into the
numerically next greater permutation of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the
lowest possible order i.e., sorted in an ascending order.


/Explanation:
Lets assume an array [1 2 3].
Its next greater permutation is [1 3 2] followed by [2 1 3] and [2 3 1].
These are the possible permutations for this array where every permutation
is the next greater permutation of the previous permutation:
[1 2 3]
[1 3 2]
[2 1 3]
[2 3 1]
[3 1 2]
[3 2 1]


Solution:
1: Search from last till you find adjacent elements where A[i-1] < A[i]
2: Now store A[i-1] as temp
3: From the end till i-1, find the element which is just greater than A[i-1]
4: Swap elements and sort the remaining array

5: Initial array is sorted, just swap end elements
6: If array is reverse sorted, sort the array simply
*/

vector<int> Solution::nextPermutation(vector<int> &A) {
    vector<int> res;
    int i;
    for(i=0;i<A.size();i++){
        res.push_back(A[i]);
    }

    //Finding the culprit
    for(i=res.size()-1;i>0;i--){
        if(res[i-1]<res[i]){
            break;
        }
    }


    // If not found or already reverse sorted array, i.e nextPermutation N/A
    if(i==0){
        sort(res.begin(),res.end());
        return res;
    }
    else{
        for(int j=res.size()-1;j>=i;j--){
            if(res[j]>res[i-1]){
                swap(res[j],res[i-1]);
                sort(res.begin()+i,res.end());
                return res;
            }
        }
    }

}
