# server.py
import socket
import sys
import pickle

HOST = "eros.cs.txstate.edu"  # Standard loopback interface address (localhost)
PORT = 8992  # Port to listen on (non-privileged ports are > 1023)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind((HOST, PORT))
s.listen(1)

conn, addr = s.accept()
print("Connected by ", addr)

loop = 1
while loop:
  conn.sendall("Student Score Database\n\n1 ADD NEW STUDENT\n2 DISPLAY STUDENT INFO WITH ID\n3 DISPLAY STUDENT INFO WITH SCORE\n4 DISPLAY ALL STUDENT INFO\n5 DELETE STUDENT ENTRY WITH ID\nSelect option: ")
  option = conn.recv(1024)
  if option == '1':
    f = open("database.txt", "a")
    conn.sendall("Student ID: ")
    id = conn.recv(1024)
    conn.sendall("First Name: ")
    fname = conn.recv(1024)
    conn.sendall("Last Name: ")
    lname = conn.recv(1024)
    conn.sendall("Score: ")
    score = conn.recv(1024)
    f.writelines([id, " ", fname, " ", lname, " ", score, "\n"])
    f.close()
  elif option == '2':
    f = open("database.txt", "r")
    conn.sendall("Student ID: ")
    id = conn.recv(1024)
    database = f.read()
    list = database.split()
    f.close()
    index = list.index(id)
    new_list = []
    new_list.append(list[index])
    new_list.append(list[index+1])
    new_list.append(list[index+2])
    new_list.append(list[index+3])
    data = pickle.dumps(new_list)
    conn.send(data)
    list.clear()
    new_list.clear()
  elif option == '3':
    f = open("database.txt", "r")
    conn.sendall("Score: ")
    score = conn.recv(1024)
    database = f.read()
    list = database.split()
    f.close()
    new_list = []
    for x in range(3, len(list), 4):
      if list[x] == score:
        new_list.append(list[x-3])
        new_list.append(list[x-2])
        new_list.append(list[x-1])
        new_list.append(list[x])
    print new_list
    data = pickle.dumps(new_list)
    conn.send(data)
    list.clear()
    new_list.clear()
  elif option == '4':
    f = open("database.txt", "r")
    file = f.read()
    list = file.split()
    f.close()
    data = pickle.dumps(list)
    conn.send(data)
  elif option == '5':
    conn.sendall("Student ID: ")
    id = conn.recv(1024)
    f = open("database.txt", "r")
    database = f.read()
    list = database.split()
    f.close()
    if list.index(id):
      index = list.index(id)
      list.pop(index)
      list.pop(index)
      list.pop(index)
      list.pop(index)
    f = open("database.txt", "w")
    for x in range(0, len(list), 4):
      f.writelines([list[x], " ", list[x+1], " ", list[x+2], " ", list[x+3], "\n"])
    f.close()
    list.clear()
  elif option == '6':
    loop = 0
  else:
    break
conn.close()