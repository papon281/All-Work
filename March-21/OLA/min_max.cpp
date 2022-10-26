#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int change_count=0;
    int _max=-1,_min=10000;
    for(int i=0;i<n;i++){
        if(arr[i]>_max){
            _max=arr[i];
            change_count++;
        }
        if(arr[i]<_min){
            _min=arr[i];
            change_count++;
        }
    }
    cout << "Change values = "<<change_count<<" times"<<endl;
    return 0;
}
