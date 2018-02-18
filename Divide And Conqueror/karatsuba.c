#include <stdio.h>
#include <math.h>

long length(int z)
{
	long count = 0.0;
	while(z>0)
	{
		z = z/10;
		count++;
	}
}

long mul(long x,long y)
{
	if(x % 10 <= 9)
		return x * y;
	else
	{
		long a,b,c,d,p1,p2,l,po;
		l = length(x);
		po = (long)pow(10.0,(long)(l/2));
		b = x % po;
		d = y % po;
		a = x / po;
		c = x / po;
		p1 = mul(a,c);
		p2 = mul(b,d);
		return (p1 * pow(10,l)) + (mul((a+b),(c+d)) - (p1+p2)) * pow(10,(long)(l/2)) + (p2); 
	}
}

void main()
{
	long x,y,ans;
	printf("First Number\n");
	scanf("%ld",&x);
	printf("Second Number\n");
	scanf("%ld",&y);
	ans = mul(x,y);
	printf("Answer = %ld\n",ans);
}