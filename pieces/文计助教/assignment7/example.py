import requests
from bs4 import BeautifulSoup

PictureDict = {}
MediaDict = {}
CharacterDict = {}
DeletePicture = set({'http://i3.sinaimg.cn/ty/cr/2008/0625/1647091190.gif', 'http://i1.sinaimg.cn/IT/images/2006-02-07/U1418P2T78D6083F3304DT20060207135619.gif', 'http://i0.sinaimg.cn/IT/cr/2008/1021/2235718743.jpg', 'http://i0.sinaimg.cn/home/c.gif', 'http://i0.sinaimg.cn/ent/deco/2009/0507/entphone.gif',
                     'http://i2.sinaimg.cn/dy/pc/2007-05-29/27/U48P1T27D2815F1264DT20070529161951.gif', 'http://i2.sinaimg.cn/IT/cr/2008/1021/1321256192.jpg', 'http://i2.sinaimg.cn/IT/cr/2008/1028/2690402909.jpg', 'http://i1.sinaimg.cn/dy/pc/2007-05-29/27/U48P1T27D2815F1264DT20070529161951.gif', 'http://i3.sinaimg.cn/IT/cr/2008/1021/2690402909.jpg'})  # 图标、广告，是从重复出现过的图里手动挑的orz
Weird = []  # 特殊模块，缺少正文标识等
'''test=set({})'''  # 手动找图标用

dataFile = open('news20081001-20081031.txt', 'w', encoding='utf-8')

#去掉html元素的函数


def content(text):
    flag = 1
    result = ""
    for i in text:
        if i == "<":
            flag = 0
        elif i == ">":
            i = ""
            flag = 1
        if flag == 1:
            result = result+i
    return result

#爬虫函数


def get(date):
    #进入排行
    url = "http://news.sina.com.cn/hotnews/{}.shtml".format(date)
    url_doc = requests.get(url).content
    html = BeautifulSoup(url_doc, "html.parser", from_encoding="gbk")
    links = set({})
    #分类爬取
    for i in range(2, 9):
        news = html.find("div", id="Con"+str(i)+"1")
        link_part = news.find_all("td", class_="ConsTi")
        for i in link_part:
            link = i.a.get("href")
            links.add(link)

    #统计
    PictureList = []
    NumCharacters = 0
    for link in links:
        Content = requests.get(link).content
        html = BeautifulSoup(Content, "html.parser", from_encoding="gbk")
        body = html.find(id='artibody')  # 正文
        if body != None:
            #统计图片
            imgs = body.find_all('img')
            for i in imgs:
                picture = i.get("src")  # 图片地址
                '''if picture in PictureList:
                    test.add(picture)
                PictureList.append(picture)'''  # 手动找图标用
                if not picture in DeletePicture:
                    PictureList.append(picture)
            #统计媒体
            media = html.find(id="media_name")
            media = media.text
            medianame = content(media)
            medianame = (' '+medianame+' ').strip()  # 去掉(我也不知道从哪来的)空格
            if medianame in MediaDict:
                MediaDict[medianame] += 1
            else:
                MediaDict[medianame] = 1
            #统计字数
            #去掉诡异的代码等
            while body.find('script') != None:
                body.find('script').decompose()
            while body.find(type=True) != None:
                body.find(type=True).decompose()
            while body.find('style') != None:
                body.find('style').decompose()
            body = body.text.replace('\u3000', '').replace('\n', '').lstrip()
            NumCharacters += len(body)
            #打出内容
            title = html.find(id="artibodyTitle")
            title = title.text
            title = content(title)
            time = html.find(id="pub_date")
            time = time.text
            time = content(time)
            print(title, time, medianame, body, file=dataFile)
        else:
            Weird.append(link)  # 爬不出来的
    PictureDict[date] = len(PictureList)
    CharacterDict[date] = NumCharacters


for i in range(20081001, 20081032):
    get(i)
print("图片:", PictureDict)
print()
print("媒体:", MediaDict)
print()
print("字数:", CharacterDict)
print()
print('爬不出来:', Weird)
print()
'''print(test)'''

dataFile.close()
