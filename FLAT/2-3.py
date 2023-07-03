import graphviz


def connection(adjacency_matrix, nodes):
    if nodes==0:
        return False
    visited = set()
    def bypass(v):
        visited.add(v)
        for i in range(nodes):
            if adjacency_matrix[v][i] != '0' and i not in visited:
                bypass(i)
    bypass(0)
    return len(visited)==nodes



num_edges = 0
# a = r"adjacency_matrix_0.txt"
a = r"matrix.txt"
dot = graphviz.Graph('graph', comment='A Round Graph')
with open(a, 'r') as file:
    nodes = len(file.readline().split())
for i in range(1, nodes + 1):
    dot.node(str(i), str(i), fontsize='20')
with open(a, 'r') as file:
    adj = [line.split() for line in file]
if connection(adj, nodes):
    print('Граф связан')
else:
    print('Граф не связан')

for i in range(nodes):
    for j in range(nodes):
        if adj[i][j] == 'a':
            continue
        weight = int(adj[i][j])
        if weight != 0:
            dot.edge(str(i + 1), str(j + 1), xlabel=str(weight))
            num_edges += 1
        adj[i][j] = 'a'
        adj[j][i] = 'a'
dot.render('doctest-output/round-table.gv', view=True)
