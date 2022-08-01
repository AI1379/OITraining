import pandas as pd
dic = {'标识': ['Apple', 'Microsoft', 'Tencent'],
       '名称': ['苹果', '微软', '腾讯'],
       '市值': [158100, 136800, 45100]}
df = pd.DataFrame(dic)
df = pd.concat(
    [df, pd.DataFrame({'标识': 'Alibaba', '名称': '阿里巴巴', '市值': 26667}, index=[3])])
df.insert(1, '成立时间', [1976, 1975, 1998, 1999])

s = input()
while s != '结束':
    print(df[df['名称'] == s]['市值'])
    s = input()
