#include<iostream>
using namespace std;
void merge(int *a,int s,int e)
{
    int mid = s + (e-s)/2;
    int i=s,j=mid+1,k=s;
    
    int temp[100];
    while(i<=mid && j<=e)
    {
        if(a[i]>a[j]){
            temp[k++] = a[j++];
        }
        else temp[k++] = a[i++];
    }
    while(i<=mid)temp[k++] = a[i++];
    while(j<=e) temp[k++] = a[j++];
    for(int x=s;x<=e;x++)
    {
        a[x] = temp[x];
    }
}

void mergesort(int a[],int s, int e)
{
    if(s>=e)return ;
    int mid = s + (e-s)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    merge(a,s,e);
}

int main()
{
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array = ";
    for(int i=0;i<n;i++)cin>>arr[i];
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)cout<<arr[i]<< " ";
    return 0;
}