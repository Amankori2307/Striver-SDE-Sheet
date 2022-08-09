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

        void approach2(vector<vector<int>> matrix, int n){
            int col0 = 1;
            for (int i = 0; i < n; i++) {
                //checking if 0 is present in the 0th column or not
                if (matrix[i][0] == 0) col0 = 0;
                for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                }
            }
            //traversing in the reverse direction and
            //checking if the row or col has 0 or not
            //and setting values of matrix accordingly.
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
                }
                if (col0 == 0) {
                matrix[i][0] = 0;
                }

            }


            disp(matrix, n);

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
    s.approach2(arr, n);
    return 0;
}