"""
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
        5, 5


    N E W S
    0 1 2 3
"""

NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3
INF = 1000000000


def getCoords(x, y, dir, turns):
    dir = (dir+turns)%4
    if (dir == NORTH):
        return x-1, y
    elif (dir == EAST):
        return x, y+1
    elif (dir == SOUTH):
        return x+1, y
    elif (dir == WEST):
        return x, y-1


direction = int(input())
x = int(input())
y = int(input())
d_x = int(input())
d_y = int(input())

vis  = [ [False]*5 for _ in range(5) ]


def getAdditionalCost(turns):
    if(turns == 1 or 3):
        return 5
    elif(turns == 0):
        return 0
    elif(turns == 2):
        return 10

def insideGrid(x, y):
    return (x > -1 and x < 5 and y > -1 and y < 5)

def pacman(x, y, dir, d_x, d_y):
    if(x == d_x and y == d_y):
        return  1, 0
    res = []
    for turns in range(0, 4):
        n_x, n_y = getCoords(x, y, dir, turns)
        if(insideGrid(n_x, n_y)):
            if not vis[n_x][n_y]:
                currDirection = (dir+turns)%4
                vis[n_x][n_y] = 1

                cost =  getAdditionalCost(turns) + pacman(n_x, n_y,currDirection, d_x, d_y)
                res.append(cost)
    if(len(res)):
        return min(res)
    else:
        return INF



cost = pacman(x, y, direction, d_x, d_y)
print(cost)