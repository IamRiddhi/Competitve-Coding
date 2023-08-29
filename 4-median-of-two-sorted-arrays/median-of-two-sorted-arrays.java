class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        
        if(n > m)
            return findMedianSortedArrays(nums2 , nums1);
        
        int l = 0;
        int u = n;
        
        while(l <= u)
        {
            int partitionX = l + (u - l) / 2;
            int partitionY = (n + m + 1) / 2 - partitionX;
            
            int leftMaxX = (partitionX == 0) ? Integer.MIN_VALUE : nums1[partitionX - 1];
            int leftMaxY = (partitionY == 0) ? Integer.MIN_VALUE : nums2[partitionY - 1];
            int rightMinX = (partitionX == n) ? Integer.MAX_VALUE : nums1[partitionX];
            int rightMinY = (partitionY == m) ? Integer.MAX_VALUE : nums2[partitionY];
            
            if(leftMaxX <= rightMinY && leftMaxY <= rightMinX)
            {
                if((n + m) % 2 == 0)
                    return (Math.max(leftMaxX , leftMaxY) + Math.min(rightMinX , rightMinY)) / 2.0;
                else
                    return Math.max(leftMaxX , leftMaxY) * 1.0;
            }
            else if(leftMaxX > rightMinY)
                u = partitionX - 1;
            else
                l = partitionX + 1;
        }
        
        return 0.0;
    }
}