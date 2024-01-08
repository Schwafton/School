import  random
import math

# 1000 processes
# avg. arrival rate: 2 processes / second, Poisson distribution
# avg. service time: 1 second, exponential distribution
# process IDs assigned incrementally beginning at 1
# output: list of tuples <process ID, arrival time, requested service time>

def problem1():
  ta = 0
  ts = 0
  processes = []
  for i in range(1, 1001, 1):
    z = float(random.uniform(0, 1))
    x = float(-(1/2)*math.log(z))
    ta += x
    ts = float(-(1)*math.log(z))
    processes.append([i, ta, ts])
  suma = 0
  sums = 0
  for process in processes:
    print(process)
    suma += process[1]
    sums += process[2]
  print("Actual average arrival rate: ", 1000/processes[999][1])
  print("Actual average service time: ", sums/1000)




# 2 servers (mirrors)
# MTBF: 500 hours (average of continuous uptimes)
# continuous uptimes: Follows exponential distribution
# When server fails, it takes exactly 10 hours to restore the data from the mirror
# a) synthesize failure and restoration times for 20 years (assume 24 h/d, 365 d/y)
def problem2a():
  time_elapsed1 = 0
  time_elapsed2 = 0
  total_ut1 = 0
  total_ut2 = 0
  total_dt1 = 0
  total_dt2 = 0
  failures1 = 0
  failures2 = 0
  failt1 = []
  failt2 = []
  

  while ((time_elapsed1 < 175200) or (time_elapsed2 < 175200)):
    if time_elapsed1 < 175200:
      z1 = random.uniform(0,1)
      ut1 = -(500)*math.log(z1)
      total_ut1 += ut1 - 10
      total_dt1 += 10
      failures1 += 1
      time_elapsed1 += ut1
      failt1.append(time_elapsed1)
      print("Server 1 Fail time (h): ", time_elapsed1)
      print("Server 1 Restore time (h): ", time_elapsed1+10)
    if time_elapsed2 < 175200:
      z2 = random.uniform(0,1)
      ut2 = -(500)*math.log(z2)
      total_ut2 += ut2 - 10
      total_dt2 += 10
      failures2 += 1
      time_elapsed2 += ut2
      failt2.append(time_elapsed2)
      print("Server 2 Fail time (h): ", time_elapsed2)
      print("Server 2 Restore time (h): ", time_elapsed2+10)
  
  print()
  print("Server 1")
  print("Total failures: ", failures1)
  print("Total uptime: ", total_ut1)
  print("Total downtime: ", total_dt1)
  print()
  print("Server 2")
  print("Total failures: ", failures2)
  print("Total uptime: ", total_ut2)
  print("Total downtime: ", total_dt2)
  print()
  print("In the simulation above, the first failure times for server 1 (left) and server 2 (right) resulting in overlapping downtime:")
  stop = 0
  for time1 in failt1:
    if stop == 1:
      break
    for time2 in failt2:
      if abs(time1 - time2) < 10:
        print(time1, time2)
        stop += 1
        break

def problem2bHelper():
  time_elapsed1 = 0
  time_elapsed2 = 0
  total_ut1 = 0
  total_ut2 = 0
  total_dt1 = 0
  total_dt2 = 0
  failures1 = 0
  failures2 = 0
  failt1 = []
  failt2 = []
  

  while ((time_elapsed1 < 175200) or (time_elapsed2 < 175200)):
    if time_elapsed1 < 175200:
      z1 = random.uniform(0,1)
      ut1 = -(500)*math.log(z1)
      total_ut1 += ut1 - 10
      total_dt1 += 10
      failures1 += 1
      time_elapsed1 += ut1
      failt1.append(time_elapsed1)

    if time_elapsed2 < 175200:
      z2 = random.uniform(0,1)
      ut2 = -(500)*math.log(z2)
      total_ut2 += ut2 - 10
      total_dt2 += 10
      failures2 += 1
      time_elapsed2 += ut2
      failt2.append(time_elapsed2)

  stop = 0
  for time1 in failt1:
    if stop == 1:
      break
    for time2 in failt2:
      if abs(time1 - time2) < 10:
        if time1 > time2:
          return time1
        else:
          return time2
        stop += 1
        break


def problem2b():
  failsum = 0
  for l in range(1000):
    p = problem2bHelper()
    print(p)
    failsum += p
  print()
  print(failsum/1000)


problem1()