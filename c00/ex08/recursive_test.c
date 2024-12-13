#include<stdio.h>

void recursive(int n)
{	
	if(n==5)
	{
		printf("我的递归在第%d次被停止了，我现在要开始返回了\n",n);	
		return;
	}

	printf("我现在要进行第%d次递归\n",n);
	recursive(n+1);	
	printf("我现在要进行第%d次返回\n",n);
	
}



int main()
{
	recursive(1);
	return 0;
}
