#include <stdio.h>
int L(int a,int b){
	return (10*a+b);
}
int main(){
	int i=2,k,m;
	k = L(i++,i++);
	i=2;
	m = L(i++,3*i++);
	printf("%d %d\n",k,m);
	return 0;
}