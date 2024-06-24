#include<bits/stdc++.h>
using namespace std;

/*take no of groups 
no of people in each group
capacity of buses
find total no of buses required to send the peeople
and whole group should go in one bus,*/
   
int main(){
    int group, cap;
    cin>>group;
    int a[group];
    for(int i=0;i<group;i++)
        cin>>a[i];
    cin>>cap;
    int bus=0;
    int sum=0;
    for(int i=0;i<group;i++){
        sum+=a[i];
        if(sum>cap){
            bus++;
            sum=a[i];

        }
        
            
        
            
    }
    if(sum>0){
        bus++;
    }
    cout<<bus;
}


