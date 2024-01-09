#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low,int high){
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void selectionSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void insertionSort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}

void bubbleSort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int f(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void qs(int arr[],int low,int high){
    if(low<high){
        int partition=f(arr,low,high);
        qs(arr,low,partition-1);
        qs(arr,partition+1,high);
    }
}

int main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //merge sort
    // mergeSort(arr,0,n-1);

    //selection sort
    // selectionSort(arr,n);

    //insertion sort
    // insertionSort(arr,n);

    //bubble sort
    // bubbleSort(arr,n);

    //quick sort
    qs(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
