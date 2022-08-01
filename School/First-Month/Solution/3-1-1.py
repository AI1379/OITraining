import pandas as pd
dic = {'标识': ['Apple', 'Microsoft', 'Tencent'],
       '名称': ['苹果', '微软', '腾讯'],
       '市值': [158100, 136800, 45100]}
df = pd.DataFrame(dic)
# DataFrame.append方法已经被pandas官方弃用 将会在未来移除 pandas官方给的替代方案是concat
# df = df.append({'标识': 'Alibaba', '名称': '阿里巴巴', '市值': 26667}, ignore_index=True)
df = pd.concat(
    [df, pd.DataFrame({'标识': 'Alibaba', '名称': '阿里巴巴', '市值': 26667}, index=[3])])
df.insert(1, '成立时间', [1976, 1975, 1998, 1999])
print(df)
