#include <iostream>

using namespace std;
int a[50],x[50],n;
long long N;

void tachchuso(long long N, int a[], int &n)
{
    n=0;
    a[0]=0;
    while (N>0)
    {
        a[n] = N % 10;
        N = N/10;
        n++;
    }
}

void vietmangx(int a[], int n)
{
    for (int i=n-1; i>=0; i--) cout<<a[i];
    cout << " ";
}

void thu(int i, bool gh)
{
    if (i<0)
    {
        vietmangx(x,n);
        return;
    }
    int maxc = gh ? a[i] : 9;
    for (int c=0; c<= maxc; c++)
    {
        x[i]=c;
        bool ghm = gh && (c == a[i]);
        thu(i-1, ghm);
    }
}

int main()
{
    cout << "Nhap so N ";
    cin >> N;
    tachchuso(N,a,n);
    thu(n-1, true);
    return 0;
}