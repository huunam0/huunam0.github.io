#include<bits/stdc++.h>
using namespace std;
#define baitoan "chiahet"
typedef long long int lli;
char a[10],n;
lli F[11][91][10000];
int K;
lli thu(int i, bool gh,int sum, int sodu)
 {
    bool ghm;
    if (i < 0)
    {
        if (sum%K==0 && sodu==0) return 1;
        else return 0;
    }
    
    if(gh == false && F[i][sum][sodu] >= 0)
        return F[i][sum][sodu];

    lli kq = 0;
    char maxc = (gh ? a[i] : 9);
    for (char c = 0; c <= maxc; c++)
    {
        ghm = gh && (c == maxc);
        kq += thu(i-1, ghm, sum+c, (10*sodu+c)%K);
    }
    if (gh==false) F[i][sum][sodu] = kq;
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
    return thu(n-1,true,0,0);
}

int main()
{
    freopen(baitoan".inp", "r", stdin);
    freopen(baitoan".out", "w", stdout);
    memset(F, -1, sizeof(F));
    lli A, B;
    cin >> A >> B >>K;
    cout << G(B) - G(A-1);
    return 0;
}
