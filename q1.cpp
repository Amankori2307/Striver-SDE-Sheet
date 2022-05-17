#include<iostream>
#include<vector>
using namespace std;


void printMatrix(vector<vector<int>> mat){
  for(auto row: mat){
        for(auto col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}

/*
    Store all the positions where value is 0, then iterate over all those positions and update value of
    row and column accordingly
*/ 
void approach1(vector<vector<int>> mat, int n, int m){
    vector<pair<int,int>> found;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                found.push_back({i, j});
            }
        }
    }

    for(auto item: found){
        for(int i=0; i<m; i++){
            mat[item.first][i] = 0;
        }
        for(int i=0; i<n; i++){
            mat[i][item.second] = 0;
        }
    }

    printMatrix(mat);
}


/*
    Aproach 2 use last row and last column of the matrix to store 0 accordingly and then traverse matrix and
    if the give mat[lastcol][i] or mat[j][lastcol] is 0 then set the value to 0
*/ 
void approach2(vector<vector<int>> mat, int n, int m){
    vector<bool> row(n, false);
    vector<bool> col(m, false);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(row[i] || col[j]){
                mat[i][j] = 0;
            }
        }
    }
    printMatrix(mat);
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    // approach1(mat, n, m);
    approach2(mat, n, m);
    
    return 0;
}