import requests  # requests是第三方库，使用前请安装

r = requests.get('http://www.pku.edu.cn')  # 取得http://www.pku.edu.cn网址的内容
r.encoding = "utf-8"  # 设置网页编码，此处一般为utf-8

print(r.text[0:])  # 输出网页文本，r.text结果为字符串
print("===========")

aPosition_Start = r.text.find(r"<a ")
while (aPosition_Start != -1):
    aPosition_End = r.text.find(r"</a>", aPosition_Start)
    FindLink = r.text[aPosition_Start:aPosition_End + 4].replace("\n", "")
    aText = FindLink[FindLink.find(r">") + 1:-4].strip()
    if "<" not in aText and len(aText) > 0:
        print(aText)
    aPosition_Start = r.text.find(r"<a ", aPosition_End + 4)

print("==============")

webFile = open("pku.html", "w", encoding="utf-8")
webFile.write(r.text)
webFile.close()

# eof
