#Get N-gram term List of the article
import string
def getNgramTermList(n, records):
    termList = []
    lenOfRecords = len(records)
    for content in records[:lenOfRecords]:
        names = "[\n|.|,|'|?|\"|%|`|(|)|\d|_|!|;|#|\\|/|$|&|*|{|}|-|@|:|，|、|。|（|）]|「|」|！| |？|；|．|：|》|《|○"
        others = "[０|１|２|３|４|５|６|７|８|９|『|』|◆|‧|■|＝|～|－|—|─|…|／|】|【|　|\t|\xa0|＊]"
        exclude = string.digits + string.punctuation + \
            string.ascii_letters + names + others
        charList = [ch for ch in content if ch not in exclude]
        if len(charList) > n-1:
            df = DataFrame([''.join(ch) for ch in [charList[i:i+n]
                                                   for i in range(0, len(charList)-n+1)]])
            bigramSeries = df[0].value_counts()
            newBigram = bigramSeries.to_dict()
            termList.append(newBigram)
    return termList

"""
其实n-gram挺适合学习嵌套列表生成式的

读进一篇文章，将文章中的英文、数字、标点符号都去掉 上面的others、names...其实不需要，看实际需求，而且中文标点符号在string中也有 把每个字都按顺序分别存进一个list中，这里叫charList 将字符按照顺序，按顺序将其拼接成n-gram的模式，例如2 gram的话，就按charList顺序两两组合起来，再存进DataFrame 这里用DataFrame是因为我这里主要计算的是往后的tfidf，所以，你根据自己的需求存

https://zhuanlan.zhihu.com/p/37046249
"""
