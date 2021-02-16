/*

parser

https://leetcode-cn.com/problems/mini-parser/


https://leetcode-cn.com/problems/mini-parser/solution/dui-bu-qi-ge-wei-liao-wo-shi-ge-zhi-zhan-cglh/


https://leetcode-cn.com/problems/mini-parser/solution/0385cmi-ni-yu-fa-fen-xi-qi-by-jasonchiuc-wmws/

                if( s[idx] == ']' && v.size() > 1 ) // 解析到']'且v.size() > 1, 说明当前的NestedInteger其实是被嵌套的, 因此要先弹出, 然后再加到上一级的NestedInteger的list中
                {
                    auto NI = v.back(); v.pop_back();
                    v.back().add(NI);
                }

作者：jasonchiucc-a
链接：https://leetcode-cn.com/problems/mini-parser/solution/0385cmi-ni-yu-fa-fen-xi-qi-by-jasonchiuc-wmws/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


https://leetcode-cn.com/problems/mini-parser/solution/c-jian-yi-ci-fa-fen-xi-qi-di-gui-han-shu-jie-fa-by/

https://leetcode-cn.com/problems/mini-parser/solution/ben-ti-can-kao-liao-ji-ben-ji-suan-qi-de-jie-ti-si/

https://leetcode-cn.com/problems/mini-parser/solution/python3ti-mu-bu-nan-zhi-xu-li-qing-luo-ji-by-salti/


TODO
https://leetcode-cn.com/problems/mini-parser/solution/cpp-8ms-100-zhu-ge-jie-xi-by-zhenying/






*/