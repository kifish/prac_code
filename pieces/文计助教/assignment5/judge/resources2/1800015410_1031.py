

def isChinese(ch):
    if 0x4e00 <= ord(ch) < 0x9fa6:
        return True
    return False

hFile=open('红楼梦.txt','r',encoding='utf-8')
hContent=hFile.read()
hFile.close()
sFile=open('水浒传.txt','r',encoding='utf-8')
sContent=sFile.read()
sFile.close()


hStr=''.join([x for x in hContent if isChinese(x)])
sStr=''.join([x for x in sContent if isChinese(x)])

hCount=len(hStr)
sCount=len(sStr)
hSet=set(hStr)
sSet=set(sStr)
hDict={}
sDict={}

Result2=open('2.txt','w',encoding='utf-8')
hAvg={}
sAvg={}
for i in range(0,hCount):
    if hStr[i] in hDict:
        hDict[hStr[i]]+=1
    else:
        hDict[hStr[i]]=1
for h in hDict:
    hAvg[h]=round(hDict[h]/hCount,8)
for i in range(0,sCount):
    if sStr[i] in sDict:
        sDict[sStr[i]]+=1
    else:
        sDict[sStr[i]]=1
for s in sDict:
    sAvg[s]=round(sDict[s]/sCount,8)
hList=list(hAvg.items())
sList=list(sAvg.items())
hList.sort(key=lambda x:x[1],reverse=True)
sList.sort(key=lambda x:x[1],reverse=True)
for i in hList[:500]:
    print(i[0],i[1],sep=',',file=Result2)
for i in sList[:500]:
    print(i[0],i[1],sep=',',file=Result2)
Result2.close()

Result3=open('3.txt','w',encoding='utf-8')
hSet=set(hStr)
sSet=set(sStr)
hOnlySet=hSet-(hSet & sSet)
sOnlySet=sSet-(hSet & sSet)
print(len(hSet),len(sSet),len(hOnlySet),len(sOnlySet),sep=',',file=Result3)
Result3.close()

Result4=open('4.txt','w',encoding='utf-8')
hOnlyDict={}
sOnlyDict={}
for i in range(0,hCount):
    if hStr[i] in hOnlySet:
        if hStr[i] in hOnlyDict:
            hOnlyDict[hStr[i]]+=1
        else:
            hOnlyDict[hStr[i]]=1
for i in range(0,sCount):
    if sStr[i] in sOnlySet:
        if sStr[i] in sOnlyDict:
            sOnlyDict[sStr[i]]+=1
        else:
            sOnlyDict[sStr[i]]=1
hOnlyList=list(hOnlyDict.items())
sOnlyList=list(sOnlyDict.items())
hOnlyList.sort(key=lambda x:x[1],reverse=True)
sOnlyList.sort(key=lambda x:x[1],reverse=True)
for i in hOnlyList[:len(hOnlyList)-1]:
    print(i[0],end=',',file=Result4)
for i in hOnlyList[len(hOnlyList)-1:len(hOnlyList)]:
    print(i[0],file=Result4)
for i in sOnlyList[:len(sOnlyList)-1]:
    print(i[0],end=',',file=Result4)
for i in sOnlyList[len(sOnlyList)-1:len(sOnlyList)]:
    print(i[0],file=Result4)
Result4.close()

Result5=open('5.txt','w',encoding='utf-8')
minusDict={}
for i in hSet & sSet:
    minusDict[i]=hDict[i]-sDict[i]
    if minusDict[i]<0:
        minusDict[i]=-minusDict[i]
minusList=list(minusDict.items())
minusList.sort(key=lambda x:x[1],reverse=True)
for i in minusList[:499]:
    print(i[0],end=',',file=Result5)
for i in minusList[499:500]:
    print(i[0],file=Result5)
Result5.close()






# aFile = open("红楼梦.txt", "r", encoding="utf-8", errors="ignore")
# bFile = open("水浒传.txt", "r", encoding="utf-8", errors="ignore")
# aWritingFile = open("2.txt", "w")
# bWritingFile = open("3.txt", "w")
# cWritingFile = open("4.txt", "w")
# dWritingFile = open("5.txt", "w")
#
# # 第一问
# aList = aFile.read()
#
#
# def isChinese(ch):
#     if 0x4e00 <= ord(ch) < 0x9fa6:
#         return True
#     return False
#
#
# strA = "".join([x for x in aList if isChinese(x)])
#
# bList = bFile.read()
#
#
# def isChinese(ch):
#     if 0x4e00 <= ord(ch) < 0x9fa6:
#         return True
#     return False
#
#
# strB = "".join([x for x in bList if isChinese(x)])
#
# # 第二问
# aDict = {}
# for i in strA:
#     if i in aDict:
#         aDict[i] += 1
#     else:
#         aDict[i] = 1
# for i in aDict:
#     aDict[i] = round(aDict[i] / len(strA), 8)
# sortedADict = sorted(aDict.items(), key=lambda x: x[1], reverse=True)
# for i in range(0, 500):
#     print(sortedADict[i][0], ",", sortedADict[i][1], sep="", file=aWritingFile)
#
# bDict = {}
# for i in strB:
#     if i in bDict:
#         bDict[i] += 1
#     else:
#         bDict[i] = 1
# for i in bDict:
#     bDict[i] = round(bDict[i] / len(strB), 8)
# sortedBDict = sorted(bDict.items(), key=lambda x: x[1], reverse=True)
# for i in range(0, 500):
#     print(sortedBDict[i][0], ",", sortedBDict[i][1], sep="", file=aWritingFile)
#
# # 第三问
# onlyA = 0
# onlyB = 0
# for i in aDict:
#     if i not in bDict:
#         onlyA += 1
# for j in bDict:
#     if j not in aDict:
#         onlyB += 1
# print(len(aDict), len(bDict), onlyA, onlyB, sep=",", file=bWritingFile)
#
# # 第四问
# sortedADict = dict(sortedADict)
# sortedBDict = dict(sortedBDict)
# for i in sortedADict.keys():
#     if i not in sortedBDict.keys():
#         if i == "祧":
#             print(i, end="", file=cWritingFile)
#         else:
#             print(i, end=",", file=cWritingFile)
# print("", file=cWritingFile)
# for j in sortedBDict.keys():
#     if j not in sortedADict.keys():
#         if j == "桅":
#             print(j, end="", file=cWritingFile)
#         else:
#             print(j, end=",", file=cWritingFile)
#
# # 第五题
# juedui = 0
# jueduiList = []
# for i in aDict.keys():
#     if i in bDict.keys():
#         juedui = aDict[i] - bDict[i]
#         if juedui < 0:
#             juedui = -juedui
#         jueduiList.append((i, juedui))
# jueduiList = dict(jueduiList)
# jueduiList = sorted(jueduiList.items(), key=lambda x: x[1], reverse=True)
# for i in range(0, 500):
#     if jueduiList[i][0] == "疼":
#         print("疼", file=dWritingFile)
#     else:
#         print(jueduiList[i][0], end=",", file=dWritingFile)
#
# aFile.close()
# bFile.close()
# aWritingFile.close()
# bWritingFile.close()
# cWritingFile.close()
# dWritingFile.close()

# # 1.清除非汉字
# afile = open("红楼梦.txt", "r", encoding="utf-8")
# aContent = afile.read()
# afile.close()
#
# bfile = open("水浒传.txt", "r", encoding="utf-8")
# bContent = bfile.read()
# bfile.close()
#
#
# def isChinese(ch):
#     if 0x4e00 <= ord(ch) < 0x9fa6:
#         return True
#     return False
#
#
# hongLouContent = "".join([x for x in aContent if isChinese(x)])
# shuiHuContent = "".join([x for x in bContent if isChinese(x)])
#
# # 2.计算汉字的出现频率
# hongLouDict = {}
# hongLouFreDict = {}
# hongLouLength = len(hongLouContent)
# hl = 0
# for ch in hongLouContent:
#     if ch in hongLouDict:
#         hongLouDict[ch] += 1
#     else:
#         hongLouDict[ch] = 1
#         hl += 1
#
# for ch in hongLouDict.keys():
#     hongLouFreDict[ch] = round(hongLouDict[ch] / hongLouLength, 8)
# hongLouFreList = sorted(hongLouFreDict.items(), key=lambda x: x[1], reverse=True)
#
# shuiHuDict = {}
# shuiHuFreDict = {}
# shuiHuLength = len(shuiHuContent)
# sh = 0
# for ch in shuiHuContent:
#     if ch in shuiHuDict:
#         shuiHuDict[ch] += 1
#     else:
#         shuiHuDict[ch] = 1
#         sh += 1
#
# for ch in shuiHuDict.keys():
#     shuiHuFreDict[ch] = round(shuiHuDict[ch] / shuiHuLength, 8)
# shuiHuFreList = sorted(shuiHuFreDict.items(), key=lambda x: x[1], reverse=True)
#
# x2file = open("2.txt", "w", encoding="utf-8")
# for i in range(0, 500):
#     print(hongLouFreList[i][0], hongLouFreList[i][1], sep=",", file=x2file)
# for i in range(0, 500):
#     print(shuiHuFreList[i][0], shuiHuFreList[i][1], sep=",", file=x2file)
# x2file.close()
#
#
#
# # 3.统计只出现在水浒传或红楼梦里的字数
# h = 0
# hongLouOnlyDict = {}
# for ch in hongLouDict.keys():
#     if ch not in shuiHuDict.keys():
#         h += 1
#         hongLouOnlyDict[ch] = hongLouDict[ch]
# s = 0
# shuiHuOnlyDict = {}
# for ch in shuiHuDict.keys():
#     if ch not in hongLouDict.keys():
#         s += 1
#         shuiHuOnlyDict[ch] = shuiHuDict[ch]
#
# x3file = open("3.txt", "w", encoding="utf-8")
# print(hl, sh, h, s, sep=",", file=x3file)
# x3file.close()
#
#
# # 4.输出只出现在水浒传或红楼梦里的汉字
# hongLouOnlyList = sorted(hongLouOnlyDict.items(), key=lambda x: x[1], reverse=True)
# shuiHuOnlyList = sorted(shuiHuOnlyDict.items(), key=lambda x: x[1], reverse=True)
#
# x4file = open("4.txt", "w", encoding="utf-8")
# for i in range(0, h - 1):
#     print(hongLouOnlyList[i][0], ",", end="", sep="", file=x4file)
# print(hongLouOnlyList[h - 1][0], file=x4file)
# for i in range(0, s - 1):
#     print(shuiHuOnlyList[i][0], ",", end="", sep="", file=x4file)
# print(shuiHuOnlyList[s - 1][0], file=x4file)
# x4file.close()
#
#
#
# # 5.
# deltaDict = {}
# for ch in shuiHuDict.keys():
#     if ch in hongLouDict.keys():
#         deltaDict[ch] = abs(hongLouFreDict[ch] - shuiHuFreDict[ch])
# deltaList = sorted(deltaDict.items(), key=lambda x: x[1], reverse=True)
#
# x5file = open("5.txt", "w", encoding="utf-8")
# for i in range(0, 499):
#     print(deltaList[i][0], ",", end="", sep="", file=x5file)
# print(deltaList[500][0], file=x5file)
# x5file.close()
#
