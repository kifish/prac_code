
--python--爬虫--0
```py
import requests

proxies = {
    "http" : "http://122.114.31.177:808",
    "https" : "http://119.164.20.193:8118",
}

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) \
                    AppleWebKit/537.36 (KHTML, like Gecko) \
                   Chrome/58.0.3029.110 Safari/537.36'}


url = "http://daily.zhihu.com/"
res = requests.get(url,headers = headers,proxies = proxies).text

#print(len(res))
print(res)

```