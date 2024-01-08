import random
import math

print('Input filename: ')
filename = input()
print('k value: ')
k = input()
input = []
centroids = []
labels = []


file = open(filename, "r")
for line in file:
  x, y = line.partition("\t")[::2]
  y = y.rstrip("\n")
  input.append([int(x),int(y)])
print(input)

# pick k random centroids
for i in range(int(k)):
  r = random.randint(0, len(input)-1)
  centroids.append(input[r])
print(centroids)

# for each pair in input, calculate euclidean distance from each centroid
# determine closest centroids
def assign_cluster(input, centroids):
  smallest_distance = 10000
  closest_centroid = 0
  for pair in input:
    for centroid in centroids:
      d = math.sqrt((centroid[0] - pair[0]) ** 2 + (centroid[1] - pair[1]) ** 2)
      if d < smallest_distance:
        smallest_distance = d
        closest_centroid = centroid
      labels.append(centroids.index(closest_centroid)+1)


assign_cluster(input, centroids)
      
# append pairs with cluster labels
def assign_labels(input, labels):
  for i in range(0, len(input), 1):
    input[i].append(labels[i])
  print(input)


def replace_labels(input, labels):
  for i in range(0, len(input), 1):
    if (input[i][2] != labels[i]):
      input[i][2] = labels[i]
      change_flag += 1


assign_labels(input, labels)
new_centroids = []

# reassign mean centroid for clusters
def find_cluster_mean(input):
  xsum = 0
  ysum = 0
  k_label = 1
  new_centroids.clear()
  k_count = 0
  while (k_label <= int(k)):
    for each in input:
      if each[2] == k_label:
        k_count += 1
        xsum += each[0]
        ysum += each[1]
    new_centroids.append([math.floor(xsum/k_count), math.floor(ysum/k_count)])
    k_count = 0
    xsum = 0
    ysum = 0
    k_label += 1  
  print(new_centroids)


find_cluster_mean(input)


while (change_flag == 0):
  assign_cluster(input, new_centroids)      
  replace_labels(input, labels)