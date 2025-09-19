#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, ele;
    printf("Enter the number of elemnts in the array");
    scanf("%d",&n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search");
    scanf("%d", &ele);

    int l = 0, mid;
    int h = n-1, found=0;

    while (l <= h){
        mid = (l+h)/2;
        if (arr[mid] == ele){
            printf("Element found at index %d", mid);
            found = 1;
            break;
        }
        else if(arr[mid] > ele){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    if(!found){
        printf("Element not found");
    }

    return 0;
}