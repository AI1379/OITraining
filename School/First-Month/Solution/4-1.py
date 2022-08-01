import pandas as pd
df = pd.read_excel('./高二技术.xlsx')
print(df.sort_values('技术总评', ignore_index=True, ascending=False)[:20])
