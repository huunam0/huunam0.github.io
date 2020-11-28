#include<bits/stdc++.h>
using namespace std;
#define baitoan "cspb"
typedef long long int lli;
char a[19],n;
lli F[19][1025][2]; 

lli thu(int i, bool gh,int tt, bool nghia)
 {
    bool ghm;
    if (i < 0)
    {
        return 1;
    }

    if(gh == false && F[i][tt][nghia] >= 0)
        return F[i][tt][nghia];

    lli kq = 0;
    if (gh)
	{
		if (nghia)
		{
			ghm=a[i]==0;
			if ((tt & 1) ==0) kq+= thu(i-1,ghm, tt|1, true);
		}
		else
		{
			ghm=a[i]==0;
			kq+=thu(i-1,ghm,tt,false);
		}
		for(char c=1; c<=a[i]; c++)
		{
			ghm=a[i]==c;
			if ((tt & (1 << c))==0) kq+= thu(i-1,ghm, tt|(1<<c), true);
		}
	}
	else
	{
		if (nghia)
		{
			if ((tt & 1)==0) kq+= thu(i-1,false, tt|1, true);
		}
		else
		{
			kq+=thu(i-1,false,tt,false);
		}
		for(char c=1; c<=9; c++)
		{
			if ((tt & (1 << c))==0) kq+= thu(i-1,false, tt|(1<<c), true);
		}
	}
    if (gh==false) F[i][tt][nghia] = kq;
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
    return thu(n-1,true,0,false);
}

int main()
{
    freopen(baitoan".inp", "r", stdin);
    freopen(baitoan".out", "w", stdout);
    memset(F, -1, sizeof(F));
    lli A, B;
    cin >> A >> B ;
    cout << G(B) - G(A-1);
    return 0;
}
