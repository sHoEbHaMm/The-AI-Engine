*Movement Behaviors*:

KineMatic motion along the border of the window:
![](https://github.com/sHoEbHaMm/The-AI-Engine/blob/main/Media/Kinematic.gif)
Dynamic Seek:
![](https://github.com/sHoEbHaMm/The-AI-Engine/blob/main/Media/Seek.gif)
Dynamic Arrive:
![](https://github.com/sHoEbHaMm/The-AI-Engine/blob/main/Media/Arrive.gif)

*Pathfinding*:

Dijkstra’s vs A*
1. Runtime:
-	Dijkstra's Algorithm: Dijkstra's algorithm explores nodes in order of their distance from the source node. It guarantees finding the shortest path but may explore many unnecessary nodes. Its runtime depends on the number of nodes and edges in the graph.
-	A* Algorithm: A* algorithm combines Dijkstra's approach with heuristics to guide the search towards the goal. It often explores fewer nodes compared to Dijkstra's algorithm, especially in graphs with a well-designed heuristic. Its runtime depends on the quality of the heuristic and the structure of the graph.
  
2. Number of Nodes Visited:
-	Dijkstra's Algorithm: Dijkstra's algorithm visits all nodes reachable from the source node until it reaches the destination. It explores nodes uniformly, without considering any information about the goal node.
-	A* Algorithm: A* algorithm typically visits fewer nodes than Dijkstra's algorithm because it uses heuristics to prioritize nodes that are likely to lead to the goal. The number of nodes visited depends on the quality of the heuristic and how well it guides the search.
  
3. Memory Usage:
-	Both algorithms store information about visited nodes and their distances. The memory usage depends on the data structures used to represent the graph, visited nodes, and priority queues (if applicable). In general, Dijkstra's algorithm may use more memory because it explores more nodes, potentially storing information about all nodes in the graph. However, in my case I used a 2D array of nodes/tiles.
  
4. Graph Structure:
-	Performance of both algorithms can be significantly affected by the structure of the graph. But in my case both algorithms used the same tile graphs. However, from whatever I have learnt so far from these algorithms is:
-	Dijkstra's algorithm explores nodes uniformly, making it suitable for graphs with uniform edge costs or where the shortest path is not known in advance.
-	A* algorithm benefits from a well-designed heuristic. In graphs where the heuristic provides accurate estimates of the remaining distance to the goal, A* can efficiently find the shortest path by prioritizing promising nodes.
-	In graphs with irregular structures, obstacles, or varying edge costs, A* may outperform Dijkstra's algorithm by avoiding unnecessary exploration.

5. Other Considerations:
-	A* algorithm is generally preferred when the problem domain allows for a good heuristic that guides the search effectively. However, designing a good heuristic can be challenging and may require domain-specific knowledge.
-	Dijkstra's algorithm is simpler to implement and guarantees finding the shortest path, but it may be less efficient in terms of runtime and memory usage compared to A* in certain scenarios.
-	Both algorithms are optimal in terms of finding the shortest path, but A* often achieves this with fewer node visits in practice when a good heuristic is available

6. Abstraction scheme: TileGraph
  - Large Tile Graph: 100x100 Nodes
   ![image](https://github.com/user-attachments/assets/e59f3237-44aa-4031-b8f6-fb64215adec3)

  - Smaller Tile Graph: 6x6 Nodes
    ![image](https://github.com/user-attachments/assets/41ba07f2-f1d6-46d5-b167-8b7562657848)

7. Heuristics:
*Manhattan Distance Heuristic*:
- Description: The Manhattan distance heuristic calculates the distance between two nodes on a grid by summing the absolute differences in their row and column indices. It measures the shortest distance between two points when only horizontal and vertical movements are allowed.
- Admissibility: The Manhattan distance heuristic is admissible because it never overestimates the actual cost to reach the goal. It always underestimates or equals the true shortest path distance, as it calculates the distance by moving only along grid lines.
- Consistency: The Manhattan distance heuristic is consistent because it satisfies the triangle inequality property. In other words, the estimated cost from the start node to any successor node plus the estimated cost from that successor node to the goal node is never greater than the estimated cost from the start node directly to the goal node.
- Performance: The Manhattan distance heuristic tends to perform well in tile-based grids or environments where movement is constrained to grid lines. It guides the A* algorithm efficiently towards the goal by considering only horizontal and vertical movements.

*Euclidean Distance Heuristic*:
- Description: The Euclidean distance heuristic calculates the straight-line distance between two nodes on a grid using the Pythagorean theorem. It measures the shortest distance between two points in a straight line, regardless of obstacles or grid lines.
- Admissibility: The Euclidean distance heuristic is admissible because it never overestimates the actual cost to reach the goal. However, it may overestimate the true shortest path distance if obstacles prevent straight-line movement.
- Consistency: The Euclidean distance heuristic is not always consistent because it may violate the triangle inequality property. It can lead to suboptimal paths or even infinite loops in certain cases where the heuristic does not accurately reflect the true cost of movement.
- Performance: The Euclidean distance heuristic can perform well in environments where obstacles are sparse, and the shortest path is relatively unobstructed. However, it may lead to suboptimal paths or inefficiencies when obstacles are present or movement is constrained to grid lines.

When comparing the performance of A* algorithm with different heuristics in a tile graph:
-	The Manhattan distance heuristic tends to perform well in tile-based grids or environments with grid-like movement constraints. It provides accurate estimates of the remaining distance to the goal and guides the search efficiently towards the goal.
-	The Euclidean distance heuristic may perform well in open environments where obstacles are sparse and movement is not constrained to grid lines. However, it may lead to suboptimal paths or inefficiencies in tile-based grids with obstacles or grid-like movement constraints.
  
*Improvements*:
I did the A* search in my own way, not following the pseudo code so I did not do a lot of things correctly:
-	Instead of a linear search, employing a binary search or hash table lookup can significantly improve the efficiency of node retrieval from the open/closed list in pathfinding algorithms.
-	Minimizing the number of nested for loops can enhance the performance and readability of the code, making it more concise and efficient.
-	Incorporating boid-like behavior into pathfinding algorithms can enhance visualization and user engagement, offering a more immersive experience while navigating complex environments.




