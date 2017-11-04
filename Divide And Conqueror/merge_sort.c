#include <stdio.h>

void prin(int *arr,int s,int m) //Prints Array
{
	for(int i=s;i<=m;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

void merge(int *arr,int s,int m,int l)
{
	int k=0,i=0,j=0,c=(l+1)-s;
	int arr1[100],arr2[100];

	for(i=0;i<(m+1)-s;i++)
		arr1[i]=arr[s+i];
	
	for(i=0;i<(l+1)-(m+1);i++)
		arr2[i]=arr[m+1+i];

	i=0;
	while(k<c && i!=(m+1)-s && j!=(l+1)-(m+1)) 
		arr[s + k++] = (arr1[i]>arr2[j]) ? arr2[j++] : arr1[i++]; 

		while(j < (l+1)-(m+1))
			arr[s + k++]=arr2[j++];

		while(i < (m+1)-s)
			arr[s+k++]=arr1[i++];
}

void sort(int *arr,int s,int l)
{
	int m=0;
	if (s < l)
	{
		m=(s+l)/2;
		sort(arr,s,m);
		sort(arr,m+1,l);
		merge(arr,s,m,l);
	}
}

void main()
{
	int arr[100];
	int i,l=0,s=0;
	printf("Give size of array\n");
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,s,l-1);
	prin(arr,0,l-1);
}