#include <bits/stdc++.h>
using namespace std;

void print (int ** arr, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << arr[i][j] <<" ";
        }
        //cout << endl;
    }   
    cout << endl;
}


inline bool check(int  arr[][20], int ** output, int row, int column,int n){
    if(column>=0 && column < n && row>=0 && row < n){
        if(arr[row][column]==1 && output[row][column]==0 ) 
            return true;
    }
    return false;
}

void ratMaze(int  arr[][20],int row ,int column ,int n,int ** output){

    if(row==n-1 && column== n-1){
        output[row][column]=1;
        print(output,n);
        return;
    }

    if(check(arr,output,row,column,n)){
        output[row][column]=1;
        for(int i=-1;i<2;i+=2) {
            ratMaze( arr, row,column+i, n,output);
            ratMaze(arr,row+i, column,n,output); 
        }
        output[row][column]=0;
    }
}



void ratInAMaze(int maze[][20], int n){

 
	int ** output = new int * [n];
    for(int i=0;i<n;i++)
        output[i] = new int[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            output[i][j]=0;
    }
    ratMaze(maze, 0,0,n,output);

}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}


