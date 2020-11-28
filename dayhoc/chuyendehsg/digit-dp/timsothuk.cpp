#include<bits/stdc++.h>
using namespace std;
#define baitoan "tnt"
typedef long long int lli;
int a[50],n,m[50]; //Tran Huu Nam - 0969156825 - thnam@thptccva.edu.vn
lli F[50][450],dem=0,k;
bool nguyento[273];
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
void viet(int k)
{
	while(k--) cout<<" ";
}
void vietm()
{
	cout<<"KQ "<<(++dem)<<": ";
	int i=n-1;
	while (m[i]==0) i--;
	for (; i>=0; i--) cout<<m[i];
	cout<<endl;
}
lli thu(int i, bool gh,int tong,long long daco)
 {
    if (daco>=k) return 0;
    bool ghm;
    if (i < 0)
    {
        if (nguyento[tong])
		{
			if (daco+1==k)
				vietm();
			return 1;
		}
        else return 0;
    }

    if(gh == false && F[i][tong] >= 0)
	{
		if (daco+F[i][tong]<k)
		{
			return F[i][tong];
		}
	}

    lli kq = 0;
    char maxc = (gh ? a[i] : 9);
    for (char c = 0; c <= maxc; c++)
    {
    	m[i]=c;
        ghm = gh && (c == maxc);
        kq += thu(i-1, ghm, tong+c, daco+kq);
        if (daco+kq>=k) break;
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
    return thu(n-1,true,0,0);
}

int main()
{
    //freopen(baitoan".inp", "r", stdin);
    //freopen(baitoan".out", "w", stdout);
    memset(F, -1, sizeof(F));
    sangnguyento(272);
    lli B;
    cout<<"Nhap so thu k=";
    cin>>k;
    n=19;
    memset(a, 0, sizeof a);
    a[n]=1;
    B = thu(n,true,0,0);
    return 0;
}
