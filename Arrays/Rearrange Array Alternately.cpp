using namespace std; 

void rearrange(long long int arr[], int n){

  long int max_el=arr[n-1]+1;
  long int min_ind=0,max_ind=n-1;
  for(int i=0;i<n;i++){
    if(i%2==0){
      arr[i]+=(arr[max_ind] % max_el )*max_el;
      max_ind--;
    }
    else{
      arr[i]+=(arr[min_ind] % max_el )* max_el;
      min_ind++;
    }
  }

  for(int i=0;i<n;i++){
    arr[i]/=max_el;
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    rearrange(arr,n);
  }
}
