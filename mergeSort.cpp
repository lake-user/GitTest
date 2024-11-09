#include<iostream>
#include<vector>
using namespace std;
void merge(vector<vector<int>>&a,int start,int mid,int end){
    vector<vector<int>>b(end-start+1,vector<int>(2));
    int i=start,j=mid+1,k=0;
    while(i<=mid&&j<=end){
        if(a[i][0]<=a[j][0]){
            b[k++]=a[i++];
        }
        else b[k++]=a[j++];
    }
    while(i<=mid)b[k++]=a[i++];
    while(j<=end)b[k++]=a[j++];
    for(int i=start;i<=end;i++){
        a[i]=b[i-start];
    }
    b.clear();
}
void mergeSort(vector<vector<int>>&a,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
int main(){
    vector<vector<int>>a={{4,2},{6,7},{5,1},{2,3},{3,4}};
    mergeSort(a,0,a.size()-1);
    for(vector<int>arr:a){
        for(int x:arr){
            cout<<x<<" ";
        }
    }
    cout<<endl;
    return 0;
}