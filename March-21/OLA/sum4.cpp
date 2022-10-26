 #include<iostream>

using namespace std;

int increment(int n){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n*n;j++){
            sum++;
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    cout<<increment(n)<<endl;
}


