import pandas as pd
dic = {'标识': ['Apple', 'Microsoft', 'Tencent', 'Google', 'Facebook', 'Amazon'],
       '名称': ['苹果', '微软', '腾讯', '谷歌', '脸书', '亚马逊'],
       '市值': [158100, 136800, 45100, 149000, 56219, 124400]}
df = pd.DataFrame(dic)
print(df.sort_values(by='市值', ascending=False))
