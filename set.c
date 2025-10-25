#include<stdio.h>
#include<stdlib.h>

struct bit{unsigned char x:1;};
int uset[]={1,2,3,4,5,6,7,8,9},size=9;

void main()
{
	void readset(struct bit[],int n);
	void printset(struct bit[]);
	void unionset(struct bit[],struct bit[],struct bit[]);
	void intersect(struct bit[],struct bit[],struct bit[]);
	void diffrence(struct bit[],struct bit[],struct bit[]);
	
	struct bit a[10]={0},b[10]={0},c[10]={0};
	int n;
	printf("number of element in setA:");
	scanf("%d",&n);
	readset(a,n);
	printf("number of element in setB:");
	scanf("%d",&n);
	readset(b,n);
	printf("setA:");printset(a);
	printf("setB:");printset(b);
	unionset(a,b,c);
	printf("AuB=");printset(c);
	intersect(a,b,c);
	printf("A intersect B=");printset(c);
	diffrence(a,b,c);
	printf("A-B=");printset(c);
}

// to read set and store as bit string

void readset(struct bit a[],int n)
{
	int i,x,k;
	printf("enter %d element:",n);
	for(i=0; i<n;++i)
	{
		scanf("%d",&x);
		for(k=0;k<size;++k)
		if(uset[k]==x)//if x is member of universal set
		{
	            // set 1 corresponding to x in a[]
		
		a[k].x=1;
		break;
		}
	}
	return;
}

// to print a set from bit string reprecentation

void printset(struct bit a[])
{
	int x,k;
	printf("{");
	for(k=0;k<size;++k)
	if (a[k].x==1)
	printf("%d,",uset[k]);
	printf("}\n");
	return;
}

// to find union of two sets usind bitstring

void unionset(struct bit a[],struct bit b[],struct bit c[])

{

	int k;
	for(k=0;k<size;++k)
	c[k].x=a[k].x|b[k].x;
	return;
}

// to find intersection of two sets

void intersect(struct bit a[],struct bit b[],struct bit c[])
{
	int k;
	for(k=0;k<size;++k)
	c[k].x=a[k].x&b[k].x;
	return;
}

// to find diffrence of two set

void diffrence(struct bit a[],struct bit b[],struct bit c[])
{
	int k;
	for(k=0;k<size;++k)
	if (a[k].x==1)
	c[k].x=a[k].x^b[k].x;
	return;
}
	

