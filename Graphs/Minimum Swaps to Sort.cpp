//Minimum Swaps to Sort
//https://practice.geeksforgeeks.org/problems/minimum-swaps/1
//Basic Idea: Selection Sort


/* You are required to complete this method */
int minSwaps(int arr[], int N){
    /*Your code here */
    int count=0;
    for(int i=0;i<N; i++){
        int j,k;
        for(j=k=i; j<N;j++){
            if(arr[j] < arr[k])
                k=j;
        }

        if(i != k){
            swap(arr[i],arr[k]);
            count++;
        }
    }
    return count;
}
