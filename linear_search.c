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

    int found = 0;
    for(int i=0; i<n; i++){
        if (arr[i] == ele){
            printf("Element found at index %d", i);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Element not found");
    }

    return 0;
}