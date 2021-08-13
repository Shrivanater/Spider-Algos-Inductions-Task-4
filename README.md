# Spider-Algos-Inductions-Task-4
*Raw is better formatted*

Q1:
Run a DFS to traverse the graph.
  Keep track of adjacencies and visited nodes in two separate maps.
  Recursive  DFS:
    Mark current node as visited and increment no of visited nodes.
    If visit == n, then we've traversed all nodes and formed a complete route.
    Loop thru adjacent nodes.
      If a node is unvisited, call DFS on that node. Move thru a branch like this.
      After reaching the end of a branch, it backtracks to the last fork and unmarks any nodes it passes thru.

Q2:
Convert inputs into weighted adjacency graph.
Run Prim's Algorithm for Mimimum Spanning Tree.
  Adds nodes to the MST if they're adjacent to and have minimum distance from one of the existing MST nodes. This will excludes edges which are pointlessly long.
M - no of edges in MST = no of useless edges.

Q3:
Create 2 arrays, one for traversing the input array forwards(fw[]) and one for backwards(bw[]).
Traverse the input array forwards and calculate the sum upto n elements for fw[n].
Keep track of the maximum sum.
Repeat for backwards.
The final ans will add values of fw and bw while leaving out subarrays varying from length 1 to K. This gives us the subarray sum while skipping upto K contiguous elements. 
  If any values of fw or bw are negative while being summed, they are ignored and 0 is added instead.
In case all numbers are -ve, it returns the max element of the array.  
