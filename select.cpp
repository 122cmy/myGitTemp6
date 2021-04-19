#include<iostream>
#include<stdlib.h>
using namespace std; 
void merge(int A[],int l,int r,int mid);
void merge_sort(int A[],int l,int r);
int select(int A[],int l,int r,int k);
int main()
{
    int n;
    cout<<"请输入数组的大小：";
    cin>>n;
    cout<<"请输入数组：";
	int A[n]; 
    for(int i=0;i<n;i++)
    {
    	cin>>A[i];
	}
	int k;
	cout<<"请输入k：";
	cin>>k; 
	cout<<"第"<<k<<"小的数为："<<select(A,0,n,k)<<endl;
    return 0;
}
void merge(int A[],int l,int r,int mid)
{
    int i,k;
    int l1=l,l2=mid,r1=mid+1,r2=r;
    int *temp=(int *)malloc((r-l+1)*sizeof(int));
    for(k=0;l1<=l2 && r1<=r2;k++)
	{
        if(A[l1]<=A[r1])
            temp[k]=A[l1++];
		else
            temp[k]=A[r1++];
    }
    if(l1<=l2)
	{
	    for(i=l1;i<=l2;i++)
	    	temp[k++]=A[i];
    }
    if(r1<=r2)
	{
        for(i=r1;i<=r2;i++)
        	temp[k++]=A[i];
    }
    for(i=0;i<r-l+1;i++)
    	A[l+i]=temp[i];
    return;
}
void merge_sort(int A[],int l,int r)
{
    int mid=0;
    if(l<r)
	{
        mid=(l+r)/2;
        merge_sort(A,l,mid);
        merge_sort(A,mid+1,r);
        merge(A,l,r,mid);
    }
    return;
}


int select(int A[],int l,int r,int k) 
{
	int n=r-l;
	if (n<5)
	{
		merge_sort(A,l,r-1);
		return A[l+k-1];
	}
	int i;
	int *m = new int[n/5];
	for (i=0;i<n/5;i++) 
	{
		merge_sort(A,l+i*5,l+i*5+5-1);
		m[i] = A[l+i*5+2];
	}
	merge_sort(m,0,i-1);
	int mid=m[i/2];
	int *A1=new int[n];
	int *A2=new int[n];
	int *A3=new int[n];
	int num1=0,num2=0,num3=0;
	for(int i=l;i<r;i++)
	{
		if(A[i]<mid)
			A1[num1++]=A[i];
		else if(A[i]==mid)
			A2[num2++]=A[i];
		else
			A3[num3++]=A[i];
	}
	if(num1>=k)
		return select(A1,0,num1,k);
	if (num1+num2>=k)
		return mid;
	else
		return select(A3,0,num3,k-num1-num2);
}
 


