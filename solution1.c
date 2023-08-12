/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
            int *arr = (int *)malloc(sizeof(int) * 2);
            if(!arr) return 0;
            arr[0] = 0;
            arr[1] = 0; 
    for ( int i=0; i<(numsSize-1); ++i){
        for (int j=i+1; j < numsSize; ++j){
            if((nums[i] + nums[j]) == target){
                *returnSize = 2;
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
    *returnSize = 0;
    return 0;
    // free(returnSize);
}