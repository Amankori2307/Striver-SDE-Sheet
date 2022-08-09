#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution{
    public:

        int getNextToCaptureIdx(vector<bool>& captured){
            for(int i=0; i<captured.size(); i++){
                if(!captured[i]) return i;
            }        
            return -1;
        }


        void disp(vector<bool> arr){
            for(int i=0; i<arr.size(); i++){
                cout << i << "="<< arr[i] <<", "; 
            }
            cout << endl;
        }
        int markCaputured(vector<bool>& caputred, vector<int>& arr, int troops){
            int idx = -1;
            int i=0;
            
            while(troops >= arr[i] && i < arr.size()){
                if(!caputred[i]){
                    idx = i;
                    break;
                }
                i++;
            }
            if(idx != -1){
                caputred[idx] = true;
                cout << "Caputred: " << idx << ", troops: " << troops << endl; 
            } else {
                cout << "IDX = -1" << endl;
            }
            return idx;
        }

        int solution(vector<int> arr){
            sort(arr.begin(), arr.end());
            int n = arr.size();
            int x = 1;
            int days = arr[0];
            vector<bool> captured(n, false);
            captured[0] = true;
            x++;
            int nextToCaptureIdx = getNextToCaptureIdx(captured);
            while(nextToCaptureIdx != -1){
                cout << "x: " << x << ", nextToCaptureIdx: " << nextToCaptureIdx << endl;
                double nextToCapture = (double)arr[nextToCaptureIdx];
                int daysToCapture = ceil(nextToCapture/x);
                int troops = daysToCapture*x;
                int capturedIdx = markCaputured(captured, arr, troops);
                // cout << days << " " << daysToCapture << " "<< capturedIdx << endl;
                days += daysToCapture;
                x++;
                nextToCaptureIdx = getNextToCaptureIdx(captured);
            }
               
            return days;
        }
        
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    Solution s;

    cout << endl << endl;
    cout << s.solution(arr);


    return 0;
}