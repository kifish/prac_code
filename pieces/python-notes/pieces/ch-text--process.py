#coding=utf-8

import time
import string
import re
import os
import nlpir
import jieba
import jieba.posseg as pseg
from config import Config as conf

class ChPreprocess():
    def __init__(self):
        print('Chinese Preprocess...')
    #解码问题

    def mdcode(self,str):
        for c in ('utf-8', 'gbk', 'gb2312'):
            try:
                return str.decode(c).encode( 'utf-8' )
            except:
                pass
        return 'unknown'
    def FileRead(self,filePath):
        f = open(filePath,'r')
        raw=self.mdcode(f.read())
        return raw
    def NlpirTokener(self,raw):
        nlpir_result=''
        tokens = nlpir.Seg(raw)
        for w in tokens:
#           result+= w[0]+"/"+w[1] #加词性标注
            nlpir_result+= w[0] +' '#加词性标注
        return nlpir_result
    def JiebaTokener(self,raw):
        jieba_result=''
        words = pseg.cut(raw) #进行分词
        jieba_result=""  #记录最终结果的变量
        for w in words:
#            jieba_result+= str(w.word)+"/"+str(w.flag) #加词性标注
             jieba_result += str(w.word)+" " #加词
        return jieba_result
    def StopwordsRm(self,words):
        spr_result=''
        wordList=[word for word in words.split(' ')]
        stopwords = {}.fromkeys([line.rstrip() forline inopen(conf.PreConfig.CHSTOPWORDS)])
        cleanStops= [w for w in wordList if w not in stopwords]
        cleanTokens=[self.CleanEnNum(cs) for cs in cleanStops]
        for c in cleanTokens:
            if c=='。'or  c=='?'or c=='!':
                spr_result+='\n'
                continue
            spr_result+=c+" "
        return spr_result
    def strQ2B(self,ustring):
        """把字符串全角转半角"""
        #http://www.cnblogs.com/kaituorensheng/p/3554571.html
        ustring=ustring.decode('utf-8')
        rstring = ""
        for uchar in ustring:
            inside_code=ord(uchar)
            if inside_code==0x3000:
                inside_code=0x0020
            else:
                inside_code-=0xfee0
            if inside_code<0x0020 or inside_code>0x7e:      #转完之后不是半角字符则返回原来的字符
               rstring+=uchar.encode('utf-8')
            else:
                rstring+=(unichr(inside_code)).encode('utf-8')
        return rstring
    def CleanEnNum(self,raw):
        p=re.compile(r'\w*',re.L)
        clean = p.sub("", raw)
#        r =re.sub("[A-Za-z0-9\[\`\~\!\@\#\$\^\&\*\(\)\=\|\{\}\'\:\;\'\,\[\]\.\<\>\/\?\~\！\@\#\\\&\*\%]", "", s)
        return clean
    def mkdir(self,path):
        # 去除首位空格
        path=path.strip()
        # 去除尾部 \ 符号
        path=path.rstrip("\\")
        # 判断路径是否存在
        # 存在    True
        # 不存在  False
        isExists=os.path.exists(path)
        # 判断结果
        if not isExists:
            # 如果不存在则创建目录
            print(path+' 创建成功')
            # 创建目录操作函数
            os.makedirs(path)
            return True
        else:
            # 如果目录存在则不创建，并提示目录已存在
            print(path+' 目录已存在')
            return False
    def WriteResult(self,result,resultPath):
        self.mkdir(str(resultPath).replace(str(resultPath).split('/')[-1],''))
        f=open(resultPath,"w")  #将结果保存到另一个文档中
        f.write(result)
        f.close()
    def JiebaMain(self,dir):
        for root,dirs,files in os.walk(dir):
            for eachfiles in files:
                croupPath=os.path.join(root,eachfiles)
                print(croupPath)
                resultPath = conf.PreConfig.JIEBARESULTPATH+croupPath.split('/')[-2]+'/'+croupPath.split('/')[-1]
                raw = self.FileRead(croupPath).strip()
                raw = self.strQ2B(raw)
                raw = raw.replace(" ",'')
                words = self.JiebaTokener(raw)
                result = self.StopwordsRm(words)
                self.WriteResult(result,resultPath)
    def NlpirMain(self,dir):
        for root,dirs,files in os.walk(dir):
            for eachfiles in files:
                croupPath=os.path.join(root,eachfiles)
                print croupPath
                resultPath=conf.PreConfig.NLPIRRESULTPATH+croupPath.split('/')[-2]+'/'+croupPath.split('/')[-1]
                raw=self.FileRead(croupPath).strip()
                raw=self.strQ2B(raw)
                raw=raw.replace(" ",'')
                words=self.NlpirTokener(raw)
                result=self.StopwordsRm(words)
                self.WriteResult(result,resultPath)
    def LoadCroupResult(self,filepath):
        raw=chPre.FileRead(filepath)
        result=[t for t in raw.split(' ')]
        for r in result:
            print self.mdcode(r)#打印显示
        return result
    def Test(self):
        chPre=ChPreprocess()
        croupPath='/corpus/mx/6/69.TXT'
        resultPath=conf.PreConfig.NLPIRRESULTPATH+croupPath.split('/')[-2]+'/'+croupPath.split('/')[-1]
#       resultPath=conf.PreConfig.JIEBARESULTPATH+croupPath.split('/')[-2]+'/'+croupPath.split('/')[-1]
        print(resultPath)
        raw=chPre.FileRead(croupPath)
        raw=chPre.strQ2B(raw)
        raw=raw.replace(" ",'')
        words=chPre.NlpirTokener(raw)
#       words=chPre.JiebaTokener(raw)
        result=chPre.StopwordsRm(words)
        print(result)
        chPre.WriteResult(result,resultPath)


chPre=ChPreprocess()
#chPre.JiebaMain(conf.PreConfig.CHCROPPATH)
chPre.NlpirMain(conf.PreConfig.CHCORUPPATH)
