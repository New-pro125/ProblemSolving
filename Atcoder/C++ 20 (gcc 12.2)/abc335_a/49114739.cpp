#include<iostream>
using namespace std;
int main(){
  string temp;
  cin>>temp;
  temp[temp.size()-1]='4';
  cout<<temp<<'\n';
  return 0;
}