class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans= new int[n];

        int nozero_prod=1;
        int n_zero=0;
        int zero_idx=-1;

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                n_zero++;
                zero_idx=i;
            }
            else{
                nozero_prod*=nums[i];
            }
        }

        //1 ho toh thik h usko chodd kar sabko 0 value dedo
        //but you cannot use n_zero>0
        //bcz if we have like
        //[2, 0, 0, 2]
        //then nums[1]=0 too since there is another 0 to turn its Product of Array Except Self  as 0  
        if(n_zero==1){
            Arrays.fill(ans, 0);
            ans[zero_idx]=nozero_prod;
        }

        else if(n_zero==0){
            for(int i=0; i<n; i++){
                ans[i]=nozero_prod / nums[i];
            }
        }

        return ans;

    }
}