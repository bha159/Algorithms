#include <stdio.h> 

void prin(int n,int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int n,i,j,arr1[100][100] = {0},arr2[100][100] = {0},arr3[100][100] = {0};
	printf("Size Of Matrix.\n");
	scanf("%d",&n);
	printf("Input Matrix1\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&arr1[i][j]);

	/*for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d",arr1[i][j]);*/


	/*printf("Input Matrix2\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&arr2[i][j]);*/

	prin(n,arr1);
	/*printf("hfadf;ldkf\n");
	prin((int *)arr2,n);*/
	// arr3 = mul(arr1,arr2);
	// prin(arr3,n);
}