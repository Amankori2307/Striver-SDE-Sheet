// Sort an array of 0s, 1s and 2s
// Three Pointer Algorithm | Dutch national flag algorithm


#include<iostream>
#include<vector>
using namespace std;


class Solution{
    public:
        void sort(vector<int> &nums){
            int low = 0, high =  nums.size() - 1;
            int mid=0;
            while(mid <= high){
                if(nums[mid] == 0){
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                } else if(nums[mid] == 1){
                    mid++;
                } else if(nums[mid] == 2){
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution s;
    s.sort(nums);
    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}