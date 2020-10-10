#include <iostream>
#include <cstdio>

using namespace std;

int A[1000], H[4000],n;

void nhapmang()
{
	freopen("mang.inp","r",stdin);
	cin>>n;
	for (int i=1; i<=n; i++) cin >> A[i];
}

void build (int v, int l, int r)
{
	if (l == r)
	{
		H[v] = A[l];
		return ;
	}
	int mid = (l+r) / 2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	H[v] = H[2*v] + H[2*v+1];
}
int getSum(int v, int l, int r, int p, int q)
{
	if (r<p || l>q) return 0;
	if (p<=l && r<=q) return H[v];
	int mid = (l+r)/2;
	return getSum(2*v,l,mid,p,q) + getSum(2*v+1,mid+1,r,p,q);
}
void update(int v, int l, int r, int i, int x)
{
	if (i<l || i>r) return;
	if (l==r)
	{
		H[v]=x;
		return;
	}
	int mid = (l+r)/2;
	if (i<=mid) update(2*v,l,mid,i,x);
	else update(2*v+1,mid+1,r,i,x);
	H[v] = H[2*v] + H[2*v+1];
}


int main()
{
    nhapmang();
    build(1, 1, n);
    //vietmangh();
    cout<<getSum(1, 1, n, 5, 7);
    update(1,1,n,6,7);
    cout<<getSum(1, 1, n, 5, 7);
    return 0;
}
