from collections import defaultdict, deque

class MapColoring:
  def __init__(self):
    self.graph = defaultdict(list)
    self.colors = ["Blue", "Brown", "Green", "Lavender", "Orange", "Pink", "Red", "Yellow", "Violet", "Gold", "Gray", "Indigo", "Silver"]
    self.color_map = {}

  def add_edge(self, country1, country2):
    self.graph[country1].append(country2)
    self.graph[country2].append(country1)

  def display_adjacency_list(self):
    print("Adjacency List Representation:")
    for country, neighbors in self.graph.items():
      print(f"{country}: {', '.join(neighbors)}")

  def color_map_south_america(self):
    for country in self.graph:
      used_colors = set()
      for neighbor in self.graph[country]:
        if neighbor in self.color_map:
          used_colors.add(self.color_map[neighbor])

      for color in self.colors:
        if color not in used_colors:
          self.color_map[country] = color
          break

  def display_color_map(self):
    print("\nCountry Colors:")
    for country, color in self.color_map.items():
      print(f"{country}: {color}")

    print("\nColors Used:")
    used_colors = set(self.color_map.values())
    print(', '.join(used_colors))

  def bfs_tree(self, start):
    visited = set()
    bfs_tree = defaultdict(list)

    queue = deque([start])
    visited.add(start)

    while queue:
      current = queue.popleft()
      for neighbor in self.graph[current]:
        if neighbor not in visited:
          queue.append(neighbor)
          visited.add(neighbor)
          bfs_tree[current].append(neighbor)

    return bfs_tree

  def display_bfs_tree(self, start):
    bfs_tree = self.bfs_tree(start)
    print("\nBFS Tree:")
    for node, neighbors in bfs_tree.items():
      print(f"{node}: {', '.join(neighbors)}")

# Create a Map Coloring instance
south_america_map = MapColoring()

# Add edges for a simplified map
south_america_map.add_edge("v", "r")
south_america_map.add_edge("r", "s")
south_america_map.add_edge("s", "w")
south_america_map.add_edge("w", "t")
south_america_map.add_edge("t", "u")
south_america_map.add_edge("u", "y")
south_america_map.add_edge("y", "x")
south_america_map.add_edge("x", "w")
south_america_map.add_edge("x", "t")
south_america_map.add_edge("x", "u")


# Display adjacency list representation of the graph
south_america_map.display_adjacency_list()

# Color the map
south_america_map.color_map_south_america()

# Display the color map
south_america_map.display_color_map()

# Display the BFS tree starting from Brazil
south_america_map.display_bfs_tree("t")