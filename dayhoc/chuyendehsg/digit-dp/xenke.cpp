#include<bits/stdc++.h>
using namespace std;
#define baitoan "xenke"
typedef long long int lli;
char a[100001],n;
lli F[100001][10][2][2];

lli thu(int i, bool gh,char dig, bool tang, bool nghia)
 {

    bool ghm;
    if (i < 0)
    {
        return 1;
    }

    if(gh == false && F[i][dig][tang][nghia] >= 0)
        return F[i][dig][tang][nghia];

    lli kq = 0;
    char maxc = (gh ? a[i] : 9);
    if (nghia)
	{
		if (tang)
		{
			for (char c = dig+1; c <= maxc; c++)
			{
				ghm = gh && (c == maxc);
				kq += thu(i-1, ghm, c, false,(c!=0)|nghia);
			}
		}
		else
		{
			for (char c = 0; c <= min(dig-1,maxc+0); c++)
			{
				ghm = gh && (c == maxc);
				kq += thu(i-1, ghm, c, true, (c!=0)|nghia);
			}
		}
	}

    else
	{
		ghm = gh && (0 == maxc);
		kq += thu(i-1, ghm, 0, true, false);
		for (char c = 1; c <= maxc; c++)
		{
			ghm = gh && (c == maxc);
			kq += thu(i-1, ghm, c, true, true);
			if (i>0)
			kq += thu(i-1, ghm, c, false, true);
		}
	}

    kq %= 1000000007;
    if (gh==false) F[i][dig][tang][nghia] = kq;
    return kq;
 }

lli G(string x)
{
    //if (x=="0") return 1;
    n=x.length();
    for (int i=0; i<n; i++) a[n-1-i]=x[i]-48;
    if (n==1) return x[0]-47;
    return thu(n-1,true,-1,true,false);
}

void giam1(string &s)
{
	int i = s.length()-1;
	while (s[i]==48)
	{
		s[i]='9';
		i--;
	}
	s[i]--;
	while(s[0]==48 && s.length()>0) s.erase(0,1);
}

int main()
{
    freopen(baitoan".inp", "r", stdin);
    freopen(baitoan".out", "w", stdout);
    memset(F, -1, sizeof(F));
    string A, B;
    cin >> A >> B;
    giam1(A);
    cout << G(B) - G(A);
    return 0;
}
