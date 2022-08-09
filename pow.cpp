/*

    Binary Exponention Method

    let x = 10, n = 6;


    ans nn 
    1   6  


*/ 


#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        double pow(int x, int n){
            double ans = 1.0;
            long long nn = n;
            nn = nn < 0 ? nn * -1: nn;

            while(nn){
                if(nn%2==0){
                    x *= x;
                    nn /= 2;
                } else {
                    ans *= x;
                    nn -= 1;
                }
            }
            return n < 0? 1/ans : ans;

        }
};

int main(){
    int x, n;
    cin >> x >> n;

    Solution s;
    cout << s.pow(x, n) << endl; 
    return 0;
}