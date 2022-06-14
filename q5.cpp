#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<count[i]; j++){
                cout << i << ", ";
            }
        }
    }
};


int main(){
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
}