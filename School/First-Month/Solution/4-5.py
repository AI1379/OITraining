import pandas as pd
df = pd.read_csv("高二技术.csv")
print(df[df['技术总评'] > 95].groupby('班级').max())
print(df[df['技术总评'] > 95].groupby('班级').min())
print(df[df['技术总评'] > 95].groupby('班级').mean())
