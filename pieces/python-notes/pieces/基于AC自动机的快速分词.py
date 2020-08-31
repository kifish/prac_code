import ahocorasick


def load_dic(dicfile):
    from math import log
    dic = ahocorasick.Automaton()
    total = 0.0
    with open(dicfile) as dicfile:
        words = []
        for line in dicfile:
            line = line.split(' ')
            words.append((line[0], int(line[1])))
            total += int(line[1])
    for i, j in words:
        dic.add_word(i, (i, log(j/total)))  # 这里使用了对数概率，防止溢出
    dic.make_automaton()
    return dic


dic = load_dic('me.dic')


def all_cut(sentence):
    words = []
    for i, j in dic.iter(sentence):
        words.append(j[0])
    return words


def max_match_cut(sentence):
    sentence = sentence.decode('utf-8')
    words = ['']
    for i in sentence:  # i相当于一个字, 优先匹配最长词
        i = i.encode('utf-8')
        if dic.match(words[-1] + i):
            words[-1] += i
        else:
            words.append(i)
    return words


#这个实现里记录了所有临时路径,可以考虑动态丢掉一部分
def max_proba_cut(sentence):
    paths = {0: ([], 0)}  # key 表示 setence[:key+1]的最大概率路径的划分
    #[] 顺序存储了词,后面的数字对应概率大小
    end = 0
    for i, j in dic.iter(sentence):
        start, end = 1+i-len(j[0]), i+1
        # #start当前切出的最长匹配词的第一个字在句子中位置的索引,endt当前切出的最长匹配词的最后一个字在句子中位置的索引
        if start not in paths:
            last = max([i for i in paths if i < start])
            paths[start] = (paths[last][0]+[sentence[last:start]],
                            paths[last][1]-10)  # ln(e^(-10)) = -10
        proba = paths[start][1]+j[1]  # 计算该词的概率,用ln把概率相乘转换为相加
        if end not in paths or proba > paths[end][1]:
            # setence[:end+1]的最大概率路径的划分
            paths[end] = (paths[start][0]+[j[0]], proba)
    #若结尾处还有单字(可能有多个单字?)
    #直接补成最后一个词,概率不必再计算了
    if end < len(sentence):
        return paths[end][0] + [sentence[end:]]
    else:
        return paths[end][0]


def min_words_cut(sentence):
    paths = {0: ([], 0)}
    end = 0
    for i, j in dic.iter(sentence):
        start, end = 1+i-len(j[0]), i+1
        if start not in paths:
            last = max([i for i in paths if i < start])
            paths[start] = (
                paths[last][0]+[sentence[last:start]], paths[last][1]+1)
        num = paths[start][1]+1
        if end not in paths or num < paths[end][1]:
            paths[end] = (paths[start][0]+[j[0]], num)
    if end < len(sentence):
        return paths[end][0] + [sentence[end:]]
    else:
        return paths[end][0]



#天然的断句标记的，比如标点符号、换行符.在这些标记之间分词
to_break = ahocorasick.Automaton()
for i in ['，', '。', '！', '、', '？', ' ', '\n']:
    to_break.add_word(i, i)

to_break.make_automaton()


def map_cut(sentence):
    start = 0
    words = []
    for i in to_break.iter(sentence):
        words.extend(max_proba_cut(sentence[start:i[0]+1]))
        start = i[0]+1
    words.extend(max_proba_cut(sentence[start:]))
    return words
