import numpy as np
class Apriori:
    """
    usage:
    sorted_by:0,1,2
    0,按support排序
    1,按confidence排序
    2,按lift排序
    input: transactions
    return: rules (dict)
    """
    def __init__(self,min_support,min_confidence,max_length = 10000000):
        self.min_support = min_support # 最小支持度
        self.min_confidence = min_confidence # 最小置信度
        self.max_length = max_length # 频繁项的最大长度
    
    def count(self,filename):
        self.total = 0 # 数据总行数
        item2num = {} #物品集合

        #统计得到物品清单
        with open(filename,encoding='utf8') as f:
            for line in f:
                self.total += 1
                for item in line.strip().split(','):
                    if item in item2num:
                        item2num[item] += 1
                    else:
                        item2num[item] = 1

        self.item2ratio = {item: num/self.total for item,num in item2num.items() if num/self.total > self.min_support}
        self.item2id = {item: idx for idx,item in enumerate(self.item2ratio)}

        #初始化物品清单的0-1矩阵
        # transaction
        self.D = np.zeros((self.total, len(item2num)),dtype = bool)
        #个人认为初始化成0,1而不是bool可能更好，因为python中的bool不像C语言中的bool那样(几乎和01等价)
        
        #得到物品清单的0-1矩阵
        with open(filename,encoding = 'utf8') as f:
            for idx,line in enumerate(f):
                for item in line.strip().split(','):
                    if item in self.item2ratio:
                        self.D[idx,self.item2id[item]] = True 

    def format_rules(self,rules):
        import collections
        res = collections.OrderedDict()
        for k,v in rules:
            new_k = ','.join(list(k[:-1])) + '->' + str(k[-1])
            new_v = 'lift: ' + str(v[2]) + 'confidence: '+str(v[1])[:5] + ' ' + 'support: ' + str(v[0])[:5]
            res[new_k] = new_v
        return res

    def find_rules(self,filename = 'data.txt',format = True, raw = False,sorted_by = 1):
        self.count(filename)
        rules = [{ (item,):ratio for item,ratio in self.item2ratio.items() }]
        cur_item_num = 0 # 当前步的频繁项的物品数

        while rules[-1] and cur_item_num + 2 <= self.max_length:  # 包含了从k频繁项到k+1频繁项的构建过程
            rules.append({}) # 给k+1频繁项 初始化
            freq_itemsets = sorted(rules[-2].keys())  # 对每个k频繁项按字典序排序（核心）感觉未必要字典序,只需要排序即可
            # 这样的排序通过递推,实现了freq_itemset内的item是有序的,且freq_itemsets也是有序的
            pre_freq_itemset_num = len(rules[-2]) # k频繁项的数量
            cur_item_num += 1 # k
            for idx in range(pre_freq_itemset_num):
                for idx2 in range(idx+1, pre_freq_itemset_num):
                    # cur_item_num-1即k-1
                    # 如果前面k-1个item相同，那么这两个k频繁项就可以组合成一个k+1频繁项
                    if freq_itemsets[idx][:cur_item_num-1] == freq_itemsets[idx2][:cur_item_num-1]:
                        # freq_itemsets[idx]:一个tuple
                        # cur_freq_itemset: k+1 频繁项,包含了k+1个不同的item
                        cur_freq_itemset = freq_itemsets[idx] + (freq_itemsets[idx2][cur_item_num-1],)
                        # 拼接成k+1 频繁项
                        # 实际上freq_itemsets[idx]并上freq_itemsets[idx2] 共有k+1个不同的item
                        cur_freq_itemset_id = [self.item2id[item] for item in cur_freq_itemset]
                        # sum(np.prod(self.D[:, cur_freq_itemset_id], 1)) k+1频繁项在数据集中的共现次数
                        support = 1.0 * sum(np.prod(self.D[:, cur_freq_itemset_id],1)) / self.total
                        if support > self.min_support: #判断是否足够频繁 
                            rules[-1][cur_freq_itemset] = support
                        
        # 遍历每一个频繁项，计算置信度
        # 也可以认为是剪枝
        result = {}
        for k, freq_itemset_pair in enumerate(rules[1:]): # 项数大于等于2
            for freq_itemset, support in freq_itemset_pair.items():#对于当前的k,遍历所有k频繁项
                for i, _ in enumerate(freq_itemset):
                    #遍历所有的组合，即(a,b,c)究竟是 a,b -> c 还是 a,c -> b 还是 b,c -> a ？
                    exclude_ith_item = freq_itemset[:i] + freq_itemset[i+1:] # 把第i项剔除
                    confidence = support / rules[k][exclude_ith_item] # 不同组合的置信度(一种排列对于一条规则)
                    if confidence > self.min_confidence:
                        result[exclude_ith_item + (freq_itemset[i],)] = (support,confidence)
                        #例如：
                        #exclude_ith_item + ith_item :a,b,c
                        #exclude_ith_item:a,b
                        #P(a,b,c) = P(a,b)*P(c|a,b)
                        #P(c|a,b) = P(a,b,c)/P(a,b) = support / rules[k][exclude_ith_item]

        # 计算lift
        for k,v in result.items():
            set_a = k[:-1]
            set_b = [k[-1]]
            set_a_id = [self.item2id[item] for item in set_a]
            set_b_id = [self.item2id[set_b[0]]]
            intersection = set_a_id + set_b_id
            lift = sum(np.prod(self.D[:, intersection], 1)) / (sum(np.prod(self.D[:, set_a_id], 1)) * sum(np.prod(self.D[:, set_b_id], 1)))
            result[k] = v + (lift,)


        if raw:
            return result

        #返回格式化或排序后的结果
        idx = sorted_by
        result_list = sorted(result.items(),key = lambda x:-x[1][idx]) #默认按置信度confidence降序排列,list
        if format:
            return self.format_rules(result_list)
        else:
            import collections
            sorted_result = collections.OrderedDict()
            for rule in result_list:
                sorted_result[rule[0]] = rule[1]
            return sorted_result



if __name__ == '__main__':
    from pprint import pprint
    model = Apriori(0.06, 0.75)
    # pprint(list(model.find_rules('data.txt').items())[:20])
    # print('----------')
    # pprint(list(model.find_rules('data.txt', raw = True).items())[:20])
    # print('----------')
    # pprint(list(model.find_rules('data.txt', format=False).items())[:20])
    # print('----------')
    pprint(list(model.find_rules('data.txt', format=False,sorted_by= 2).items())[:20])
    # print('----------')
    # model = Apriori(0.06, 0.75,3)
    # pprint(list(model.find_rules('data.txt').items())[:20])


