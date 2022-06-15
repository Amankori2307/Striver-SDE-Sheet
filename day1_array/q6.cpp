// Stock Buy And Sell

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int> prices){
            int mxp = 0;
            for(int i=0; i<prices.size()-1; i++){
                for(int j=i+1; j<prices.size(); j++){
                    mxp = max(prices[j] - prices[i], mxp);
                }
            }
            return mxp;
        }

        // Optimized Solution
        int maxProfit2(vector<int> prices){
            vector<int> diff(prices.size()-1);
            for(int i=0; i<prices.size(); i++){
                diff[i] = prices[i+1] - prices[i];
            }

            int mxp = 0;
            int currProfit = 0;
            for(int i=0; i<prices.size()-1; i++){
                currProfit += diff[i];
                mxp = max(mxp, currProfit);
                if(currProfit < 0) currProfit = 0;
            }
            return mxp;
        }

        int maxProfit3(vector<int> prices){
            int minPrice = INT_MAX;
            int maxPro = 0;

            for(int i=0; i<prices.size(); i++){
                minPrice = min(prices[i], minPrice);
                maxPro = max(prices[i]-minPrice, maxPro);
            }
            return maxPro;`
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }

    Solution s;
    cout << s.maxProfit3(prices) << endl;
    
    return 0;
}