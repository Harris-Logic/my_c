class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int min_cost = INT_MAX;
		
		// 最大可能的步数组合长度（全走1步）
		int max_len = n;
		
		// 尝试所有可能的步数组合
		for (int mask = 0; mask < (1 << (max_len - 1)); ++mask) {
			int current_pos = 0;
			int total_cost = 0;
			bool valid = true;
			
			// 从第0阶开始的情况
			while (current_pos < n) {
				total_cost += cost[current_pos];
				
				// 根据mask决定走1步还是2步
				if (mask & (1 << current_pos)) {
					current_pos += 2; // 走2步
				} else {
					current_pos += 1; // 走1步
				}
				
				// 检查是否越界
				if (current_pos > n) {
					valid = false;
					break;
				}
			}
			
			if (valid && total_cost < min_cost) {
				min_cost = total_cost;
			}
		}
		
		// 从第1阶开始的情况
		for (int mask = 0; mask < (1 << (max_len - 2)); ++mask) {
			int current_pos = 1;
			int total_cost = 0;
			bool valid = true;
			
			while (current_pos < n) {
				total_cost += cost[current_pos];
				
				if (mask & (1 << (current_pos - 1))) {
					current_pos += 2;
				} else {
					current_pos += 1;
				}
				
				if (current_pos > n) {
					valid = false;
					break;
				}
			}
			
			if (valid && total_cost < min_cost) {
				min_cost = total_cost;
			}
		}
		
		return min_cost;
	}
	// int minCostClimbingStairs(vector<int>& cost) {
	//     int n=cost.size();
	//     int allcost=0;
	//     int curcost[]=0;
	
	//     for(;;){
	//         int i=0;
	
	//         allcost+=cost[i];
	//         if(i>=n) break;
	//         for(;;){
	//             int j=i;
	
	//         }
	//     }
	// }
};
