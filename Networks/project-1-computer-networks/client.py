# client.py
import socket
import sys
import pickle

HOST = "eros.cs.txstate.edu"  # The server's hostname or IP address
PORT = 8992  # The port used by the server

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

loop = 1
while loop:
  data = s.recv(1024)
  print data
  option = str(input())
  s.sendall(option)
  if option == '1':
    print s.recv(1024)
    id = str(input())
    s.sendall(id)
    print s.recv(1024)
    fname = raw_input()
    s.sendall(fname)
    print s.recv(1024)
    lname = raw_input()
    s.sendall(lname)
    print s.recv(1024)
    score = str(input())
    s.sendall(score)
  elif option == '2':
    print s.recv(1024)
    id = str(input())
    s.sendall(id)
    new_list = pickle.loads(s.recv(4096))
    print "{0:<10}{1:<15}{2:<15}{3:<10}".format("ID", "First Name", "Last Name", "Score")
    print "{0:<10}{1:<15}{2:<15}{3:<10}".format(new_list[0], new_list[1], new_list[2], new_list[3])
    new_list.clear()
  elif option == '3':
    print s.recv(1024)
    score = str(input())
    s.sendall(score)
    new_list = pickle.loads(s.recv(4096))
    print "{0:<10}{1:<15}{2:<15}{3:<10}".format("ID", "First Name", "Last Name", "Score")
    for x in range(0, len(new_list), 4):
      print "{0:<10}{1:<10}{2:<10}{3:<10}".format(new_list[x], new_list[x+1], new_list[x+2], new_list[x+3])
    new_list.clear()
  elif option == '4':
    list = pickle.loads(s.recv(4096))
    print "{0:<10}{1:<15}{2:<15}{3:<10}".format("ID", "First Name", "Last Name", "Score")
    for x in range(0, len(list), 4):
      print "{0:<10}{1:<15}{2:<15}{3:<10}".format(list[x], list[x+1], list[x+2], list[x+3])
    list.clear()
  elif option == '5':
    print s.recv(1024)
    id = str(input())
    s.sendall(id)
  elif option == '6':
    loop = 0
  else:
    print "Invalid input.  Option must be integer, 1 through 5."
s.close()