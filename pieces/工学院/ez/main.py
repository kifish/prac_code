import pandas as pd
from functools import reduce
import os
import re
import sys
raw_data_path = sys.argv[1]
field_dict_path = sys.argv[2]

df = pd.DataFrame()
# raw_data_path = 'C:/Users/k/Desktop/dump8000.nozzel'
# raw_data_path = '/Users/k/Documents/prac_code/pieces/工学院/dump8000.nozzel'
with open(raw_data_path, 'r') as f:
    for line in f:
        df = pd.concat(
            [df, pd.DataFrame([tuple(line.strip().split(' '))])], ignore_index=True)


def get_needed_data(df):
    needed_data = []
    cur_unit = []
    for row_idx in range(9, len(df)):
        if len(cur_unit) >= 9:
            needed_data.append(cur_unit.copy())
            cur_unit = []
        cur_unit.append((df.iloc[row_idx][3], df.iloc[row_idx]
                         [4], df.iloc[row_idx][5], df.iloc[row_idx][18]))
    if cur_unit:
        needed_data.append(cur_unit.copy())  # 这里也要写成cur_unit.copy() !
    # print(needed_data)
    return needed_data



# field_dict_path = 'C:/Users/k/Desktop/funkySetFieldsDict'
# field_dict_path = '/Users/k/Documents/prac_code/pieces/工学院/funkySetFieldsDict'
with open(field_dict_path, 'r') as f:
    raw_str = f.read()
text_head = raw_str[:788]

root_path = os.path.split(field_dict_path)[0]


def read_head(head, root_path='.'):
    path = ''
    if head == 'a':
        path = os.path.join(root_path, 'head1.txt')
    elif head == 'p':
        path = os.path.join(root_path, 'head2.txt')

    if path:
        with open(path) as f:
            head = f.read()
        return head
    else:
        return None


def get_field_name(s):
    field_name = s.strip().split()[1]
    if 'alpha' in field_name:
        return 'alphawater'
    elif 'p' == field_name[0]:
        return 'pp'
    return None

#追求效率的话，可以用正则得到关键位置的idx，然后替换，每替换一次都要重新计算关键位置idx


def fill_condition_str(unit):
    res = 'condition ' + '\n'
    for idx, item in enumerate(unit):
        s = 'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}'.format(*item)
        if idx == 0:
            res += s
        else:
            res += '||' + s
    res += ';'
    return res


def gen_str(data, head):
    res = ''
    res += head + '\n' + '\n'
    idx = 1
    for unit in data:
        if len(unit) == 9:
            unit_data_list = list(reduce(lambda x, y: x+y, unit))
            condition_str = (
                'condition '
                '"pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}||'
                'pow(pow(pos().x-{},2)+pow(pos().y-{},2)+pow(pos().z-{},2),0.5)<={}";'
            ).format(*unit_data_list)
        else:
            condition_str = fill_condition_str(unit)
        field_name = get_field_name(
            re.match(r'.*(field.*?;).*(expression.*?;).*', head, re.S).group(1))
        unit_str = re.sub(r'.*(condition.*?;).*', condition_str, head, re.S)
        unit_str = re.sub(r'.*(%s).*' % (field_name),
                          field_name+str(idx), unit_str, re.S)
        res += unit_str
        idx += 1
    return res


text_body_head = 'expressions\n(\n'
text_body_tail = ');'
text_body_main = gen_str(get_needed_data(df), read_head('a', root_path))
text = text_head + text_body_head + text_body_main + text_body_tail
save_path = os.path.join(root_path, 'NewfunkySetFieldsDict2')
with open(save_path, 'w', encoding='utf8') as f:
    f.write(text)
