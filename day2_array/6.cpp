#include<iostream>
#include<vector>
using namespace std;


class Solution{
    public:
    int arrayInversions(vector<int>& arr){
        int inversions = 0;
        for(int i=0; i<arr.size()-1; i++){
            for(int j=i+1; j<arr.size(); j++){
                if(i < j && arr[i] > arr[j]){
                    inversions++;
                }
            }
        }
        return inversions;
    }

    int merge(vector<int>& arr, int left, int mid, int right){
        int inversions = 0;
        int i = left;
        int j = mid+1;
        // int k = 0;
        while(i <= mid && j <= right){
            if(arr[i] > arr[j]){
                inversions =  mid-i+1;
                int temp = arr[j];
                move(arr, i, j);
                arr[i] = temp;
                j++;
            } else {
                i++;    
            }
        }
    }

    int move(vector<int> arr, int start, int end){
        for(int i=end; i>start; i++){
            arr[i] = arr[i-1];
        }
    }

    int arrayInversionsRecursive(vector<int>& arr, int left, int right){
        if(left == right) return 0;
    
        int inversions = 0;
        int mid = (left + right) / 2;
        inversions += arrayInversionsRecursive(arr, left, mid);
        inversions += arrayInversionsRecursive(arr, mid+1, right);
        
        inversions += merge(arr, left, mid, right)
        return inversions;
    }

    void display(vector<int> arr){
        for(auto i: arr){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    Solution s;
    // cout << s.arrayInversions(arr) << endl;



    int left = 0;
    int right = arr.size() -1;


    cout << s.arrayInversionsRecursive(arr, left, right) << endl;

    return 0;
}


/*

    5 2 3 1 4
    |   |

    -3 1 -2 3

    1


    0 | 0 1 -> y
    1 | 0 2 -> 

*/ 