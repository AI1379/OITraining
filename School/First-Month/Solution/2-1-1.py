import pandas as pd
dic = {
    'Name': ['Harry Potter', 'Ron Weasley', 'Hermione Granger',
             'Neville Longbottom', 'Luna Lovegood', 'Ginny Weasley',
             'Albus Dumbledore'],
    'Gender': ['Male', 'Male', 'Female', 'Male', 'Female', 'Female', 'Male'],
    'Height': [180, 185, 165, 170, 157, 167, 190],
    'Weight': [63, 72, 54, 62, 46, 53, 68],
}
df = pd.DataFrame(dic)
print(df)
