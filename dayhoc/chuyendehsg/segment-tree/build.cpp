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
	//cout<<"Xay dung nhanh do nut "<<v<<" quan li doan "<<l<<"..."<<r<<endl;
	if (l == r)
	{
		H[v] = A[l];
		//cout<<" gan H["<<v<<"]=A["<<l<<"]"<<endl;
		return ;
	}
	int mid = (l+r) / 2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	H[v] = H[2*v] + H[2*v+1];
	//cout<<" tinh H["<<v<<"]="<<H[v]<<endl;
}

void vietmangh()
{
	for (int i=1; i<2*n; i++) cout<<H[i]<<" ";
	cout<<endl;
}
int main()
{
    nhapmang();
    build(1, 1, n);
    vietmangh();
    return 0;
}
