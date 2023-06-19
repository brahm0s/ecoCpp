import pandas as pd 
import numpy as np 

import matplotlib 
import matplotlib.pyplot as plt

df = pd.read_csv("output.csv")
pivoted_df = df.pivot_table(index='FirmID', columns=df.groupby('FirmID').cumcount()+1, values='output')
# rename the columns to indicate the day number
num_days = pivoted_df.shape[1]
pivoted_df.columns = [f"day{i}" for i in range(1, num_days+1)]

# reset the index to make FirmID a regular column
pivoted_df.reset_index(inplace=True)

firm_list= df['FirmID'].unique()


pivoted_df.set_index('FirmID', inplace=True)

for i in firm_list:
    firm_data = pivoted_df.loc[i]

    # Plot the line chart
    plt.figure()
    firm_data.plot(kind='line')

    # Add labels and title
    plt.xlabel('Days')
    plt.ylabel('Value')
    plt.title(f'Values for Firm {i} over Days')

    # Save the figure
    plt.savefig(f'firm_{i}.png')

    # Close the figure
  

    plt.close()