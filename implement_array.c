#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int arr[100];

    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    printf("Enter elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array before insertion:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    //Insertion of element into the array
    int val,idx;
    printf("\nEnter the element to insert into the array: ");
    scanf("%d",&val);
    printf("Enter the index (0 to %d) for placing the element: ", n);
    scanf("%d",&idx);

    if (idx >=0 && idx <= n){
        for (int i = n; i > idx; i--){
             arr[i] = arr[i-1];
        }
        arr[idx] = val;
        n++;
    } else {
        printf("Invalid index!\n");
    }

    printf("\nArray after insertion:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }



    //Deletion of element from the array
    int ele;
    printf("\nEnter the element to delete ");
    scanf("%d",&ele);

    int i = 0;
    while (i < n && arr[i] != ele){
        i += 1;
    }

    if (i < n){
        while (i+1 < n){
            arr[i] = arr[i+1];
            i+=1;
        }
        n--;
    }
    else{
        printf("Element not found!\n");
    }
    

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}