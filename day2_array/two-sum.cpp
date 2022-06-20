#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution{
    public:
        pair<int, int> twoSum(vector<int> arr, int target){
            unordered_map<int, int> visited;
            pair<int, int> ans;
            for(int i=0; i<arr.size(); i++){
                int num1 = arr[i];

                if(visited.find(target - num1) != visited.end()){
                    int num2 = target - num1;
                    ans.first = min(i, visited[num2]);
                    ans.second = max(i, visited[num2]);
                    break;
                } else {
                    visited[num1] = i;
                }
            }
            return ans;
        }
};

int main() {
    vector<int> arr = {1, 4, 6, 2, 5};
    int target = 6;

    Solution s;


    pair<int, int> ans = s.twoSum(arr, target);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}