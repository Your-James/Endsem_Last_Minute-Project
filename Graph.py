#ACCURACY
#WPM
#TIME TAKEN
#NUMBER OF ATTEMPTS


import csv
import matplotlib.pyplot as plt
import pandas as pd


l = []
for value in range(4):
    val = (input())
    l.append(val)
    


with open("E:\Project\demo\Type_Info.csv","a") as File:
    writer = csv.writer(File)
    writer.writerow(l)
File.close()

plt.style.use('bmh')
#data frame variable: reads the csv file
df = pd.read_csv('E:\Project\demo\Type_Info.csv')

x1 = df['Attempts']
y1 = df['Accuracy']
y2 = df['Wpm']
y3 = df['Time Taken']

plt.title('Graph of Accuracy, Wpm, Time Taken')
#Bar graph
#plt.xlabel('Attempts', fontsize=18)
#plt.ylabel('Accuracy', fontsize=18)
#plt.bar(x,y)

#Line graph
plt.xlabel('Attempts', fontsize=18)
#plt.ylabel('Accuracy',fontsize=18)
#for scattered points
#plt.scatter(x1,y1)
#for joined points
plt.plot(x1,y1, label = 'Accuracy')
plt.plot(x1,y2, label = 'Wpm')
plt.plot(x1,y3, label = 'Time Taken')


plt.legend()
plt.show()