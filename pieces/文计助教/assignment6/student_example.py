import requests
myfile = open("1700017834_stockData_SZZS_2017.txt", "w", encoding="utf-8")
data1 = requests.get(
	"http://quotes.money.163.com/trade/lsjysj_zhishu_000001.html?year=2017&season=1")
data1.encoding = "utf-8"
data2 = requests.get(
	"http://quotes.money.163.com/trade/lsjysj_zhishu_000001.html?year=2017&season=2")
data2.encoding = "utf-8"
data3 = requests.get(
	"http://quotes.money.163.com/trade/lsjysj_zhishu_000001.html?year=2017&season=3")
data3.encoding = "utf-8"
data4 = requests.get(
	"http://quotes.money.163.com/trade/lsjysj_zhishu_000001.html?year=2017&season=4")
data4.encoding = "utf-8"

#th是一个表头单元格
ChnStart = data1.text.find(r"<th>")
while(ChnStart != -1):
	ChnEnd = data1.text.find(r"</th>", ChnStart)
	Chn = data1.text[ChnStart+4:ChnEnd]
	print(Chn, end=",", file=myfile)
	ChnStart = data1.text.find(r"<th>", ChnEnd)
print(file=myfile)
#打印第一行汉字
#tr 是一行;td是一个数据单元格
DataStart = data4.text.find(r"<td>")
while(DataStart != -1):
	DataEnd = data4.text.find(r"</td>", DataStart)
	Data = data4.text[DataStart+4:DataEnd]
	# 去掉千分号
	if "," in Data:
		Data = Data.replace(",", "")
	if "<" not in Data and " " not in Data and "\n" not in Data and "" != Data:
		print(Data, end=",", file=myfile)
		output = True
	else:
        output = False
	DataStart = data4.text.find(r"<td>", DataEnd)
    #如果</tr>夹在</td>与<td>之间，说明需要换行。
	if data4.text.find(r"</tr>", DataEnd, DataStart) != -1 and output == True:
		print(file=myfile)  # 换行

DataStart = data3.text.find(r"<td>")
while(DataStart != -1):
	DataEnd = data3.text.find(r"</td>", DataStart)
	Data = data3.text[DataStart+4:DataEnd]
	if "," in Data:
		Data = Data.replace(",", "")
	if "<" not in Data and " " not in Data and "\n" not in Data and "" != Data:
		print(Data, end=",", file=myfile)
		p = True
	else:
		p = False
	DataStart = data3.text.find(r"<td>", DataEnd)
	if data3.text.find(r"</tr>", DataEnd, DataStart) != -1 and p == True:
		print(file=myfile)

DataStart = data2.text.find(r"<td>")
while(DataStart != -1):
	DataEnd = data2.text.find(r"</td>", DataStart)
	Data = data2.text[DataStart+4:DataEnd]
	if "," in Data:
		Data = Data.replace(",", "")
	if "<" not in Data and " " not in Data and "\n" not in Data and "" != Data:
		print(Data, end=",", file=myfile)
		p = True
	else:
		p = False
	DataStart = data2.text.find(r"<td>", DataEnd)
	if data2.text.find(r"</tr>", DataEnd, DataStart) != -1 and p == True:
		print(file=myfile)

DataStart = data1.text.find(r"<td>")
while(DataStart != -1):
	DataEnd = data1.text.find(r"</td>", DataStart)
	Data = data1.text[DataStart+4:DataEnd]
	if "," in Data:
		Data = Data.replace(",", "")
	if "<" not in Data and " " not in Data and "\n" not in Data and "" != Data:
		print(Data, end=",", file=myfile)
		p = True
	else:
		p = False
	DataStart = data1.text.find(r"<td>", DataEnd)
	if data1.text.find(r"</tr>", DataEnd, DataStart) != -1 and p == True:
		print(file=myfile)

myfile.close()
