#include <iostream>
#include <cstdio>

using namespace std;

int A[1000], H[4000],Nho[4000],n;

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
	H[v] = max(H[2*v], H[2*v+1]);
}

int getmax(int v, int l, int r, int p, int q)
{
    if (q < l || r < p)  return -1;
    if (p <= l && r <= q) return H[v];
    int mid = (l + r) / 2;
    H[2*v] += Nho[v];
    Nho[2*v] += Nho[v];
    H[2*v+1] += Nho[v];
    Nho[2*v+1] += Nho[v];
	Nho[v]=0;
    return max(getmax(2*v, l, mid, p, q), getmax(2*v+1, mid+1, r, p, q));
}
void update(int v, int l, int r, int p, int q, int g)
{
    if (q < l || r < p)         return ;
    if (p <= l && r <= q)
	{
        H[v] += g;
        Nho[v] += g;
        return ;
    }
    int mid = (l + r) / 2;

    H[2*v] += Nho[v];
    Nho[2*v] += Nho[v];
    H[2*v+1] += Nho[v];
    Nho[2*v+1] += Nho[v];
	Nho[v]=0;

    update(2*v, l, mid, p, q, g);
    update(2*v+1, mid+1, r, p, q, g);

    H[v] = max(H[2*v], H[2*v+1]);
}

int main()
{
    nhapmang();
    build(1, 1, n);
    
    return 0;
}
