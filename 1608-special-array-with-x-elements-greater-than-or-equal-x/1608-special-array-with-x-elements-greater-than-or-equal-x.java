class Solution {
    public int specialArray(int[] nums) {
        for(int i=1;i<101;i++){
            int count=0;
            for(int num:nums){
                if(num>=i)
                    count++;
            }
            if(i==count)
                return i;
        }
        return -1;
    }
}