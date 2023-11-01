void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Sorted(int *arr, int length){
     // sorted
    for(int i=0; i < (length-1); ++i){
        for(int j=i+1; j < length; ++j){
            if(arr[j] < arr[i]) swap(&arr[j], &arr[i]);
        }
    }
}
double rt_func(int *arr, int length){
    if((length % 2) == 1) return (double)arr[length/2];
    if((length % 2) == 0) return (double)((double)(arr[length/2]+arr[length/2-1]) / 2);
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size == 0){
        Sorted(nums2, nums2Size);
        return rt_func(nums2, nums2Size);
    } else if(nums2Size == 0){
        Sorted(nums1, nums1Size);
        return rt_func(nums1, nums1Size);
    }
    else{
    int merge_arr[nums1Size + nums2Size];
    int m = nums1Size - 1; // =1
    int n = nums2Size - 1; // =1
    int length = nums1Size + nums2Size; //=4

    for ( int i=0; i < length; ++i){
        if(i <= m){ // <= 1, 0->1
            merge_arr[i] = nums1[i];
        }
        if(i > m){ // i= 2, 2->3, 0->1
            merge_arr[i] = nums2[i-nums1Size];
        }
    }
    Sorted(merge_arr, length);
    return rt_func(merge_arr, length);
    // for(int i=0; i<length; ++i){ printf("%d\n", merge_arr[i]);}
    }
    return 0;
}
