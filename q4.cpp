// Kadane’s Algorithm : Maximum Subarray Sum in an Array


#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int maximumSubArraySum(vector<int> nums){
            int maxSum = nums[0];
            int currSum = 0;
            for(int i=0; i<nums.size(); i++){
                currSum += nums[i];
                maxSum = max(currSum, maxSum);
                
                if(currSum <= 0){
                    currSum = 0;
                }
            }

            return maxSum;
        }
};

int main(){
    int n;
    cin  >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution s;
    cout << s.maximumSubArraySum(nums) << endl;
    return 0;
}