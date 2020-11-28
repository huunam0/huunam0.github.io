
#include<bits/stdc++.h>
using namespace std;
#define baitoan "tnt"
typedef long long int lli;
char a[20],n;
lli F[20][163];
bool nguyento[163];
void sangnguyento(int  n)
{
    int i,j;
    memset(nguyento,true,sizeof(nguyento));
    nguyento[0]=nguyento[1]=false;
    for (i=2; i<=n; i++) 
    {
        if (nguyento[i])
        {
            for (j=i*i; j<=n; j+=i) nguyento[j]=false;
        }
    }
}

lli thu(int i, bool gh,int tong)
 {
    bool ghm;
    if (i < 0)
    {
        if (nguyento[tong]) return 1;
        else return 0;
    }
    
    if(gh == false && F[i][tong] >= 0)
        return F[i][tong];

    lli kq = 0;
    char maxc = (gh ? a[i] : 9);
    for (char c = 0; c <= maxc; c++)
    {
        ghm = gh && (c == maxc);
        kq += thu(i-1, ghm, tong+c);
    }
    if (gh==false) F[i][tong] = kq;
    return kq;
 }

lli G(lli x)
{
    a[0] = 0;
    n = 0;
    while (x)
    {
        a[n] = x % 10;
        x /= 10;
        n++;
    }
    return thu(n-1,true,0);
}

int main()
{
    //freopen(baitoan".inp", "r", stdin);
    //freopen(baitoan".out", "w", stdout);
    memset(F, -1, sizeof(F));
    sangnguyento(72);
    lli A, B;
    cin >> A >> B;
    cout << G(B) - G(A-1);
}
