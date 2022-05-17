/*
    ALGORITHM


    * If in stack
        return 0
    * If not inside the grid
        return 0
    * If Destination
        return 1

    vis[]

*/ 

#include<iostream>
#include<vector>
using namespace std;

const int N = 3;

vector<vector<bool>> vis(N, vector<bool>(N, false));

class Coords {
    public:
        int x, y;

    Coords(int a, int b){
        x = a;
        y = b;
    }

    bool insideGrid(){
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    bool visited(){
        return vis[x][y];
    }

    bool isEqual(Coords coords){
        return x == coords.x && y == coords.y;
    }

    bool visit(){
        return vis[x][y] = true;
    }


    bool unVisit(){
        return vis[x][y] = false;
    }
};


void printVis(){
    for(auto row: vis){
        for(auto col: row){
            cout << col << " ";
        }
        cout << "\n";
    }
    cout << endl; 
}


int noOfWays(Coords coords, Coords dest){
    if(!coords.insideGrid()){
        // cout << "CASE 1" << endl;
        return 0;
    }
    if(coords.visited()){
        // cout << "CASE 2" << endl;
        return 0;
    }
    if(coords.isEqual(dest)){
        // cout << "CASE 3" << endl;
        return 1;
    }

    coords.visit();
    printVis();

    int sum = 0;
    sum += noOfWays({coords.x-1, coords.y}, dest);
    sum += noOfWays({coords.x, coords.y-1}, dest);
    sum += noOfWays({coords.x+1, coords.y}, dest);
    sum += noOfWays({coords.x, coords.y+1}, dest);
    // cout << sum << endl;

    coords.unVisit();

    return sum;
}

int main() {
    Coords dest(2, 2);
    Coords currentLocation(0, 0);

    cout  << noOfWays(currentLocation, dest) << endl;

    return 0;
}