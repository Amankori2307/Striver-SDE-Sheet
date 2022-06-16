/*
    3 Approaches
    - Sort and find duplicate
    - Frequency array
    - Linked list cycle approach (most optimized)
*/ 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
        int findDuplicate(vector<int>& nums){
            int n = nums.size();
            int slow = nums[0];
            int fast = nums[0];
            do{
                slow = nums[slow];
                fast = nums[nums[fast]];
            } while(slow != fast);

            fast = nums[0];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 6};
    Solution s;
    cout << s.findDuplicate(nums);
    return 0;
}