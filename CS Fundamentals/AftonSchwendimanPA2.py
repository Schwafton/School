import random
import math
PROCESSES = 10000

# Simulate 10k processes.
# Output:
# Avg. turnaround time
# Total throughput (num of processes done per unit time)
# Avg. cpu utilization
# avg. num of processes in ready queue

class Event:
  def __init__(self, ty, ti):
    self.type = ty
    self.time = ti  # = clock + interarrival time
    self.next = None
    
class EventQueue:
  def __init__(self):
    self.readyQueueCount = 0 #current number of processes ready
    self.eventQueueCount = 0
    self.head = None
    self.clock = 0 #current simulation time
    self.idle = True  #current state of the system
    self.serviceTime = 0
    self.arrivalCount = 0
    self.arrivalTime = 0
    self.departureCount = 0
    self.departureTime = 0
    
  def sched_event(self, type, time):
    event = Event(ty = type, ti = time)
    new = event
    if (self.head == None or new.time < self.head.time):
      new.next = self.head
      self.head = new
    else:
      temp = self.head
      while (temp.next != None and temp.next.time < new.time):
        temp = temp.next
      new.next = temp.next
      temp.next = new
    self.eventQueueCount += 1
    if event.type == 0:
      self.arrivalTime += event.time
    else:
      self.departureTime += event.time
    return event
    
  def arr_handler(self):
    interarrival_time = self.get_time(1/l)
    arrival_time = self.clock + interarrival_time
    service_time = self.get_time(s)
    departure_time = self.clock + service_time
    if self.idle == True:
      self.idle = False
      self.sched_event(1, departure_time) #schedule departure
      self.serviceTime += service_time
    else:
      self.readyQueueCount += 1
    if self.arrivalCount < PROCESSES:
      self.sched_event(0, arrival_time)  # schedule arrival
      self.arrivalCount += 1
     
  def dep_handler(self):
    if self.readyQueueCount == 0:
      self.idle = True
    else:
      self.readyQueueCount -= 1
      service_time = self.get_time(s)
      departure_time = self.clock + service_time
      self.sched_event(1, departure_time)
      self.serviceTime += service_time

  def get_time(self, v):  #get interarrival or service time, v = avg. arrival rate or service time
    z = float(random.uniform(0,1))  #generate uniform random between 0 and 1
    x = float(-(v)*math.log(z))  #generate interarrival or service time
    return x
  
  def run(self):
    self.sched_event(0, self.get_time(1/l)) #schedule first arrival
    self.arrivalCount += 1
    while self.departureCount < PROCESSES:
    # get next event
      e = self.head   # Get current head
    # record the Time
      current_time = self.clock
      self.clock = e.time
    # interval length since last event
      time_elapsed = self.clock - current_time
    # record states within that inerval
    # clock = e->time;
      if e.type == 0:    # ARR = 0
        self.arr_handler()
      elif e.type == 1:   # DEP = 1
        self.dep_handler()
        self.departureCount += 1
      # delete e from the event queue
      self.head = self.head.next  # Set the head to the next in line
      self.eventQueueCount -= 1  # Decrement size of queue

simulation = 1
while simulation == 1:
  l = int(input("\nEnter Avg. Arrival Rate (processes/second): "))
  s = float(input("\nEnter Avg. Service Time (seconds): "))
  eq = EventQueue()  #create event queue object
  eq.run()
  p = eq.serviceTime/eq.clock  #utilization
  ts = eq.serviceTime/PROCESSES #avg. service time
  u = 1/ts  #avg. service rate
  tq = (eq.departureTime - eq.arrivalTime)/PROCESSES  #avg. turnaround time
  tp = PROCESSES/eq.clock  #total throughput
  w = (p/float(1-p))-p
  print("\nAvg. Turnaround Time: ", tq, "\nTotal Throughput: ", tp, "\nAvg. Utilization: ", p, "\nAvg. Processes in Ready Queue: ", w)
  with open('output.txt', 'a') as f:
    print(l, "\t", tq, "\t", tp, "\t", p, "\t", w, file=f)
  print("\nRun another simulation?\n1. YES\n2. NO")
  simulation = int(input("Choice: "))