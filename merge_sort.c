# include <stdio.h>
# define MAX_SIZE  10
int tmp[MAX_SIZE];

void merge(int a[], int low, int mid, int high){
    int k, left,right;
    for(k=low; k<=high; k++){
        tmp[k] = a[k];
    }
    for(left=low,right=mid+1,k=low; left<=mid&&right<=high;k++)
        a[k] = tmp[left]<tmp[right]?tmp[left++]:tmp[right++];
    while(left <= mid)
        a[k++] = tmp[left++];
    while(right <= high)
        a[k++] = tmp[right++];
}

void merge_sort(int a[], int low, int high){  //initial low=0, high=arr_len-1
   if (low < high){
       int mid = (low+high)/2;
       merge_sort(a, low, mid);
       merge_sort(a, mid+1, high);
       merge(a, low, mid, high);
   }
}


//test case
int main(){
    int a[] = {88,34,65,78,49,23,90,12,17,76};

    int i;
    printf("未排序前：\n");
    for(i=0;i<MAX_SIZE;i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n经过排序后：\n");
    merge_sort(a, 0, MAX_SIZE-1);
    for(i=0;i<MAX_SIZE;i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}
