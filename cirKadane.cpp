//This program will find out the max sub array sum of a circular array in O(N)
#include <iostream>
#include <climits>

using namespace std;
int kadane(int arr[],int n);
int main(){
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int wrapSum,nonWrapSum,total=0;
	
	nonWrapSum=kadane(arr,n);
	for(int i=0;i<n;i++){
		total+=arr[i];
		arr[i]=-arr[i];
	}
	wrapSum=total+kadane(arr,n);

	cout<<max(wrapSum,nonWrapSum)<<endl;

	return 0;
}

int kadane(int arr[],int n){
	int currSum=0,mx=INT_MIN;
	for(int i=0;i<n;i++){
		currSum+=arr[i];
		if(currSum<0){
			currSum=0;
		}
		mx=max(currSum,mx);
	}
	return mx;
}