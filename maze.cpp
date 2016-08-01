#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;
void printsol(char A[MAX][MAX]);
void maze_path(int maze[10][10]);
bool mazeUtil(int maze[10][10],int curr_i,int curr_j,bool b[10][10]);
char sol[10][10];
int main(){
	int maze[10][10],i,j;

	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			cin>>maze[i][j];
maze_path(maze);
	return 0;
}


void maze_path(int maze[10][10]){
int i,j;
 	bool b[10][10];
 		for(i=0;i<10;i++)
 			for(j=0;j<10;j++)
 				b[i][j]=false;
 	
// char sol[10][10];
 for(i=0;i<10;i++)
 	for(j=0;j<10;j++)
 		sol[i][j]='.';

	if(mazeUtil(maze,0,0,b))
		printsol(sol);
return;
 }
 void printsol(char A[10][10]){
 	int i,j;
 	for(i=0;i<10;i++)
 		{for(j=0;j<10;j++)
 			cout<<A[i][j];
 		cout<<endl;}
 		return;
 }
bool mazeUtil(int maze[10][10],int curr_i,int curr_j,bool b[10][10]){
	if(curr_i<0 || curr_j<0 || curr_i>=10 || curr_j>=10)
		return false;
	if(maze[curr_i][curr_j]==1)
		return false;
	else if(b[curr_i][curr_j])
		return false;
	else if(curr_i==9 && curr_j==9)
		{	sol[curr_i][curr_j]='#';
			//cout<<"=>"<<"["<<curr_i<<"]"<<"["<<curr_j<<"]";
			return true;
		}	
	else{
		b[curr_i][curr_j]=true;
		if(mazeUtil(maze,curr_i+1,curr_j,b) )
			{
				//cout<<"=>"<<"["<<curr_i<<"]"<<"["<<curr_j<<"]"<<"=>";
				sol[curr_i][curr_j]='#';
			return true;
		}
		else if(mazeUtil(maze,curr_i-1,curr_j,b))
			{//cout<<"=>"<<"["<<curr_i<<"]"<<"["<<curr_j<<"]";
				sol[curr_i][curr_j]='#';
			return true;
		}
		else if(mazeUtil(maze,curr_i,curr_j-1,b))
		{  //cout<<"=>"<<"["<<curr_i<<"]"<<"["<<curr_j<<"]";
			sol[curr_i][curr_j]='#';
			return true;
		}
		else if(mazeUtil(maze,curr_i,curr_j+1,b))
		{  //cout<<"=>"<<"["<<curr_i<<"]"<<"["<<curr_j<<"]";
			sol[curr_i][curr_j]='#';
			return true;
		}

		else return false;
	}

}
