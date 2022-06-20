/*


    Approach
    - traverse from back and find a[i] < a[i+1] || Idx1
    - traverse from back and find element which is greater thatn A[idx1] || idx2
    - swap(A[idx1], A[idx2])
    - Reverse everything which is on the right of idx1



    Explaination
    - find the breaking point
    - fin the the next greatest element
    - swap 


    Example 

    A[] = 1 3 5 4 2

    idx1 = 1 // A[1] = 3
    idx2 = 3 // A[3] = 4
    swap(A[idx1], A[idx2]);
    revers(A.begin()+idx+1, A.end());
*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = findBreakPointIdx(nums);
        if(idx1 == -1){
            reverse(nums.begin(), nums.end());

        } else {
            int idx2 = nextGreaterElementIdx(nums, nums[idx1]);
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin()+idx1+1, nums.end());

        }
    }

    int findBreakPointIdx(vector<int>& nums){
        int breakPoint = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                breakPoint = i;
                break;
            }
        }
        return breakPoint;
    }
    
    
    int nextGreaterElementIdx(vector<int>& nums, int elem){
        int idx = -1;
        for(int i=nums.size()-1; i>=0;  i--){
            if(nums[i] > elem){
                idx = i;
                break;
            }
        }
        return idx;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }


    Solution s;
    s.nextPermutation(nums);

    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}