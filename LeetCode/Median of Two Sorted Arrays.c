double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums[nums1Size + nums2Size], y=nums1Size+nums2Size,i,key,j;
    double result;
    for (i = 0; i < nums1Size; i++) {
        nums[i] = nums1[i];
    }
    for (i = 0; i < nums2Size; i++) {
        nums[nums1Size + i] = nums2[i];
    }

    for (i = 0; i < y; i++) {
        key = nums[i];  
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];  
            j = j - 1;
        }
        nums[j + 1] = key;
    }
    

    for(int i=0;i<y;i++){
        printf("%d ",nums[i]);
    }
    
    if(y%2!=0){
        y/=2;
        return nums[y];
        
    }else if(y%2==0){
        int a =y/2, b=(y+1)/2;
        return ((nums[y / 2 - 1] + nums[y / 2])/2.0);
        
    }
    else{
        return 0;
    }   
}