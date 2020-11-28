#include<bits/stdc++.h>
using namespace std;
#define baitoan "tbpb3"
typedef long long int lli;
char a[10001],n;
lli F[10001][3];
int loai=0;

lli thu(int i, bool gh,int tbp)
 {
    //cout << " thu "<<i<<gh<<tbp<<endl;
    bool ghm;
    if (i < 0)
    {
        if (tbp == 0) return 1;
        else return 0;
    }

    if(gh == false && F[i][tbp] >= 0) return F[i][tbp];

    lli kq = 0;
    char maxc = (gh ? a[i] : 9);
    for (char c = 0; c <= maxc; c++)
    {
        ghm = gh && (c == maxc);
        kq += thu(i-1, ghm, (tbp+c*c)%3);
    }
    kq=kq%1000000007;
    if (gh == false) F[i][tbp] = kq;
    return kq;
 }

lli G(string x)
{
    int t=0;
    n=x.length();
    for (int i=0; i<n; i++) a[n-1-i]=x[i]-48;
    for (int i=0; i<n; i++) t+=a[i]*a[i];
    if (t%3==0) loai=1;
    return thu(n-1,true,0);
}

int main()
{
    freopen(baitoan".inp", "r", stdin);
    freopen(baitoan".out", "w", stdout);
    memset(F, -1, sizeof(F));
    string A;
    cin >> A ;
    cout << G(A)-loai;
}
