#include<bits/stdc++.h>
using namespace std;

void printall(string str){
    sort(str.begin(),str.end());
    do{
        cout<<str<<endl;
    }while (next_permutation(str.begin(),str.end()));
    
    

}



int main(){
    string str;
    cout<<"enter the string: ";
    cin>>str;
    printall(str);


    return 0;
}