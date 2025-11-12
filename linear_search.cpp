#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[10]={21,34,65,75,34,235,67,45,23,40};

    int n = 23 ;

     int x=0;

    for (int i= 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        if(arr[i]== n){
            cout << "number found \n";
            x=1;
            break;
        }
    }
    if( x == 0){
        cout << "number not found \n";
    }
    return 0;
}
