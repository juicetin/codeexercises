class Node(object):
    def __init__(self, name):
        self.name = name
        self.seen = False
        self.value = float("inf")
        self.neighbours = []
        self.neighbour_weights = []

edges = [['A','B',2], ['A','C',1], ['B','C',3], ['B','D',4], ['B','E',3], ['C','D',1], ['C','E',2], ['D','E',1],
        ['D','F',3], ['E','F',1]]

node_list = []
graph = []

#Loading edges
for edge in edges:
    node_a = edge[0] if edge[0] < edge[1] else edge[1] 
    node_b = edge[1] if edge[1] > edge[0] else edge[0]

    if node_a not in node_list:
        node_list.append(node_a)
        graph.append(Node(node_a))

    if node_b not in node_list:
        node_list.append(node_b)
        graph.append(Node(node_b))

    for node in graph:
        if node.name == node_a:
            node.neighbours.append(node_b)
            node.neighbour_weights.append(edge[2])

#Perform Dijkstra's
while graph[-1].seen != True:
    pass

for node in graph:
    print (node.name)
    print (node.neighbours)
    print (node.neighbour_weights)
    print ()
