class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.size();
		string res = "";
        vector<vector<bool>> is_pal(n,vector<bool>(n,false));
		for(int start = 0;start<s.size();start++){
			is_pal[start][start] = true;
			if(res.size() == 0) res = s[start];

			if(start +1 < (int)s.size()){
				if(s[start] == s[start + 1]) {
					is_pal[start][start + 1] = true;
					if(res.size() < 2){
						res = s[start];
						res += s[start+1];
					} 
				}
			}
		}
		for(int len = 3;len<=n;len++){
			for(int start=0;start<s.size();start++){
				if(start + len -1 < s.size()){
					if(is_pal[start+1][start+len-2] && s[start] == s[start + len -1]){
						is_pal[start][start+len-1] = true;
						if(len > res.size()) res = s.substr(start,len);
					}
				}
			}
		}
		return res;
    }
};




/*

一文让你彻底明白马拉车算法 - windliang的文章 - 知乎
https://zhuanlan.zhihu.com/p/70532099


(R-1) - (L+1) + 1

= R - L - 1


*/
