#include <iostream>
#include <string>
using namespace std;
int main() 
{
    string s;
    getline(cin,s);
    s+=" ";
    int d=1;
    cout<<s[0];
    for (int i=1;i<=s.length()-1;i++){
      if (s[i]==32){
        if (i>d){
          cout<<s.substr(d,i-d)<<endl;
          d=i+1;
        }
      d=i+1;
      }
    }
    return 0;
}
