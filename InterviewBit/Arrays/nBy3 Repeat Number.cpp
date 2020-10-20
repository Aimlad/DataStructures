/*
N/3 Repeat Number
https://www.interviewbit.com/problems/n3-repeat-number/

You’re given a read only array of n integers. Find out if any integer occurs
more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

Input : [1 2 3 1 1]
Output : 1
1 occurs 3 times which is more than 5/3 times.


Solution:
----Moore's Voting Algorithm----
The Boyer–Moore majority vote algorithm is an algorithm for finding
the majority of a sequence of elements using linear time and constant space

- Majority element is an element that occurs in an array more than n/k times;
- Basic idea find the candidate who can be majority element
- Note: There can be at max, k-1 number of candiates
        eg: n/2 = then candidate = 1//
            n/3 = then candiate = 2
-How to find candiate?
    - Take k-1 counters for the k-1 candidates
    - Iterate for all elements and if A[i] = candidate(x), increment count
        else decrement count;
    - If count == 0, i.e, that element is not the candidate
    - change the value of candidate to A[i] and set count =1;

-Now Iterate once again and find the counts of all the candidates
- Whichever is > n/k, return that candidate value
- Else, return -1

*/

int Solution::repeatedNumber(const vector<int> &A) {
    //Moore's Voting algo
    //For 3 element
    ////Basically states that there can be  2 element which has more than n/2 elements
    int majority_element1=0, count1=0,majority_element2=0, count2=0;
    for(int i=0;i<A.size(); i++){
        if(majority_element1 == A[i])   count1++;
        else if(majority_element2 == A[i])   count2++;
        else if(count1 == 0){
            majority_element1 = A[i];
            count1++;
        }
        else if(count2 == 0){
            majority_element2 = A[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 =0,count2 =0;
    for(int i=0; i<A.size() ; i++){
        if(A[i]== majority_element1)count1++;
        if(A[i]== majority_element2)count2++;
    }
    if(count1 > A.size()/3)  return majority_element1;
    if(count2 > A.size()/3)  return majority_element2;
    return -1;
}

//     //For 2 elements
//     //Basically states that there can be only 1 element which has more than n/2 elements
//     int majority_element=A[0], count =1;
//     for(int i=1;i<A.size(); i++){
//         if(majority_element == A[i]){
//             count++;
//         }
//         else
//             count--;

//         if(count == 0){
//             majority_element = A[i];
//             count = 1;
//         }
//     }
//     count =0;
//     for(int i=0; i<A.size() ; i++){
//         if(A[i]== majority_element)
//             count++;
//     }
//     if(count > floor(A.size()/3))
//         return majority_element;
//     return -1;

// }
