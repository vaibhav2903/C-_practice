#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
bool paranthesis(string s);
int main(){
	string S;
	cin>>S;
	if(paranthesis(S))
		cout<<"Valid"<<endl;
	else{
		cout<<"Invalid"<<endl;
		}
return 0;
}
struct Stack{
int top;
unsigned capacity;
char A[100];
};
bool isEmpty(struct Stack* S){
	//return (s->top==1)? true:false;
	if(S->top==-1)
		return true;
	else{	
		return false;}
}
void push(struct Stack* S,char a){
	S->A[++S->top]=a;
	return;
}
char pop(struct Stack* S){
	if(isEmpty(S))
		return '1';
	return S->A[S->top--];
}
bool paranthesis(string S){
bool m = true; //Assume String is valid at first
struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
int l= S.length();
int i=0 ;char k;
while(i<l ){
	//cout<<"1"<<endl;
	if(S[i]=='('|| S[i]=='['||S[i]=='{')
		{push(s,S[i]);
			//cout<<S[i]<<" pushed"<<endl;
		}
	else if(S[i]==')'||S[i]=='}'||S[i]==']')
	{	if(isEmpty(s))
			m=false;
		else{
			k = pop(s);
			//cout<<k<<" popped"<<endl;
			if((S[i]==')' && k == '(')||(S[i]==']' && k == '[')||(S[i]=='}' && k == '{'))
				{//cout<<"1"<<endl;
		}	
			else{
				m = false;
				}
		}
	}
	i++;
}
return m;
}