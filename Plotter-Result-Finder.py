import numpy as np
import matplotlib.pyplot as plt
from Functions import *

######################## Passing Analysis ########################
passingFile = open('passing.txt', 'r')
passingList = read(passingFile)
passingScoreList = create_score_list(passingList)
passingZList = create_zscore_list(passingList)
passing_x = np.array(passingZList)
passing_y = np.array(passingScoreList)
scatter1 = plt.figure(1)
plt.scatter(passing_x, passing_y)
plt.xlabel("Z Score")
plt.ylabel("Score")
plt.title("NFL Passing Comparison")

# adding labels to the graph
index = 4
while index <= len(passingList):
    label = str(passingList[index-3]) + " " + str(passingList[index-4])
    x = float(passingList[index-1][0])
    y = float(passingList[index-2])
    plt.annotate(label, [x, y])
    index += 4
plt.subplots_adjust(right=0.82)


######################## Receiving Analysis ########################
receivingFile = open('receiving.txt', 'r')
receivingList = read(receivingFile)
receivingScoreList = create_score_list(receivingList)
receivingZList = create_zscore_list(receivingList)
receiving_x = np.array(receivingZList)
receiving_y = np.array(receivingScoreList)
scatter2 = plt.figure(2)
plt.scatter(receiving_x, receiving_y)
plt.xlabel("Z Score")
plt.ylabel("Score")
plt.title("NFL Receiving Comparison")

# adding labels to the graph
index = 4
while index <= len(receivingList):
    label = str(receivingList[index-3]) + " " + str(receivingList[index-4])
    x = float(receivingList[index-1][0])
    y = float(receivingList[index-2])
    plt.annotate(label, [x, y])
    index += 4
plt.subplots_adjust(right=0.82)


######################## Rushing Analysis ########################
rushingFile = open('rushing.txt')
rushingList = read(rushingFile)
rushingScoreList = create_score_list(rushingList)
rushingZlist = create_zscore_list(rushingList)
rushing_x = np.array(rushingZlist)
rushing_y = np.array(rushingScoreList)
scatter3 = plt.figure(3)
plt.scatter(rushing_x, rushing_y)
plt.xlabel("Z Score")
plt.ylabel("Score")
plt.title("NFL Rushing Comparison")

# adding labels to the graph
index = 4
while index <= len(rushingList):
    label = str(rushingList[index-3]) + " " + str(rushingList[index-4])
    x = float(rushingList[index-1][0])
    y = float(rushingList[index-2])
    plt.annotate(label, [x, y])
    index += 4
plt.subplots_adjust(right=.788)
plt.show()