import pandas as pd
import numpy as np
import plotly.graph_objects as go

# draw a Pareto Chart with plotly
def pareto_chart(data, x, y, title):
    fig = go.Figure()
    fig.add_trace(go.Bar(x=data[x], y=data[y], name=y, marker_color='rgb(55, 83, 109)'))
    fig.add_trace(go.Scatter(x=data[x], y=data[y].cumsum(), mode='lines+markers', name='Cumulative Percentage', marker_color='rgb(26, 118, 255)'))
    fig.update_layout(title=title, xaxis_title=x, yaxis_title=y, title_x=0.5)
    fig.show()

    
from plotly.subplots import make_subplots
import plotly.graph_objects as go
from statsmodels.tsa.seasonal import seasonal_decompose, STL

# decompose the time series data
def decompose(ts):
    decomposition = STL(ts, period=12).fit()

    fig = make_subplots(
        rows=4, cols=1,
        shared_xaxes=True,
        vertical_spacing=0.05,
        subplot_titles=['observed', 'trend', 'seasonal', 'resid']
    )

    x = ts.index
    fig.add_trace(go.Scatter(x=x, y=decomposition.observed), row=1, col=1)
    fig.add_trace(go.Scatter(x=x, y=decomposition.trend), row=2, col=1)
    fig.add_trace(go.Scatter(x=x, y=decomposition.seasonal), row=3, col=1)
    fig.add_trace(go.Scatter(x=x, y=decomposition.resid), row=4, col=1)

    fig.update_layout(
        height=1200, margin={'t':20, 'b':0, 'l':0, 'r':0},
        xaxis4=dict(title="Fiscal Months", dtick='M12', range=['2017-07-01','2024-06-30']),
        showlegend=False
    )
    fig.show()