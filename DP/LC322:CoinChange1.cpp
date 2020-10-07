/*

//Minimum number of coins


322. Coin Change
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

//Reference:
16  Coin change problem- Minimum number of coins_HD - Youtube


//Solution:

Initialization is the key
Initialize the 01, 10 rows and colums
Also, Initialize the [1][j] column as to know if exaclty divisible or not
*/

class Solution {
public:
    int dp[13][10001];
    int coinChange(vector<int>& coins, int amount) {

        for(int i=0;i<=coins.size();i++)
            dp[i][0]=0;
        for(int j=0; j<=amount; j++)
            dp[0][j]=INT_MAX-1;

        for(int j=1; j<=amount; j++){
                if(j % coins[0] == 0)
                    dp[1][j] = j/coins[0];
                else
                    dp[1][j] = INT_MAX-1;
        }

        for(int i=2; i<=coins.size(); i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<= j){
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1 , dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[coins.size()][amount] != INT_MAX-1 ?dp[coins.size()][amount]:-1;

    }
};
