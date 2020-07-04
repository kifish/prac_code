

/*


        for(int i = 0;i < beforeItems.size(); ++i){
            for(auto it : beforeItems[i]){
                if(group[i] == group[it]){
                    itemIndegree[i]++; // 构建项目间的依赖
                    itemGraph[it].insert(i); 
                }else{ // 说明这2个项目有顺序要求,且是两个不同的组来负责这2个项目; 项目i依赖it
                    if(!groupGraph[group[it]].count(group[i])){
                        groupIndegree[group[i]]++; // 项目i所在的组 入度加1
                        groupGraph[group[it]].insert(group[i]);// 项目it所在的组 指向项目i所在的组
                    }
                }
            }
        }

然后先进行组的排序, 再进行组内项目的排序

作者：mike-meng
链接：https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/solution/tuo-bu-pai-xu-by-mike-meng/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

    }
};



