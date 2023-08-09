class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[] = new int[2];
        HashMap<Integer,Integer> present = new HashMap<Integer,Integer>();
           
        for(int i=0;i<nums.length;i++)
        {
            if(present.containsKey(target-nums[i]))
            {
                int ind = present.get(target-nums[i]);
                if(ind!=i)
                {
                    ans[0] = ind;
                    ans[1] = i;
                    return ans;
                }
            }
             present.put(nums[i],i);
        }
        return ans;
    }
}