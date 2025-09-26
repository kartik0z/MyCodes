# Write a program to display Bar graphs or Pie chart using Matplotlib.

import matplotlib.pyplot as plt
import numpy as np

# Sample data
categories = ['A', 'B', 'C', 'D']
values = [10, 24, 36, 40]
x = np.arange(len(categories))
width = 0.4
# Bar Graph
plt.bar(x, values, width, color='b', label='Values')
plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Bar Graph Example')
plt.xticks(x, categories)
plt.legend()
plt.show()
# Pie Chart
plt.pie(values, labels=categories, autopct='%1.1f%%', startangle=140)
plt.title('Pie Chart Example')
plt.show()