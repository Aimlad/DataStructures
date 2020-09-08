//fourSum
//GFG

#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef vector<vector<int>> vvi;

void twoSum(vi &nums,vvi &final,int n1, int start,int target){

    int left=start+1, right=nums.size()-1;
    while(left<right){
        if(nums[n1]+nums[start]+nums[left] + nums[right] ==target){
            vector<int> res;
            if(final.empty()){
                res.push_back(nums[n1]);
                res.push_back(nums[start]);
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                final.push_back(res);
            }
            else if(final[final.size()-1][0] != nums[n1] ||
                    final[final.size()-1][1] != nums[start] ||
                    final[final.size()-1][2] != nums[left] ||
                    final[final.size()-1][3] != nums[right]){
                    res.push_back(nums[n1]);
                    res.push_back(nums[start]);
                    res.push_back(nums[left]);
                    res.push_back(nums[right]);
                    final.push_back(res);
                }
            left++;
            right--;
            }
        else if(nums[n1] +nums[start]+nums[left] + nums[right] <target)
            left++;
        else
            right--;
    }
}
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,target;
	    cin>>n>>target;
	    vi nums(n);
	    for(int i=0;i<n;i++)
	        cin>>nums[i];


	    vvi final;
        vi temp;
        if(!nums.empty()){
            for(int i=0;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                for(int j=i+1;j<temp.size();j++){
                    twoSum(temp,final,i,j,target);
                    while(j+1<temp.size() && temp[j]==temp[j+1]) // if j is repeated
                        j++;
                }
                while(i+1<temp.size() && temp[i]==temp[i+1]) // if i is repeated
                        i++;
            }
        }
        if(!final.empty()){
        for(int i=0;i<final.size();i++){
            for(int j=0;j<final[0].size();j++){
                cout<<final[i][j]<<" ";
            }
            cout<<"$";
        }}
        else
            cout<<-1;
        cout<<endl;
	}
	return 0;
}
