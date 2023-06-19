class Solution {
public:
int maxProduct(vector<int>& nums) {
    int max1;
	int max2;
	if(nums[0] > nums[1]){
		max1 = nums[0];
		max2 = nums[1];
	}else{
		max1 = nums[1];
		max2 = nums[0];
	}
	for(int j = 2 ; j < nums.size() ; j++){
		if(nums[j] > max1){
			max2 = max1;
			max1 = nums[j];
		}
		else if(nums[j] > max2){
			max2 = nums[j];
		}
	}
	return (max1-1) * (max2-1);
}
};