//Inversion of array

#include<bits/stdc++.h>
using namespace std;


long long int merge(int arr[],int tmp[],int beg, int mid, int end){
    int i=beg, j=mid,k=beg;
    long long int count=0;
    while((i<=mid-1) && (j<=end)){
        if(arr[i]<=arr[j])
            tmp[k++]= arr[i++];

        else{
            //cout<<arr[i]<<"--"<<arr[j];
            tmp[k++]=arr[j++];
            count+=mid-i;
            //cout<<"--"<<count<<endl;
        }
    }

    while(i<=mid-1)
        tmp[k++]=arr[i++];
    while(j<=end)
        tmp[k++]=arr[j++];

    for(i=beg;i<=end;i++){
        arr[i]=tmp[i];
    }
    return count;

}
long long int msort(int arr[],int tmp[],int beg,int end){
    long long int sum=0;
    if(beg<end){
        int mid=(beg+end)/2;
        sum+=msort(arr,tmp,beg,mid);
        sum+=msort(arr,tmp,mid+1,end);
        sum+=merge(arr,tmp,beg,mid+1,end);
    }
    return sum;
}
long long int mergeSort(int arr[],int n){
    int tmp[n];
    return msort(arr,tmp,0,n-1);
}
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    cout<<mergeSort(arr,n)<<"\n";
	}
	return 0;
}
