#coding=utf-8
import nltk
# import enchant
import string
import re
import os
from config import Config as conf
from nltk.corpus import wordnet as wn

'''
python3 已经不需要这三行代码
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
'''
class EnPreprocess():
    '''
    整体流程：
    读取文件：fileRead（）filepath to raw
    分割成句子:SenToken()raw to sents
    (词性标注):POSTagger()sent to words[] #待完善
    句子分割成词:TokenToWords()将句子分割成词 sent to word[]
    （拼写检查）：WordCheck() 错误的去掉或是等人工改正
    去掉标点，去掉非字母内容:CleanLines()句子，line to cleanLine
    去掉长度小于3的词，小写转换，去停用词：CleanWords(),words[] to cleanWords[]
    词干化:StemWords()把词词干化返回，words to stemWords
    二次清理:再执行一次CleanWords()，使句子更加纯净
    '''
    def __init__(self):
        print('English token and stopwords remove...')
    def fileRead(self,filePath):#读取内容
        f = open(filePath)
        raw = f.read()
        return raw
    def WriteResult(self,result,resultPath):
       self.mkdir(str(resultPath).replace(str(resultPath).split('/')[-1],''))
       f=open(resultPath,"w") #将结果保存到另一个文档中
       f.write(str(result))
        f.close()
    def SenToken(self,raw):#分割成句子
        sent_tokenizer=nltk.data.load('tokenizers/punkt/english.pickle')
        sents =sent_tokenizer.tokenize(raw)
        return sents
    def POSTagger(self,sents): #这里的参数sent应该为sents
        taggedLine=[nltk.pos_tag(sent) for sent in sents]
        return taggedLine
    def WordTokener(self,sent):#将单句字符串分割成词
        wordsInStr= nltk.word_tokenize(sent)
        returnwordsInStr
    def WordCheck(self,words):#拼写检查 #该函数未经测试
        d =enchant.Dict("en_US")
        checkedWords=()
        for word in words:
            if not d.check(word):
               d.suggest(word)
               word=raw_input()
            checkedWords = (checkedWords,'05')
        return checkedWords
    def CleanLines(self,line):
        identify =string.maketrans('', '')
        del_pun_digits =string.punctuation + string.digits #ASCII 标点符号，数字
#       cleanLine= line.translate(identify, del_pun_digits) #去掉ASCII 标点符号和空格 (注释的这一行似乎没法去空格)
        cleanLine =line.translate(identify,del_pun_digits) #去掉ASCII 标点符号
        return cleanLine
    def CleanWords(self,wordsInStr):#去掉标点符号，长度小于3的词以及non-alpha词，小写化
        cleanWords=[]
        stopwords ={}.fromkeys([ line.rstrip() for line in open(conf.PreConfig.ENSTOPWORDS)])
        for words in wordsInStr: #words相当于一句话
           cleanWords+= [[w.lower() for w in words if w.lower() not in stopwords and 3<=len(w)]]
        return cleanWords
    def StemWords(self,cleanWordsList):
        stemWords=[]
        #porter =nltk.PorterStemmer()#有人说这个词干化工具效果不好，不是很专业
        #result=[porter.stem(t) for t in cleanTokens]
        for words in cleanWordsList:
           stemWords += [[wn.morphy(w) for w in words]]
        return stemWords
    def WordsToStr(self,stemWords):
        strLine=[]
        for words in stemWords: #stemWords相当于处理过后的文本内容，words相当于一句话
           strLine += [w for w in words] #文本内容变为一个list
        return strLine

    def my_mkdir(self,path):
        # 去除首位空格
        path = path.strip()
        # 去除尾部 \ 符号
        path = path.rstrip("\\")
        # 判断路径是否存在
        # 存在    True
        # 不存在  False
        isExists = os.path.exists(path)
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
    def EnPreMain(self,dir):
        for root,dirs,files in os.walk(dir):
            for filename in files:
                croupPath=os.path.join(root,filename)
                print(croupPath)
                resultPath=conf.PreConfig.NLTKRESULTPATH+croupPath.split('/')[-2]+'/'+croupPath.split('/')[-1]
                raw=self.fileRead(croupPath).strip()
                sents=self.SenToken(raw)
#               taggedLine=self.POSTagger(sents)#暂不启用词性标注
                cleanLines=[self.CleanLines(line) for line in sents]
                words=[self.WordTokener(cl) for cl in cleanLines]
#               checkedWords=self.WordCheck(words)#暂不启用拼写检查
                cleanWords=self.CleanWords(words)
                stemWords=self.StemWords(cleanWords)
#               cleanWords=self.CleanWords(stemWords)#第二次清理出现问题，暂不启用
                strLine=self.WordsToStr(stemWords)
                self.WriteResult(strLine,resultPath)#一个文件暂时存成一行
    def StandardTokener(self,raw):
        result=''
        #to be continued
        return result


enPre=EnPreprocess()
enPre.EnPreMain(conf.PreConfig.ENCORUPPATH)
