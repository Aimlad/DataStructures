//ThreeSum
//https://leetcode.com/problems/3sum/
// Sum =0

class Solution {
public:
    void twoSum(vector <int> &nums,vector<vector<int>> &final, int start){

        int left=start+1, right=nums.size()-1;
        while(left<right){
            if(nums[start]+nums[left] + nums[right] ==0){
                vector<int> res;
                if(final.empty()){
                    res.push_back(nums[start]);
                    res.push_back(nums[left]);
                    res.push_back(nums[right]);
                    final.push_back(res);
                }
                else if(final[final.size()-1][0] != nums[start] ||
                      final[final.size()-1][1] != nums[left] ||
                        final[final.size()-1][2] != nums[right]){
                        res.push_back(nums[start]);
                        res.push_back(nums[left]);
                        res.push_back(nums[right]);
                        final.push_back(res);
                    }
                left++;
                right--;
                }
            else if(nums[start]+nums[left] + nums[right] <0)
                left++;
            else
                right--;
            }
        }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> final;
        vector<int> temp;
        if(!nums.empty()){
            for(int i=0;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                twoSum(temp,final,i);
                while(i+1<temp.size() && temp[i]==temp[i+1]) // if i is repeated
                    i++;
            }
        }
        return final;
    }
};
