# Bellman-Ford
Implementation of Bellman-Ford Algorithm to find the shortest distance between source node and other nodes. 
Bellman Ford Algorithm can also used be in a network with negative edges.

The project asks the user for the number of Vertices and Edges in the network.
Then user is asked to enter the all the edges in the network.
E.g if there is a edge directed from node 1 to node 2 with weight of -2,
it will be entered as 1 2 -2.
At the end, user is asked to enter the node from which the minimum distance to other nodes is to be calculated.

For example, for 1->2 (2), 2->3(1), and 1->3(4) directed graph

Enter the number of Vertices in the graph 3
Enter the number of Edges in the graph 3
Enter start-end-weight for the edges
1 2 2
2 3 1
1 3 4
Enter the source node 1
Vertex Distance from Source
1 0
2 2
3 3
