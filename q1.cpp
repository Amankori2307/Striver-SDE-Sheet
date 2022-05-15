#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    vector<pair<int,int>> found;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                found.push_back({i, j});
            }
        }
    }

    for(auto item: found){
        for(int i=0; i<m; i++){
            arr[item.first][i] = 0;
        }
        for(int i=0; i<n; i++){
            arr[i][item.second] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}