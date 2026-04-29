import dash
from dash import dcc, html, Input, Output
import plotly.express as px
import pandas as pd

# Load the Gapminder Dataset
df = px.data.gapminder()

app = dash.Dash(__name__)

# Layout incorporating Features from 1000266136.jpg
app.layout = html.Div([
    html.H1("Global Development Dashboard", style={'textAlign': 'center'}),
    
    # 1. Dynamic KPI Cards (Theory section in 1000266136.jpg)
    html.Div(id='kpi-cards', style={'display': 'flex', 'justifyContent': 'space-around', 'padding': '20px'}),
    
    # 2. Geographic Heatmap (Choropleth map)
    dcc.Graph(id='geo-heatmap'),
    
    # 3. Time Series Analysis & Top 10 Analysis
    html.Div([
        html.Div([dcc.Graph(id='time-series')], style={'width': '50%', 'display': 'inline-block'}),
        html.Div([dcc.Graph(id='bar-chart')], style={'width': '50%', 'display': 'inline-block'}),
    ]),
    
    # 4. Interactive Control (Slider)
    html.P("Select Year:"),
    dcc.Slider(
        id='year-slider',
        min=df['year'].min(),
        max=df['year'].max(),
        value=df['year'].max(),
        marks={str(year): str(year) for year in df['year'].unique()},
        step=None
    )
])

@app.callback(
    [Output('kpi-cards', 'children'),
     Output('geo-heatmap', 'figure'),
     Output('time-series', 'figure'),
     Output('bar-chart', 'figure')],
    [Input('year-slider', 'value')]
)
def update_dashboard(selected_year):
    year_df = df[df.year == selected_year]
    
    # KPI Logic
    avg_life = round(year_df['lifeExp'].mean(), 1)
    avg_gdp = round(year_df['gdpPercap'].mean(), 1)
    kpis = [
        html.Div([html.H3("Avg Life Expectancy"), html.P(f"{avg_life} years")]),
        html.Div([html.H3("Avg GDP per Capita"), html.P(f"${avg_gdp}")])
    ]
    
    # Geographic Heatmap
    geo_fig = px.choropleth(year_df, locations="iso_alpha", color="lifeExp", 
                            hover_name="country", title="Global Life Expectancy Heatmap")
    
    # Time Series (Historical trend for the world)
    ts_df = df.groupby('year')['gdpPercap'].mean().reset_index()
    ts_fig = px.line(ts_df, x='year', y='gdpPercap', title="Global GDP Growth Over Decades")
    
    # Top 10 Analysis (Bar Chart)
    top_10 = year_df.nlargest(10, 'gdpPercap')
    bar_fig = px.bar(top_10, x='country', y='gdpPercap', title="Top 10 Countries by GDP")
    
    return kpis, geo_fig, ts_fig, bar_fig

# To this:
if __name__ == '__main__':
    app.run(debug=True)
    app.run_server(debug=True)