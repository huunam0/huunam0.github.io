#include <iostream>

using namespace std;

long long hambam(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long kq = 0;
    long long pm = 1;
    for (int i=0; i<s.length(); i++) {
        kq = (kq + (s[i] - 'a' + 1) * pm) % m;
        pm = (pm * p) % m;
    }
    return kq;
}

int main()
{
    string s="abc";
    cout<<hambam(s);
    return 0;
}
