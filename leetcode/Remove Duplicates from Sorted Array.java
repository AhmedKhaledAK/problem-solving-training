class Solution {
    public int removeDuplicates(int[] nums) {
        // according to this output, you just need to count unique numbers without removing any
        // but we will solve it by removing duplicates
        if(nums.length == 0) return 0;
        int j = 0, i =0;
        for(; i < nums.length-1; i++){
            if(nums[i] != nums[i+1])
                nums[j++] = nums[i];
        }
        nums[j] = nums[i];
        return j+1;
    }
}
