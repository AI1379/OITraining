import pandas as pd
df = pd.read_csv("高二技术.csv")
print(df.groupby("班级")['技术总评'].mean())