import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# set plot style
plt.style.use('fivethirtyeight')

# load data
df = pd.read_csv('data/data.csv')
ts['month'] = pd.to_datetime(df['PostDate']).dt.to_period('M')
ts = df.groupby('month')[['OR', 'TO']].sum().reset_index()
fig, ax = plt.subplots(figsize=(10, 6))

ax.plot(ts['month'], ts['OR'], label='OR')
ax.plot(ts['month'], ts['TO'], label='TO')
ax.set_title('Monthly Orders and Sales')
start, end = pd.to_datetime('2017-07-01'), pd.to_datetime('2024-06-30')



ax.set_xticklabels(ts['month'])
ax.legend()


