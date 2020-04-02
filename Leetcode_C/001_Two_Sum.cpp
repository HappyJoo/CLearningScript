/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// brute force
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *a = (int*)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize; i++)
        {
            for(int j = i + 1; j < numsSize; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    *returnSize = 2;
                    a[0] = i;
                    a[1] = j;
                    return a;
                }
            }
        }
    return 0;
}

// Second method
typedef struct {
    int val;
    int index;
} NumMap;

int Cmp_Array(const void* a, const void* b) {
    // if the return-value is smaller than 0, qsort will order 'a' before 'b'.
    // if greater than 0, 'b' will before 'a'.
    return *(int*)a - *(int*)b;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    NumMap* map = calloc(numsSize, sizeof(NumMap));

    for (int i = 0; i < numsSize; i++) {
        map[i].val = nums[i];
        map[i].index = i;
    }
    qsort(map, numsSize, sizeof(NumMap), Cmp_Array);
    int l = 0;
    int r = numsSize - 1; 
    while (l < r) {   
        int sum = map[l].val  + map[r].val;
        if (sum < target) {
            l++;
        } else if (sum > target) {
            r--;
        } else {
            int* res = calloc(2, sizeof(int));
            res[0] = map[l].index;
            res[1] = map[r].index;
            *returnSize = 2;
            return res;
        }
    }
    *returnSize = 0;
    return NULL;
}