#include<stdio.h>
#include<math.h>
int CanBacN(int n,int x){
	if(n==0)
	return 0;
	int s=1;
	s= pow(x,n);
	return s;
	}
int main(){
	int n,x;
	printf(" nhap n:");
	scanf("%d",&n);
	printf(" nhap x:");
	scanf("%d",&x);
	if (n<0){
	return 0;
	}
	else{
		int s=CanBacN(n,x);
		printf("ket qua:%d",s);
		}
		return 0;
		}

