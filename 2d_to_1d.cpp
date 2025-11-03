#include<bits/stdc++.h>
using namespace std ;

int main(){
    cout << "high";
    int r,c;
    cin >> r >> c ;
    int arr[r][c];
    int oneD[r*c];
    int x=0;
    for(int i= 0 ; i<r;i++){
        for(int j= 0 ; j<c;j++){
            cin >> arr[i][j];
            oneD[x] = arr[i][j];
                x++;
        }
    }
    for(int i = 0; i< r*c ; i++){
        cout << oneD[i];
    }
    int y;
    cin >> y ;
    for(int i= c*(y-1); i< c*y ; i++){
        cout << oneD[i] <<"\n";
    }

return 0;
}
