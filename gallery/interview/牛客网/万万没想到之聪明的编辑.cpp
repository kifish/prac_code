#include<bits/stdc++.h>

// c++11(clang++ 3.9)

using namespace std;



// c++ string erase
// http://www.cplusplus.com/reference/string/string/erase/


// https://blog.csdn.net/u010472607/article/details/80431604



/*

https://www.nowcoder.com/test/question/42852fd7045c442192fa89404ab42e92?pid=16516564&tid=34249987


[编程题]万万没想到之聪明的编辑
时间限制：C/C++ 1秒，其他语言2秒

空间限制：C/C++ 32M，其他语言64M

我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：

1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
……
万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……

请听题：请实现大锤的自动校对程序

输入描述:
第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。

后面跟随N行，每行为一个待校验的字符串。

输出描述:
N行，每行包括一个被修复后的字符串。

输入例子1:
2
helloo
wooooooow

输出例子1:
hello
woow





暴力即可。
您的代码已保存
答案正确:恭喜！您提交的程序通过了所有的测试用例



*/

bool check_1(string & s, vector<bool> & deleted, int idx){
    int cnt = 0;
    int same_ch_cnt = 0;
    int tmp_idx = idx;
    for(; tmp_idx >= 0;tmp_idx--){
        if(deleted[tmp_idx]){
            continue;
        } 
        cnt++;
        if(s[tmp_idx] == s[idx]){
            same_ch_cnt++;
        }
        if(cnt >= 3){
            break;
        }
    }
    if(same_ch_cnt == 3){
        return true;
    }
    else return false;

}

bool check_2(string & s, vector<bool> & deleted, int idx){
    if(idx >= 3){
        vector<char> buf;
        int cnt = 0;
        for(;idx >= 0;idx--){
            if(deleted[idx]){
                continue;
            }
            cnt++;
            buf.push_back(s[idx]);
            if(cnt == 4){
                break;
            }
        }
        if(buf.size() == 4){
            if(buf[0] == buf[1] && buf[2] == buf[3] && buf[0] != buf[3]){
                return true;
            }
            else return false;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

string process(string & s){
    vector<bool> deleted(s.size(), false);

    for(int i = 0;i<s.size();i++){
        if(check_1(s, deleted, i)){
            deleted[i] = true;
        }

        if(check_2(s,deleted, i)){
            deleted[i] = true;
        }
    }

    string ret = "";
    for(int i = 0;i<s.size();i++){
        if(!deleted[i]){
            ret += s[i];
        }
    }
    return ret;
}


int main(){
    string ret;
    int case_cnt;
    cin>>case_cnt;
    string line;
    // cout<<case_cnt<<endl;
    cin.get(); // 吸收一个空行
    // https://blog.csdn.net/iamiman/article/details/53468250
    while(case_cnt--){
        // https://blog.csdn.net/MisterLing/article/details/51697098
        // http://www.cplusplus.com/reference/string/string/getline/
        getline(cin, line);
        // cout<<"line :"<<line<<endl;
        ret = process(line);
        cout<<ret<<endl;
        // cout<<"the case ended"<<endl;
    }
}

