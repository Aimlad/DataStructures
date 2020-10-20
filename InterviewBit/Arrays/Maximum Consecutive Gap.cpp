/*
Maximum Consecutive Gap
LC 164: Maximum gap

Given an unsorted array, find the maximum difference between
the successive elements in its sorted form.

Try to solve it in linear time/space.
Input : [1, 10, 5]
Output : 5

Solution:
- Main concept is the Pigeonhole principle
- There are n elements, so create n-1 buckets, which guarantees that
    one/more of the element will share the same buckets
- Now, find the max and min element of the array
- Now, divide the array into n-1 buckets on the basis of Gap
- What is Gap?
     Gap = (max - min)/ n-1;
- Take 2 buckets, one contains the min element in i'th buckets
    Other containing max element in the i'th bucket
- Initialize both with INT_MAX and INT_MIN respectively
- Now, search for the bucketNumber for each A[i] and insert it into the bucket
- How?
    BucketNumber of A[i] = A[i] - min / gap;
- Simply, now, we have min and max of all the made up buckets
- So, start from minbucket[0]-min
- update min to maxBucket[0] and minBucket to minBucket[1];
- Take max of the value and return the result



*/
int Solution::maximumGap(const vector<int> &A) {

    if(A.empty() || A.size() <2)
        return 0;

    int n = A.size();
    int mn = A[0];
    int mx = A[0];

    for(auto it=A.begin(); it!= A.end(); it++){
        mn = min(mn, *it);
        mx = max(mx, *it);
    }
    // If all the elements are same
    if(mn == mx)
        return 0;


    int gap = ceil(double(mx-mn)/(n-1));
    int minBucket[n-1];
    int maxBucket[n-1];
    for(int i=0; i< n-1; i++){
        minBucket[i]=INT_MAX;
        maxBucket[i]=INT_MIN;
    }

    for(int i=0;i<n; i++){
        // So that 0/n case does not occur
        if(A[i] == mn || A[i] == mx)
            continue;
        int bucketNo = (A[i] - mn)/ gap;
        minBucket[bucketNo] = min(minBucket[bucketNo], A[i]);
        maxBucket[bucketNo] = max(maxBucket[bucketNo], A[i]);
    }
    int prev= mn;
    int res = 0;
    for(int i=0; i< n-1; i++){
        if(maxBucket[i] == INT_MIN && minBucket[i] == INT_MAX)
            continue;
        res = max(minBucket[i] - prev,res);
        prev =maxBucket[i];
        }
    //cout<< mx<< "** "<< prev<<endl;
    res = max(res, mx-prev);

    return res;

}
