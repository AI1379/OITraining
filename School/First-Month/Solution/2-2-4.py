import pandas as pd
dic = {'标识': ['Apple', 'Microsoft', 'Tencent', 'Google', 'Facebook', 'Amazon'],
       '名称': ['苹果', '微软', '腾讯', '谷歌', '脸书', '亚马逊'],
       '市值': [158100, 136800, 45100, 149000, 56219, 124400]}
df = pd.DataFrame(dic)
# 注意pandas.DataFrame.loc是闭区间，而非python原生list的左闭右开区间
# sort_values ignore_index=True后会重新分配每一行的index 默认值是False
print(df['市值'].sort_values(ignore_index=True).loc[1:df['市值'].count()-2].mean())
# 另一种写法
# print((df['市值'].sum()-df['市值'].max()-df['市值'].min())/(df['市值'].count()-2))
