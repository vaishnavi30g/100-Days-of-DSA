/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     int* arr = (int*)malloc(2 * sizeof(int));
     for(int i = 0 ; i < numsize ; i++ ){
        for(int j = i+1 ; j < numsize ; j++){
            if ( num[i] + num[j] = target){
                arr[0] = i;
                arr[1] = j;
                *returnSizev = 2;
                return arr;
            }
        }
     }
    *returnSize = 0;
    return NULL;
}
