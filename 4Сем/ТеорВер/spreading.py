import random


def pseudo_norm(average = 50, sko = 3):
    """Generate a value between 1-100 in a normal distribution"""
    min=average-3*sko
    max = average+3*sko
    count= sko
    values =  sum([random.randint(min, max) for x in range(count)])
    return values/count

def pseudo_uniform(min=0, max=100):
    values =  random.randint(min, max)
    return values

def ascii_plot(dist, num_of_intervals=20):
    """makes plot and output base information about 2d list"""

    counted= [0] * num_of_intervals
    minimal = min(dist)
    interval = (max(dist)-minimal)/num_of_intervals
    print(f"max number = {max(dist)}")
    print(f"min number= {min(dist)}")
    print(f"interval = {interval}")
    print(f"average = {sum(dist)/len(dist)}")
    print('\n')
    for i in dist:
        counted[round((i-minimal)/interval)-1]+=1
        #print(f"{i} goes to {round((i-minimal)/interval)} interval")

    sizeX= num_of_intervals
    sizeY= max(counted)
    plot =[]
    for i in range(sizeY):
        plot.append([0]*sizeX)

    for x in range(sizeX):
        for y in range(counted[x]):
            plot[sizeY-y-1][x]=counted[x]
        
    #show
    labelY=sizeY
    for i in range(sizeY):
        
        string =f"{labelY}\t"
        labelY-=1
        for char in plot[i]:
            if char==0:
                string+=" "
            else:
                string+="|"
        print(string)
    underscore= "Y/X\t"
    for i in range(sizeX):
        underscore+=str('-')
    print(underscore)

for i in range(10):

    #dist = [random.uniform(1, 100) for x in range(100)]
    #dist = [random.pseudo_norm(50, 3) for x in range(100)]
    dist = [random.gauss(1, 100) for x in range(100)]
    ascii_plot(dist)
    print('\n')
    print(dist)

