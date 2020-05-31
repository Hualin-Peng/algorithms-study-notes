# include <stdio.h>

# define MAX_SIZE 1

int partition(int a[], int low, int high){
    int i, j, tmp;
    for(i=low-1,j=low; j<high; j++){
        if(a[j]<=a[high]){
            i++;
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    i++;
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;

    return i;
}

int quick_select(int a[], int low, int high, int k){ //第k大的数下标为k-1
    int mid;
    mid = partition(a, low, high);
    if (mid==0)
        return mid; //注意a中只有一个元素且k>1 的情况
    if(k-1==mid)
        return mid;
    else if(k-1<mid){
        return quick_select(a, low, mid-1, k);
    }
    else if(k-1>mid){
        return quick_select(a, mid+1, high, k);
    }
    return 0;
}

//test
int main(){
    //int a[] = {88,34,65,78,49,23,90,12,17,76};
    int a[] = {88};
    int i;
    int s;
    printf("Origin Array:\n");
    for(i=0; i<MAX_SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");
    
    s = quick_select(a, 0, MAX_SIZE-1, 3);
    printf("%d\n", s);

    printf("Sorted Array:\n");
    for(i=0; i<MAX_SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
