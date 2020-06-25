class Solution
{
public:
    vector<int> memo;
    int numTrees(int n)
    {
        memo = vector<int>(n+1,-1);
        return get_num_trees(n);
    }

    int get_num_trees(int n){
        if(memo[n] != -1) return memo[n];
        if(n==1){
            memo[n] = 1;
            return 1;
        }
        if(n==0){
            memo[n] = 1;
            return 1; 
        }
        int sum = 0;
        for(int i =1;i<=n;i++){
            int left_subtree_num =  get_num_trees(i-1);
            int right_subtree_num = get_num_trees(n-i);
            sum += left_subtree_num * right_subtree_num;
        }
        memo[n] = sum;
        return sum;
    }
};