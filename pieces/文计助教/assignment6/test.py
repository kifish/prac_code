from bs4 import BeautifulSoup
import requests
res = requests.get('http://news.sina.com.cn/hotnews/20181030.shtml')
# 注意2018年的网页加了反爬措施，不太好爬。
# 2008年的网页没有反爬措施

res.encoding = "utf-8"
htmlCode = res.text
oBS = BeautifulSoup(htmlCode,"html.parser")
# print(oBS.prettify())
tags = oBS.find_all(['th'])
idx = 0
d = {}
for tag in tags:
    if '媒体' in tag.get_text():
        table_tag = tag.find_parent().find_parent()
        tmp = table_tag.find_all('a')
        if(len(tmp)):
            d[idx] = tmp
            idx += 1
print(len(d))
for k,v in d.items():
    print()
    print('-------------------------------------------------------')
    print(k)
    print(v)
    print('-------------------------------------------------------')
    print()

# 图片排行
tags = oBS.find_all(['h2'])
idx = 0
d = {}
for tag in tags:
    if '图片排行' in tag.get_text():
        print(tag.find_parent().find_parent())



# print(oBS.select('title'))
# print(oBS.select("#4"))
# view-source:http://news.sina.com.cn/hotnews/20181030.shtml#5
# 井号之后是页面内定位用的，指向页面内的锚点（一个有名称的 a 标签）
# <a name=5></a>



# https://stackoverflow.com/questions/31958637/beautifulsoup-search-by-text-inside-a-tag

# https://www.cnblogs.com/kongzhagen/p/6472746.html
# https://blog.csdn.net/Winterto1990/article/details/47808949
