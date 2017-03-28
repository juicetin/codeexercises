class Queue:
    def __init__(self):
        self.data = []
        self.size = 0

    def queue(self, item):
        self.data = [item] + self.data
        self.size += 1

    def dequeue(self):
        removed_item = self.data[-1]
        self.data = self.data[:-1]
        self.size -= 1
        return removed_item

    def empty(self):
        return self.size == 0

    def display(self):
        print(list(reversed(self.data)))

def initialise_adjacency_list_if_needed(graph, v1, v2):
    if v1 not in graph:
        graph[v1] = []
    if v2 not in graph:
        graph[v2] = []

def BFS_with_visited_count(graph, start, visited_node_flags):
    q = Queue()
    q.queue(start)
    visited_count = 1
    while not q.empty():
        cur = q.dequeue()
        visited_node_flags[cur] = 1
        if len(graph[cur]) == 0:
            continue
        for adjacentNode in graph[cur]:
            if visited_node_flags[adjacentNode]:
                continue
            q.queue(adjacentNode)
            visited_count += 1
            visited_node_flags[adjacentNode] = 1
    return visited_count

def build_graph_and_nodes(edge_count):
    graph = {}
    nodes = set([])
    for i in range(edge_count):
       v1, v2 = list(map(lambda x:int(x)-1, input().split(' '))) 
       nodes.add(v1)
       nodes.add(v2)
       initialise_adjacency_list_if_needed(graph, v1, v2)
       graph[v1].append(v2)
       graph[v2].append(v1)
    nodes = range(max(nodes)+1)

    return graph, nodes

def find_next_starting_point(visited_node_flags):
    for i, flag in enumerate(visited_node_flags):
        if flag == 0:
            return i

def mark_nonexistent_nodes(visited_node_flags, graph):
    for i in range(len(visited_node_flags)):
        node_exists = i in graph
        if not node_exists:
            visited_node_flags[i] = 1

edge_count = int(input())
graph, nodes = build_graph_and_nodes(edge_count)

visited_node_flags = [0] * len(nodes)
mark_nonexistent_nodes(visited_node_flags, graph)

starting_node = find_next_starting_point(visited_node_flags)
visited_counts = []
while sum(visited_node_flags) < len(nodes):
    visited_this_round = BFS_with_visited_count(graph, starting_node, visited_node_flags)
    visited_counts.append(visited_this_round)
    starting_node = find_next_starting_point(visited_node_flags)

print(min(visited_counts), max(visited_counts))
