#include<iostream>
using namespace std;
template <typename T>void selection_sort(T arr[],int n){
    for(int i=0;i<n-1;i++){
        int mi=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mi]){
                mi=j;
            }
        }
        if(mi!=i){
            swap(arr[mi],arr[i]);
        }
    }
}
int main(){
    cout<<"Selection Sort Using Template...\n";
    cout<<"Enter number of values in integer array : ";
    int n1;cin>>n1;
    int ar[n1];
    for(int i=0;i<n1;i++){
        cin>>ar[i];
    }
    cout<<"Enter number of values in float array : ";
    int n2;cin>>n2;
    float ar1[n2];
    for(int i=0;i<n2;i++){
        cin>>ar1[i];
    }
    selection_sort<int>(ar,n1);
    selection_sort<float>(ar1,n2);
    cout<<"Sorted Integer Array is : ";
    for (int i=0;i<n1;i++){
        cout<<ar[i]<<" ";
    }
    cout<<"\nSorted Float Array is : ";
    for (int i=0;i<n2;i++){
        cout<<ar1[i]<<" ";
    }
}