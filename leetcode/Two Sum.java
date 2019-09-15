import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,ArrayList<Integer>> hm = new HashMap<>();
        for(int i =0;i < nums.length; i++){
            ArrayList<Integer> al;
            if(hm.get(nums[i])!=null){
                al = hm.get(nums[i]);
            }
            else {
                al = new ArrayList<>();
            }
            al.add(i);
            hm.put(nums[i], al);
        }
        int i=0,j=nums.length-1;
        int [] indexes = new int[2];
        Arrays.sort(nums);
        
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            } else if(nums[i]+nums[j]<target){
                i++;
            } else {
                indexes[0]=hm.get(nums[i]).get(0);
                indexes[1]=hm.get(nums[j]).get(0);
                if(indexes[0]==indexes[1])
                    indexes[1]=hm.get(nums[j]).get(1);
                break;
            }
        }
        return indexes;
    }
}
