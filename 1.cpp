/*
    PROBLEM STATEMENT: Given a matrix if an element in the matrix is 0 then you will have to set its entire column 
    and row to 0 and then return the matrix.


*/


#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int col0 = 1;
    for(int i=0; i<n; i++){
        if(arr[i][0] == 0) col0 = 0;
        for(int j=1; j<n; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=1; j--){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
        if(col0 == 0) arr[i][0] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}