class Node(object):
    def __init__(self, name):
        self.name = name
        self.seen = False
        self.neighbours = []

def load_graph_edges(edge_list):
    node_list = []
    graph = []
    for edge in edge_list:
        node_a = edge[0] if edge[0] < edge[1] else edge[1]
        node_b = edge[1] if edge[1] > edge[0] else edge[0]
        node_A = []
        node_B = []

        # Create/get nodeA
        if node_a not in node_list:
            node_list.append(node_a)
            node_A.append(Node(node_a))
            graph.append(node_A[0])
        else:
            for node in graph:
                if node.name == node_a:
                    node_A.append(node)
                    break

        # Create/get nodeB
        if node_b not in node_list:
            node_list.append(node_b)
            node_B.append(Node(node_b))
            graph.append(node_B[0])
        else:
            for node in graph:
                if node.name == node_b:
                    node_B.append(node)
                    break

        # Add nodeA/B to each other as neighbours
        for node in graph:
            if node.name == node_a:
                node.neighbours.append(node_B[0])
            if node.name == node_b:
                node.neighbours.append(node_A[0])

    return graph

def get_bfs_list(edges):
    #Load edges
    graph = load_graph_edges(edges)

    #BFS
    visit_queue = [graph[0]]    # Queue of nodes to visit (and add neighbours at front of queue to back)
    visited = []                # Visited nodes to exclude from queuing to visit_queue
    bfs_list = []               # BFS ordering

    # Read visit_queue until all nodes have been exhausted
    while len(visit_queue) > 0:
        bfs_list.append(visit_queue[0])
        visited.append(visit_queue[0].name)

        # Append all neighbours of front of visit queue if they haven't been visited yet
        for node in visit_queue[0].neighbours:
            if not node.name in visited:
                visit_queue.append(node)
                visited.append(node.name)
        visit_queue.pop(0)

    return bfs_list


#edges = [['A','B'], ['A','C'], ['B','C'], ['B','D'], ['B','E'], ['C','D'], ['C','E'], ['D','E'],['D','F'],['E','F']]
edges = [['A','D'], ['A','E'], ['D','C'], ['D','B'], ['E','B'], ['B','C']]

bfs = get_bfs_list(edges)
for node in bfs:
    print (node.name)

