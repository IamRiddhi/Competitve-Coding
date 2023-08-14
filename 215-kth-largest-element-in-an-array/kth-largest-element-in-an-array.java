import java.util.concurrent.ThreadLocalRandom;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        quickSort(nums , 0 , nums.length - 1 , k);
        
        return nums[k - 1];
    }
    
    private void quickSort(int[] nums , int l , int u , int k)
    {
        if(l >= u)
            return ;
        
         int pivot = ThreadLocalRandom.current().nextInt(l , u);
        
         swap(nums , l , pivot);
         
        int index = partition(nums , l , u , k) ;
        
        if( index < (k - 1))
            quickSort(nums , index + 1 , u , k);
        else if(index > (k -1))
            quickSort(nums , l , index - 1, k);
        
    }
    
    private int partition(int[] nums , int l , int u , int k)
    {
        int pivot = l;
        int pos = l + 1;
        
        for(int i = l + 1; i <= u ; i++)
        {
            if(nums[pivot] < nums[i])
            {
                swap(nums , i , pos);
                pos++;
            }
        }
        
        pos--;
        
        swap(nums , pos , pivot);
        
        return pos;
        
    }
    
     private void swap(int[] nums , int i , int j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    
}