import random

# Create an array of 4-digits student IDs of Size 500
student_ids = [random.randint(1000, 9999) for _ in range(500)]
# Display student IDs
print("STUDENT IDS")
print("-----------")
print(student_ids)

# Linked Hash Table
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return key % self.size

    def insert(self, data):
        index = self.hash_function(data)
        if not self.table[index]:
            self.table[index] = Node(data)
        else:
            current = self.table[index]
            while current.next:
                current = current.next
            current.next = Node(data)

    def print_table(self):
        for i in range(self.size):
            current = self.table[i]
            if current:
                print(f"{i}\t\t", end="\t")
                while current:
                    print(current.data, end=" ")
                    current = current.next
                print(" ")
            else:
                print(f"{i}\t\t\tNone Mapped")

# Create hash table and inserting the student IDs
m = 173  # Chosen prime number as per the requirement
hash_table = HashTable(m)
for student_id in student_ids:  # Populate hash table with student IDs
    hash_table.insert(student_id)

# Display hash table
print("HASH TABLE")
print("----------")
print("Address\t\tIDs")
hash_table.print_table()

# C. Sequential search
def sequential_search(array, key):
    count = 0
    for i in range(len(array)):
        count += 1
        if array[i] == key:
            return True, count
    return False, count

# D. Computational Complexity Comparison Table
print("ID FOUND")
print("--------")
print("ID\t\tSeqS\tHashing  ")
for i in range(1, 18):
    search_id = random.choice(student_ids)
    result, count_seq = sequential_search(student_ids, search_id)
    index = hash_table.hash_function(search_id)
    count_hash = 1
    current = hash_table.table[index]
    while current:
        if current.data == search_id:
            break
        count_hash += 1
        current = current.next
    print(f"{search_id}\t{count_seq}\t\t{count_hash}")

print("ID NOT FOUND")
print("------------")
for i in range(1, 4):
    m = max(student_ids)
    search_id = random.choice([x for x in range(m) if x not in student_ids])
    result, count_seq = sequential_search(student_ids, search_id)
    index = hash_table.hash_function(search_id)
    count_hash = 1
    current = hash_table.table[index]
    while current:
        if current.data == search_id:
            break
        count_hash += 1
        current = current.next
    print(f"{search_id}\t{count_seq}\t\t{count_hash}")