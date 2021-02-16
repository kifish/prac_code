/*

https://leetcode-cn.com/problems/design-twitter/


系统设计题


这个代码写的很清晰:
https://leetcode-cn.com/problems/design-twitter/solution/she-ji-tui-te-by-leetcode-solution/345258

        struct cmp {
            bool operator()(const Tweet *a, const Tweet *b) {
                return a->time < b->time;
            }
        };

        priority_queue<Tweet*, vector<Tweet*>, cmp> q;



*/