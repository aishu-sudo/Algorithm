#include <bits/stdc++.h>
using namespace std;
int lower_bound(int a[], int s, int n)
{
if (s < a[0])
return 0;
int idx, l = 0, r = n - 1;
while (l <= r)
{
int m = l + (r - l) / 2;
if (a[m] <= s)
{
idx = m;
l = m + 1;
}
else
r = m - 1;
}
int fidx, val = a[idx];
l = 0, r = n - 1;
while (l <= r)
{
int m = l + (r - l) / 2;
if (a[m] >= val)
{
fidx = m;
r = m - 1;
}
else
l = m + 1;
}
return fidx;
}
int upper_bound(int a[], int s, int n)
{
if (a[n - 1] < s)
return n;
int idx, l = 0, r = n - 1;
while (l <= r)
{
int m = l + (r - l) / 2;
if (a[m] > s)
{
idx = m;
r = m - 1;
}
else
l = m + 1;
}
return fidx;
}
int upper_bound(int a[], int s, int n)
{
if (a[n - 1] < s)
return n;
int idx, l = 0, r = n - 1;
while (l <= r)
{
int m = l + (r - l) / 2;
if (a[m] > s)
{
idx = m;
r = m - 1;
}
else
l = m + 1;
}
int fidx, val = a[idx];
l = 0, r = n - 1;
while (l <= r)
{
int m = l + (r - l) / 2;
if (a[m] <= val)
{
fidx = m;
l = m + 1;
}
else
r = m - 1;
}
return fidx;
}
int main()
{
int n, s;
cin >> n >> s;
int a[n];
for (int i = 0; i < n; i++)
cin >> a[i];
int lb = lower_bound(a, s, n);
int ub = upper_bound(a, s, n);
cout << ub << " " << lb << "\n";
}
