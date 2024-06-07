import pandas as pd
import numpy as np
import plotly.graph_objects as go

# draw a Pareto Chart with plotly
# export the figure to a png file
def pareto_chart(data, x, y, title):
    fig = go.Figure()
    fig.add_trace(go.Bar(x=data[x], y=data[y], name=y, marker_color='gray'))
    fig.add_trace(go.Scatter(x=data[x], y=data[y].cumsum(), mode='lines+markers', name='Cumulative Percentage', marker_color='rgb(26, 118, 255)', line=dict(color='rgba(26, 118, 255, 0.7)')))
    fig.update_layout(title=title, xaxis_title=x, yaxis_title=y, title_x=0.5, plot_bgcolor='rgba(0,0,0,0)')
    fig.update_layout(yaxis2=dict(title='Cumulative Percentage', side='right', overlaying='y'))
    fig.show()
    fig.write_image("pareto_chart.png", width=800, height=600)

    
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

# stack bar chart based on y1, y2, y3 with same x
def stack_bar_chart(data, x, y1, y2, y3, title):
    fig = go.Figure()
    fig.add_trace(go.Bar(x=data[x], y=data[y1], name=y1, marker_color='rgb(55, 83, 109)'))
    fig.add_trace(go.Bar(x=data[x], y=data[y2], name=y2, marker_color='rgb(26, 118, 255)'))
    fig.add_trace(go.Bar(x=data[x], y=data[y3], name=y3, marker_color='rgb(255, 153, 51)'))
    fig.update_layout(title=title, xaxis_title=x, yaxis_title='Count', title_x=0.5, barmode='stack', plot_bgcolor='rgba(0,0,0,0)')
    fig.update_layout(legend=dict(orientation="h", x=1, xanchor="right", y=1, yanchor="top"))
    fig.show()
