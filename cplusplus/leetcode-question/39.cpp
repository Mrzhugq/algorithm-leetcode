//C++
class Solution
{
	private:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
		{
			if (sum > target)
			{
				return;
			}
			if (sum == target)
			{
				result.push_back(path);
				return;
			}
			for (int i = startIndex; i < candidates.size(); i++)
			{
				sum += candidates[i];
				path.push_back(candidates[i]);
				backtracking(candidates, target, sum, i); //不用i+1了，表示可以重复读取当前的数
				sum -= candidates[i];
				path.pop_back();
			}
		}
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target)
		{
			result.clear();
			path.clear();
			backtracking(candidates, target, 0, 0);
			return result;
		}
}
		
		
		
		
		
		
		
		
		
		
		
//C	
int candidatesSize_tmp;

int ansSize;

int combineSize;

int* ansColumnSize;

void dfs(int* candidates, int target, int** ans, int* combine, int idx)
{
	if (idx == candidatesSize_tmp)
	{
		return;
	}
	if (target == 0)
	{
		int* tmp = malloc(sizeof(int) * combineSize);
		for (int i = 0; i < combineSize; ++i)
		{
			tmp[i] = combine[i];
		}
		ans[ansSize] = tmp;
		ansColumnSize[ansSize++] = combineSize;
		return;
	}
	// 直接跳过
	dfs(candidates, target, ans, combine, idx + 1);
	// 选择当前数
	if (target - candidates[idx] >= 0)
	{
		combine[combineSize++] = candidates[idx];
		dfs(candidates, target - candidates[idx], ans, combine, idx);
		combineSize--;
	}
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
	candidatesSize_tmp = candidatesSize;
	ansSize = combineSize = 0;
	int** ans = malloc(sizeof(int*) * 1001);
	ansColumnSize = malloc(sizeof(int) * 1001);
	int combine[2001];
	
	dfs(candidates, target, ans, combine, 0);
	
	*returnSize = ansSize;
	*returnColumnSizes = ansColumnSize;
	return ans;
}	