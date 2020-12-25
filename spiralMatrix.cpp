//This program print a 2D array in spiral order

#include <iostream>
using namespace std;

int main(){

    int n,m; cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        } 
    }

    //spiral order print

    int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;

    while(rowStart <= rowEnd && colStart <=  colEnd){

        //for Row Start
        for(int col=colStart;col<=colEnd;col++){
            cout<<arr[rowStart][col]<<" ";
        }
        rowStart++;

        //for Col End
        for(int row=rowStart;row<=rowEnd;row++){
            cout<<arr[row][colEnd]<<" ";
        }
        colEnd--;

        //for Row End
        for(int col=colEnd;col>=colStart;col--){
            cout<<arr[rowEnd][col]<<" ";
        }
        rowEnd--;

        //for Col Start
        for(int row=rowEnd;row>=rowStart;row--){
            cout<<arr[row][colStart]<<" ";
        }
        colStart++;
    }
    cout<<endl;

    return 0;
}