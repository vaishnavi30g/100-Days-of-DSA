/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int minSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int *result = (int*)malloc(minSize * sizeof(int));
    int k = 0;
    for(int i = 0;i<nums1Size;i++){
        for(int j = 0;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                result[k++] = nums1[i];
                nums2[j] = -1000001;
                break;
            }
        }
    }
    *returnSize = k;
    return result;
}
