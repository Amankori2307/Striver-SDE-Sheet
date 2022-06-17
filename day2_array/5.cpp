/*
    Approaches:
    - Count sort / Frequency array  
    - Maths equation
    - XOR
*/ 

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeating(vector<int>& A){
            long long int n = A.size();
            long long int s = n*(n+1)/2;
            long long int p = n*(n+1)*((2*n)+1)/6;

            long long int s1 = 0;
            for(int i=0; i<A.size(); i++){
                s1 += A[i];
            }

            long long int p1 = 0;
             for(int i=0; i<A.size(); i++){
                p1 += pow(A[i], 2);
            }

            long long int sDiff = s - s1; 
            long long int pDiff = p - p1; 

            int missing = ((int)sDiff + pDiff/sDiff)/2;
            int repeating =  missing - sDiff;

            return {repeating, missing};
        }

         vector<int> findMissingAndRepeatingXOR(vector<int>& A){
            int XOR = 0;
            int n  = A.size();
            for(int i=0; i<n; i++){
                XOR ^= A[i];
            }
            int XOR_TEMP = XOR;

            for(int i=0; i<A.size(); i++){
                XOR_TEMP ^= i;
            }

            int set_bit_no = XOR_TEMP & ~(XOR_TEMP - 1);

         }
};

int main() {
    vector<int> nums =  {1, 2, 3, 3, 5};
    Solution s;

    // vector<int> res = s.findMissingAndRepeating(nums);
    // cout << res[0] << " " << res[1] << endl;

    vector<int> res = s.findMissingAndRepeatingXOR(nums);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}