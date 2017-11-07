#include <stdio.h>

void prin(int *arr,int s,int m) //Prints Array
{
	for(int i=s;i<=m;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

int merge_count(int *arr,int s,int m,int l)
{
	int count=0,k=0,i=0,j=0,c=(l+1)-s;
	int arr1[100],arr2[100];

	for(i=0;i<=m-s;i++)
		arr1[i] = arr[s+i];

	for(i=0;i<l-m;i++)
		arr2[i] = arr[m+1+i];

	i = 0;
	while(k<c && i!=(m+1)-s && j!=(l+1)-(m+1))
	{ 
		if(arr1[i] > arr2[j])
		{
			arr[s + k++] = arr2[j++];
			count+=(m+1-s-i);
		} 
		else
			arr[s + k++] = arr1[i++];
	}	

	while(j < (l+1)-(m+1))
	{
		arr[s + k++]=arr2[j++];
	}

	while(i < (m+1)-s)
	{
		arr[s + k++]=arr1[i++];
	}

	return count;
}

int count_inv(int *arr,int s,int l)
{
	int m,x=0,y=0,z=0;
	m = (s+l)/2;
	if (s < l)
	{
		x = count_inv(arr,s,m);
		y = count_inv(arr,m+1,l);
		z = merge_count(arr,s,m,l);
		return x + y + z;
	}
	else
		return 0;
}

void main()
{
	int arr[100], count = 0,l=0,i;
	printf("Size of Array.\n");
	scanf("%d",&l);
	for(i=0;i<l;i++)
		scanf("%d",&arr[i]);

	count = count_inv(arr,0,l-1);
	printf("Inversion = %d\n",count);
	prin(arr,0,l-1);
}