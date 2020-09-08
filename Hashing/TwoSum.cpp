//  Leet Code
//Method 1 : Using One iteration map
// TC : O(n) SC: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map <int , int> mp;
        vector<int> res;
        for (int i=0;i<arr.size() ; i++){
            if(mp.find(target-arr[i])!= mp.end() && mp[target-arr[i]]!=i){
                res.push_back(mp[target-arr[i]]);
                res.push_back(i);
                return res;
            }
            mp[arr[i]]=i;
        }
        return res;
    }
};


//Method 2: Using Sorting
// TC: O(NlogN) SC: O(N)

vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> temp;
        vector<int> twoSum;
        if(!nums.empty()){
            for(int i=0;i<nums.size();i++){
                temp.push_back(make_pair(nums[i],i));
            }
            sort(temp.begin(),temp.end());

            auto left=temp.begin(), right=temp.end()-1;
            while(left<right){
                if(left->first+right->first==target){
                    twoSum.push_back(left->second);
                    twoSum.push_back(right->second);
                    break;
                }
                else if(left->first+right->first<target)
                    left++;
                else
                    right--;
            }

        }
	    return twoSum;
}
