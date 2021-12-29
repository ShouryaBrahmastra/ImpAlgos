// Moore Voting Algo finds majority element in array

#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int c = 1, res = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[res] == arr[i])
    {
      c++;
    }
    else
    {
      c--;
    }
    if (c == 0)
    {
      res = i;
      c = 1;
    }
  }

  cout << arr[res] << endl;

  return 0;
}