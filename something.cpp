// Source - https://stackoverflow.com/q
// Posted by Kshitij Kohli, modified by community. See post 'Timeline' for change history
// Retrieved 2026-01-21, License - CC BY-SA 4.0

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    scanf("%d",&w);
    char crap=getchar();
    while(w--){
        string a;
        getline(cin,a);
        int t=1,i;
        if((a.length()==1)||(a.length()==2))
            printf("Bad\n");
        else{
            for(i=0;i<a.length()-2;i++){
                if(((a[i]=='0')&&(a[i+1]=='1')&&(a[i+2]=='0'))||((a[i]=='1')&&(a[i+1]=='0')&&(a[i+2]=='1'))){
                    t=1;
                    break;
            }
                else t=0;
            }
        if(t==0)
            printf("Bad\n");
        else  printf("Good\n");
        }
    }
    return 0;
}
