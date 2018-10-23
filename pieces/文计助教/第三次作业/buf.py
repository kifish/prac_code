rfile=open("/Users/k/Documents/prac_code/pieces/文计助教/第三次作业/20181017作业/50W.txt","r",encoding="utf-8")#打开50W.text文件，r代表动作，encoding代表输出格式
fileContent=rfile.read()
rfile.close()

listA=fileContent.split()
chnCount=len(listA)
dictXing={}
for i in range(0,chnCount):
    tmp=listA[i]
    xing=tmp[0]
    if xing in dictXing:
        dictXing[xing]+=1
    else:
        dictXing[xing]=1
listB=list(dictXing.items())
listB.sort(key=lambda x:x[1],reverse=True)
#lambda是一个匿名函数，实际效果就是def一个函数