/*

//Maximum number  of ways

518. Coin Change 2

You are given coins of different denominations and a total amount of money.
Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.

// Same as count of subset with a given sum
// Only thing is that, repetition is possible as it is an unbounded Knapsack problem
*/
class Solution {
public:
    int dp[501][5001];
    int change(int amount, vector<int>& coins) {
        for(int j=0; j<=amount; j++)
            dp[0][j]=0;
        for(int i=0;i<=coins.size();i++)
            dp[i][0]=1;

        for(int i=1; i<=coins.size(); i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[coins.size()][amount];

    }
};
