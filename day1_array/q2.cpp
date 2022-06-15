#include<iostream>
#include<vector>
using namespace std;


void print(int n, vector<vector<int>> mat){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void printPascalTriangle(int n){
    vector<vector<int>> mat(n,vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j == 0 || i == 0){
                mat[i][j] = 1;
            } else {
                mat[i][j] = mat[i-1][j] + mat[i-1][j-1];
            }
        }
    }
    print(n, mat);
}




int main() {
    int n;
    cin >> n;

    printPascalTriangle(n);
    return 0;
}