/*
    Problem: 
    - It is a game where there is a player named pacman
    - who will be moving in a 5X5 2d grid
    - in the start of the game the player will be 
    - pointing in a certain direction, 
    - will be at a random location in the grid 
    - and he will be having a certain amount of power, 
    - every time he turns he loses 5 power 
    - and every time he moves 1 distance he loses 10 power
        - Possible directions to move are East, West, North, South 
    - so the task is calculate whether the user can reach the destincation or not and if he can, how many powers are left after reaching destination


    (NOTE: Grid is a 5X5 matrix, coordinates starts from 0,0 coordinate is north west corner of the grid )
   
    GRID:
    
    (0, 0) (0, 1) (0, 2) (0, 3) (0, 4)
    (1, 0) (1, 1) (1, 2) (1, 3) (1, 4)
    (2, 0) (2, 1) (2, 2) (2, 3) (2, 4)
    (3, 0) (3, 1) (3, 2) (3, 3) (3, 4)
    (4, 0) (4, 1) (4, 2) (4, 3) (4, 4)
    

            N
            |
            |
            |
   w--------|---------E
            |
            |
            |
            S

    N r-1, c
    E r, c+1
    S r+1, c
    W r, c-1

    INPUT: 
    CURRENT_DIRECTION
    CURRENT_LOCATION_COORD
    DESTINATION_LOCATION_COORD
    CURRENT_ENERGY

    OUTPUT:
    DIRECTION_AFTER_REACHING_DESTINATION
    ENRGY_TOOK_TO_REACH


    Sample:
        EAST
        0, 0
        4, 4
     _ _ _ _ 
    |_|_|_|_|
    |_|_|_|_|
    |_|_|_|_|
    |_|_|_|_|


    N E W S
    0 1 2 3
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<bool>>  vis(5, vector<bool>(5, false));

enum Direction {
    NORTH=0,
    EAST=1,
    SOUTH=2,
    WEST=3,
};

const int MOVING_COST = 10;

class Coords{
    public:
        int x, y;
    
    bool isEqual(Coords dest){
        return x == dest.x && y == dest.y;
    };

    int getTurningCost(int turns){
        if(turns == 1 || turns == 3) return 5;
        else if(turns == 0) return 0; 
        else if(turns == 2) return 10;
        else return -1;
    }

    bool isVisited(){
        return vis[x][y];
    }

    void visit(){
        vis[x][y] = true;
    }

    void unVisit(){
        vis[x][y] = false;
    }
    
    Coords move(int dir, int turns){
        dir = (dir+turns)%4;
        if (dir == NORTH)
            return{x-1, y};
        else if (dir == EAST)
            return {x, y+1};
        else if (dir == SOUTH)
            return {x+1, y};
        else if (dir == WEST)
            return {x, y-1};
        else return {-1, -1};
    }

    bool isInsideGrid(){
        return x >= 0 && x < 5 && y >= 0 && y<5;
    }

    void print(string prefix){
        cout << prefix << ":\tX=" << x << ",\tY=" << y << endl;
    }
};

struct Res {
    bool reached;
    int cost;
    Coords coords;
    void print(){
        cout << "Cost: " << cost <<", Reached: " << reached << endl;
    }
};


Res pacman(Coords currentLocation, int dir, Coords destination, Coords parent){
    // Not inside grid
    if(!currentLocation.isInsideGrid()){
        return {false, INT_MAX, currentLocation};
    }
    // Destination
    if(currentLocation.isEqual(destination)){
        return {true, 0, currentLocation};
    }
    // Visited
    if(currentLocation.isVisited()){
        return {false, INT_MAX, currentLocation};
    }

    currentLocation.visit();

    vector<Res> resList(4);
    for(int turns=0; turns<4; turns++){
        Coords locationAfterMove = currentLocation.move(dir, turns);
        int newDirection = (dir+turns)%4;
        if(!locationAfterMove.isEqual(parent)){
            Res move = pacman(locationAfterMove, newDirection, destination, currentLocation);
            move.cost = move.cost+MOVING_COST+move.coords.getTurningCost(turns);
            resList.push_back(move);
        }
    }

    Res ans = {false, INT_MAX, {-1, -1}};
    for(auto res: resList){
        if(res.reached){
            int cost = min(ans.cost, res.cost);
            ans = res;
            ans.cost = cost;
        }
    }


    // for(auto res: resList){
    //     res.coords.unVisit();
    // }
    // if(ans.reached){
    //     ans.coords.visit();
    // }

    return ans;
}

int main(){
    int dir;
    Coords currentLocation, destination;
    cin >> dir;
    cin >> currentLocation.x >> currentLocation.y;
    cin >> destination.x >> destination.y;


    Res res = pacman(currentLocation, dir, destination, {-1, -1});
    if(res.reached){
        cout << res.cost<< endl;
    } else {
        cout << "Couldn't reach destination" << endl;
    }


    // cout << currentLocation.getTrunsCost(0) << endl;
    // cout << currentLocation.getTrunsCost(1) << endl;
    // cout << currentLocation.getTrunsCost(2) << endl;
    // cout << currentLocation.getTrunsCost(3) << endl;

    // cout << currentLocation.isEqual(destination) << endl;
    // cout << currentLocation.isEqual({0, 0}) << endl;

    return 0;
}