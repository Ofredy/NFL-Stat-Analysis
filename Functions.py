def read(file):
    lines = file.readlines()
    information = []
    for line in lines:
        temp = line.split(",")
        year = temp[0].split(" ")
        year = year[-1]
        name = temp[1]
        score = temp[2].split(" ")
        score = score[-1]
        dfm = temp[-1]
        dfm = dfm.split(" ")
        dfm = dfm[-1]
        dfm = dfm.split()
        information.append(year)
        information.append(name)
        information.append(score)
        information.append(dfm)
    return information

def create_score_list(list):
    scoreList = []
    count1 = 0
    count2 = 0
    while count2 < len(list):
        if(count1==2):
            score = float(list[count2])
            scoreList.append(score)
        count1 = (count1+1)%4
        count2 += 1
    return scoreList
    

def create_zscore_list(list):
    dfmList = []
    count1 = 0
    count2 = 0
    while count2 < len(list):
        if(count1==3):
            dfm = float(list[count2][0])
            dfmList.append(dfm)
        count1 = (count1+1)%4
        count2 += 1
    return dfmList