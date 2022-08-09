/*
    Q 1. Set Matrix Zero
    Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire 
    column and row to 0 and then return the matrix.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        void disp(vector<vector<int>> &arr, int n){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        void approach1(vector<vector<int>> arr, int n){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(arr[i][j] == 0){
                        // Set the whole row and column as -1
                        for(int k=0; k<n; k++){
                            if(arr[i][k] != 0) arr[i][k] = -1;
                            if(arr[k][j] != 0) arr[k][j] = -1;
                        }
                    }
                }
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(arr[i][j] == -1){
                        arr[i][j] = 0;
                    }
                }
            }
            disp(arr, n);
        }
};


int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    Solution s;
    s.approach1(arr, n);
    return 0;
}