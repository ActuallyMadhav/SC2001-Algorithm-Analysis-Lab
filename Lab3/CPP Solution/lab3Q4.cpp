#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(int C, const std::vector<int>& weights, const std::vector<int>& profits){
    std::vector<int> dp(C+1, 0);

    for(int c = 1; c < C+1; c++){
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] <= c){
                dp[c] = std::max(dp[c], dp[c - weights[i]] + profits[i]);
            }
        }
    }

    for(int x : dp){std::cout << x << ' ';}
    std::cout << '\n';
    return dp[C];
}

int main(){

    std::vector<int> weights1 = {4,6,8};
    std::vector<int> profits1 = {7,6,9};
    int C = 14;

    printf("P(14) for set 1: %d\n", maxProfit(C, weights1, profits1));

    std::cout << '\n';

    std::vector<int> weights2 = {5,6,8};
    std::vector<int> profits2 = {7,6,9};

    printf("P(14) for set 2: %d\n", maxProfit(C, weights2, profits2));
    return 0;
}