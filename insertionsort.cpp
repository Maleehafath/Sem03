#include<iostream>
using namespace std;
int main()
{
    int ub,a[100],n,j,lb,key;
    cout<<"Enter the size of the array"<<'\n';
    cin>>n;
    cout<<"Enter the elements of the array"<<'\n';
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }   
    cout<<"The array is:"<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Enter the lowerbound of the array:"<<'\n';
    cin>>lb;
    cout<<endl<<"Enter the upperbound of the array:"<<'\n';
    cin>>ub;   
    for(int i=lb+1;i<=ub;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=lb && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1; 
    }
    a[j+1]=key;
    }  
    for(int i=0;i<=ub;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}