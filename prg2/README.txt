README

1. Data strucutre:
- struct xpoint:
	Coord location

- struct fibre
	Coord xpoint1
	Coord xpoint2
	Cost cost;

-> struct: a good way to store every infomation of fibre
(xpoint 1, xpoint2, cost)

- unordered_map<Coord, xpoint*, CoordHash> xpoints
- unordered_map<Coord, vector<fibre*>> fibres;

Reason
- unordered_map takes constant time to search and insert element on average
  and we have to do these a lot -> save more time than other data structures
- we don't have to use this data structure to be sorted in any case
- store Coord as key so that functions can use Coord of xpoint to search later, value as pointer or vector pointer so that we can access later directly

- vector<Coord> xpoints_coord;
- vector<pair<Coord, Coord> fibre_info;

Reason:
- push_back element takes constant time
- don't have to make a new vector when calling function all_xpoints, all_fibres everything
- sorting easily


- bool fibres_sorted, xpoints_sorted

Reason:
- to know when we need to sort 2 vectors above, if they are already sorted,
do nothing and return directly

struct path:
	Coord parent
	fibre* way
	cost cost

Reason: store infomation for backward search later, cost to count the cost up to the point from source xpoint, pointer to fibre.
-> necessary and makes graph algorithms more efficiently

2. Functions
- all_xpoints, all_fibres
Complexity: O(nlogn) or O(1)
Reason: the vector is sorted if it is not before

- check_xpoints_condition
Content: check the situation to know what we need to add in the data structures
Complexity: O(n)
Reason: searching in unordered_map is constant time, worst case have to go through all fibre 

- add_fibre_coord
Content: add fibre_coord to vector fibre_infos
Complexity: O(1)
Reason: takes constant time at eveything task

- add_fibre
Complexity of total: O(n) (check_xpoints_condition and add_fibre_coord)

- remove_fibre
Complexity: O(n)
Reason: delete from unordered_map average takes constant time, and erase from vector takes linear time

- BFS
Content: breath-first-search

- isIntersecting
Content: check when two paths intersect 

- route_any
Content: similar to bidirectional search
do BFS on both ends 
-> faster than doing BFS on 1 end
Complexity: O(b^d/2) which b is branching factor and d is number of xpoints from fromxpoint

- Unweighted_BFS
Content: Breath_first_search for unweighted_graph

- route_least_xpoints
Complexity: O(x + f) where x is the number of xpoints and f is the number of fibres
Reason: modified version for BFS, have to going every xpoints and fibres worst

- route_fastest
Complexity: O(xlogf)
Reason: similar to Dijkstra's algorithm (using min_heap and adjacency list representation)

- is_cyclic
Content: a recursive function to check if the cycle is in the graph
when a adjacent xpoint is visited but it is not father of the current xpoint

- route_fibre_cycle
Content: going backward from the point makes the cycle
Complexity: O(x + f) where x is the number of xpoints and f is the number of fibres
Reason: have to going through all xpoints and fibres connect from one xpoint worst

- find_root
Content: find the root of the current xpoint

- trim_fibre_network
Content: similar to Kruskal's algorithm
Complexity: O(xlogf)
Note: this algorithm is having some unknown bugs. The reason for it can be that the set all_routes does not work
correctly as I want. I want a set since it doesn't store fibre pointer twice. (there are two similar fibre pointers
in the unordereded_map fibres)


3. Conclusion
All the functions are optimized, and some of them can be really fast


