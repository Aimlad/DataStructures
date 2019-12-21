//https://practice.geeksforgeeks.org/problems/count-the-triplets/0

using namespace std;


int partition(int arr[], int low, int high){
    int pivot =arr[low];
    int i=low-1, j=high+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        
        do{
            j--;
        }while(arr[j]>pivot);
        
        if(i>=j)
            return j;
        
        swap(arr[i], arr[j]);
    }
}

int partition_r(int arr[],int low,int high){
    srand(time(NULL));
    
    int random= low+ rand() % (high-low);
    swap(arr[random],arr[low]);
    
    return partition(arr,low,high);
}

void Qsort(int arr[], int beg, int end){
    if(beg<end){
        int pi = partition_r(arr,beg,end);
        
        Qsort(arr,beg,pi);
        Qsort(arr,pi+1,end);
    }
}
int main(){
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        sort(arr,arr+n);
        // for(int i=0;i<n;i++)
        //      cout<<arr[i]<<" ";
        int count=0;
        for(int k=n-1;k>=2;k--){
            for(int i=0,j=k-1;i<j;){
                if(arr[i]+arr[j]==arr[k]){
                    count++;
                    i++;j--;
                }
                else if(arr[i]+arr[j]>arr[k])
                    j--;
                else
                    i++;
            }
        }
        if(count > 0)
            cout<<count<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}