/*

    [
        1,  3,  5,  7,
        10, 11, 16, 20,
        23, 30, 34, 60,
    ]

    1 is at (0,0)
    and 60 is at (2,4)


    element to find = 5 = k
    we will start from (4, 0) = 23

    while(r < n && c < m){
        if(arr[r][c] === k) return r,c
        else if(arr[r][c] < k) c++;
        else r--;
    }

    DRY RUN
    r   c   arr[r][c]   k
    2   0   23          5
    1   0   10
    0   0   1
    0   1   3
    0   2   5  //return
*/ 


#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        bool search(vector<vector<int>> mat, int n, int m, int k){
            int row = n-1;
            int col = 0;
            while(row >= 0 && col < m){
                if(mat[row][col] == k) return true;
                else if(mat[row][col] < k) col++;
                else row--;
            }
            return false;
        }

        bool searchUsingBinarySearch(vector<vector<int>> mat, int k){
            int n = mat.size(), m = mat[0].size();
            int low = 0;
            int high = (n*m)-1;

            while(low <= high){
                // cout << "low: " << low <<", high: " << high << endl;
                int mid = (low+high)/2;
                int num = mat[mid/m][mid%m];
                if(num == k){
                    return true;
                } else if(num < k){
                    low = mid+1;
                } else {
                    high = mid -1;
                }
            }
            return false;
        }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    Solution s;
    // cout << s.search(mat, n, m, k) << endl;

    
    cout << s.searchUsingBinarySearch(mat, k);
    return 0;
}