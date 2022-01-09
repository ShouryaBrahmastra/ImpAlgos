#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n, mx = INT_MIN, sum = 0;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++)
  {
    sum = max(arr[i], sum + arr[i]);
    mx = max(mx, sum);
  }

  cout << mx << endl;

  return 0;
}