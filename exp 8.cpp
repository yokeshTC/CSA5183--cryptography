#include<stdio.h>
#include<math.h>
int main()
{
	int a,q,xa,xb,ya,yb,ka,kb;
	printf("Enter the value of a:");
	scanf("%d",&a);
	printf("Enter the value of q:");
	scanf("%d",&q);
	printf("Enter the value of xa:");
	scanf("%d",&xa);
	printf("Enter the value of xb:");
	scanf("%d",&xb);
	int x =pow(a,xa);
	ya =x%q;
	int y =pow(a,xb);
	ya =y%q;
	int m =pow(yb,xa);
	ya =m%q;
	int n =pow(ya,xb);
	ya =n%q;
	printf("Secret key value of user A:%d",ka);
	printf("Secret key value of user B:%d",kb);
}