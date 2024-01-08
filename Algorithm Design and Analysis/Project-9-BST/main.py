import random

class TreeNode:
    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.left = None
        self.right = None

def insert(root, key, data):
    if root is None:
        return TreeNode(key, data)
    if key < root.key:
        root.left = insert(root.left, key, data)
    elif key > root.key:
        root.right = insert(root.right, key, data)
    return root

def in_order_traversal(root):
    if root:
        in_order_traversal(root.left)
        print(f"Student ID: {root.key}, Name: {root.data[0]}, Grades: {root.data[1]}")
        in_order_traversal(root.right)

def search(root, key):
    if root is None or root.key == key:
        return root
    if key < root.key:
        return search(root.left, key)
    return search(root.right, key)

def generate_student_records(count):
    student_records = []
    for _ in range(count):
        student_id = random.randint(100000, 999999)
        name = f"Student-{student_id}"
        grades = [random.randint(0, 100) for _ in range(10)]
        student_records.append((student_id, name, grades))
    return student_records

def main():
  # -- Student Records Set 1 --
  print("-- Student Records Set 1 --")
  # Generate student records for Set 1
  set1 = generate_student_records(20)
  # Display student records before BST insertion
  print("-- Student records before BST insertion --\n", set1, "\n")
  # Create and display BST for Set 1
  bst1 = None
  for student in set1:
      bst1 = insert(bst1, student[0], (student[1], student[2]))
  print("-- BST for Set 1 --")
  in_order_traversal(bst1)
  # Search two student records in Set 1 BST
  search_key1 = set1[10][0]
  search_key2 = set1[11][0]
  result1 = search(bst1, search_key1)
  result2 = search(bst1, search_key2)
  print("\n-- Search for two student records in Set 1 BST --")
  print(f"Search Results for Student ID {search_key1}: {result1.data}")
  print(f"Search Results for Student ID {search_key2}: {result2.data}")
  # Insert two student records into Set 1 BST
  print("\n-- Insert two new records into Set 1 BST and display --")
  insert_key1 = random.randint(100000, 999999)
  insert_key2 = random.randint(100000, 999999)
  bst1 = insert(bst1, insert_key1, (f"Insertion-{insert_key1}", [80, 85, 90, 95, 92, 88, 75, 78, 81, 89]))
  bst1 = insert(bst1, insert_key2, (f"Insertion-{insert_key2}", [70, 75, 80, 85, 82, 78, 65, 68, 71, 79]))
  # Display Set 1 BST after BST insertion
  in_order_traversal(bst1)

  # -- Student Records Set 2 --
  print("\n-- Student Records Set 2 --")
  # Generate student records for Set 2
  set2 = generate_student_records(20)
  # Display student records before BST insertion
  print("--Student records before BST insertion--\n", set2)
  # Create and display BST for Set 2
  bst2 = None
  for student in set2:
      bst2 = insert(bst2, student[0], (student[1], student[2]))
  print("\n-- BST for Set 2 --")
  in_order_traversal(bst2)
  # Search two student records in Set 2 BST
  search_key3 = set2[10][0]
  search_key4 = set2[11][0]
  result3 = search(bst2, search_key3)
  result4 = search(bst2, search_key4)
  print("\n-- Search for two student records in Set 2 BST --")
  print(f"Search Results for Student ID {search_key3}: {result3.data}")
  print(f"Search Results for Student ID {search_key4}: {result4.data}")
  # Insert two student records into Set 2 BST
  print("\n-- Insert two new records into Set 2 BST and display --")
  insert_key3 = random.randint(100000, 999999)
  insert_key4 = random.randint(100000, 999999)
  bst2 = insert(bst2, insert_key3, (f"New-Student-{insert_key3}", [85, 88, 92, 95, 90, 78, 85, 80, 88, 92]))
  bst2 = insert(bst2, insert_key4, (f"New-Student-{insert_key4}", [75, 80, 82, 78, 72, 68, 76, 80, 78, 80]))
  # Display Set 2 BST after BST insertion
  in_order_traversal(bst2)

if __name__ == "__main__":
  main()
