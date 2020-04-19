int search(int* nums, int numsSize, int target){
    // solution 1
    int l = 0, r = numsSize - 1;
    while(l<r)
    {
        int mid = l + ((r - l) >> 1);
        if((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            l = mid + 1;
        else 
            r = mid;
    }
    return l == r && nums[l] == target ? l : -1;


    // solution 2
    int l = 0, r = numsSize - 1;
    
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target) return mid;
        if(nums[l] <= nums[mid])
        {
            if(target >= nums[l] && target <= nums[mid])
                r = mid-1;
            else
                l = mid + 1;
        } else {
            if(target >= nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid-1;
        }
    }
    return -1;
}
