class Solution {
public:
    // Function to count subsets with a given sum
    int counter(vector<int>& nums, int S){
        int n=nums.size();
        int dp[n+1][S+1];

        //Initialization part & Base conditions
        dp[0][0]=1;
        for(int i=1;i<=n; i++){
                if(nums[i-1] == 0)
                    dp[i][0] = 2 * dp[i-1][0];
                else
                    dp[i][0] = dp[i-1][0];
            }
        for(int j=1; j<= S; j++){
                dp[0][j]=0;
        }

        //Choice diagram
        for(int i=1;i<=n; i++){
            for(int j=1; j<= S; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]]+ dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][S];
    }


    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto it = nums.begin(); it != nums.end(); it++)
            sum+=*it;
        if(S > sum)
            return 0;

        /*
        As we know we are to find 2 subsets with given diff S;
        So,
                s1 - s2 = diff
                s1 + s2 = sum

                2s1 = diff + sum

        which means, diff + sum should always be even for s1 to exist
        */
        if((S+ sum) % 2 == 1)
            return 0;
        int diff= ceil((S + sum)/2.0);
        return counter(nums,diff);
    }



};
