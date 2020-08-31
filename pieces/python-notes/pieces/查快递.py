import json,requests
def search_package():
    #输入运单号码，只有正在途中的快递才可以查到！
    package_num = input('请输入运单号码: ')
    url1 = 'http://www.kuaidi100.com/autonumber/autoComNum?resultv2=1&text=' + package_num
    #查询运单号对应的快递公司，如中通，返回zhongtong
    company_name = json.loads(requests.get(url1).text)['auto'][0]['comCode']



    url2 = 'http://www.kuaidi100.com/query?type=' + company_name + '&postid=' + package_num
    #还有个temp字段加不加都可以。如：'&temp=0.9829438147420106'
    #查询运单号和快递公司得到快递详情，返回json文件，用dict保存在resultdict中

    print('时间↓                             地点和跟踪进度↓\n')
    for item in json.loads(requests.get(url2).text)['data']:
        print(item['time'],item['context'])

search_package()

#pyinstaller -F search_package.py
#打包成exe
