#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        void display(vector<int> arr){
            for(auto item: arr){
                cout << item << " ";
            }
            cout << endl;
        }

        void merge(vector<int> a, vector<int> b){
            if(a.size() == 0) display(b);
            if(b.size() == 0) display(a);

            for(int i=0; i<a.size(); i++){
                if(a[i] > b[0]){
                    swap(a[i], b[0]);
                    for(int j=1; j<b.size(); j++){
                        if(b[j-1] > b[j]){
                            swap(b[j-1], b[j]);
                        }
                    }
                }
            }
            display(a);
            display(b);
        }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    Solution s;
    s.merge(a, b);
}