//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
using namespace std;
int main()
 {
	//code
	int tc;
	int noOfElements,target_sum,final_sum,cur_sum=0;
	cin>>tc;
	while(tc--){
	    cin>>noOfElements>>target_sum;
	    int arr[noOfElements];
	   	
	   	for(int i=0;i<noOfElements;i++){
	        cin>>arr[i];
	    }
	    cur_sum=0;
	    bool flag=false;
	    int i=0,j=0;
	    
	    for(i=0,j=0;j<noOfElements;){
	        //cout<<"*****"<<cur_sum<<"*****"<<endl;
	        if(cur_sum==target_sum){
	        	flag=true;
	        	cout<<i+1<<" "<<j<<endl;
	            break;
	        }
	        else if(cur_sum<target_sum){
	            cur_sum+=arr[j];
	            j++;
	        }
	        else{
	            cur_sum=cur_sum-arr[i];
	            i++;
	        }
	    }
	    while(i<j && cur_sum!=target_sum){
	    	cur_sum-=arr[i];
	    	i++;
	    }
		if(flag==false && cur_sum==target_sum){
			cout<<i+1<<" "<<j<<endl;
		}
		else if(cur_sum!=target_sum)
		    cout<<-1<<endl;
	}
	return 0;
	
}