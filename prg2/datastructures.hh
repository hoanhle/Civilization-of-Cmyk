// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <unordered_map>
#include <list>
#include <stdio.h>
#include <queue>





// Type for beacon IDs
using BeaconID = std::string;

// Return value for cases where required beacon was not found
BeaconID const NO_ID = "----------";

// Return value for cases where integer values were not found
int const NO_VALUE = std::numeric_limits<int>::min();

// Return value for cases where name values were not found
std::string const NO_NAME = "-- unknown --";

// Type for a coordinate (x, y)
struct Coord
{
    int x = NO_VALUE;
    int y = NO_VALUE;
};

// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary

struct CoordHash
{
    std::size_t operator()(Coord xy) const
    {
        auto hasher = std::hash<int>();
        auto xhash = hasher(xy.x);
        auto yhash = hasher(xy.y);
        // Combine hash values (magic!)
        return xhash ^ (yhash + 0x9e3779b9 + (xhash << 6) + (xhash >> 2));
    }
};

// Example: Defining < for Coord so that it can be used
// as key for std::map/set
inline bool operator<(Coord c1, Coord c2)
{
    if (c1.y < c2.y) { return true; }
    else if (c2.y < c1.y) { return false; }
    else { return c1.x < c2.x; }
}

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for color (RGB)
struct Color
{
    int r = NO_VALUE;
    int g = NO_VALUE;
    int b = NO_VALUE;
};

// Equality and non-equality comparisons for Colors
inline bool operator==(Color c1, Color c2) { return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b; }
inline bool operator!=(Color c1, Color c2) { return !(c1==c2); }

// Return value for cases where color was not found
Color const NO_COLOR = {NO_VALUE, NO_VALUE, NO_VALUE};

// Type for light transmission cost (used only in the second assignment)
using Cost = int;

// Return value for cases where cost is unknown
Cost const NO_COST = NO_VALUE;


// This is the class you are supposed to implement
// Declare xpoint and fibre type

struct xpoint;
struct fibre;

// Type for beacon
struct Beacon
{
    BeaconID ID;
    std::string name;
    Color color;
    Coord coord;
    int brightness;
    std::vector<fibre*> sent_fibres;
};


// Type for xpoint
struct xpoint
{
    Coord location;

};


// Type for fibre
struct fibre
{
    xpoint* xpoint1;
    xpoint* xpoint2;
    Cost cost;
};


// Type for path (used for graph algorithm)
struct path
{
    fibre* way;
    Coord parent;
    int cost;
};

// comparator for min heap
class comparator
{
    public:
    bool operator()(std::pair<int, Coord> l, std::pair<int, Coord> r)
    {
        return l.first > r.first;
    }

};


class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance:
    // Short rationale for estimate:
    int beacon_count();

    // Estimate of performance:
    // Short rationale for estimate:
    void clear_beacons();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> all_beacons();

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_beacon(BeaconID id, std::string const& name, Coord xy, Color color);

    // Estimate of performance:
    // Short rationale for estimate:
    std::string get_name(BeaconID id);

    // Estimate of performance:
    // Short rationale for estimate:
    Coord get_coordinates(BeaconID id);

    // Estimate of performance:
    // Short rationale for estimate:
    Color get_color(BeaconID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> beacons_alphabetically();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> beacons_brightness_increasing();

    // Estimate of performance:
    // Short rationale for estimate:
    BeaconID min_brightness();

    // Estimate of performance:
    // Short rationale for estimate:
    BeaconID max_brightness();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> find_beacons(std::string const& name);

    // Estimate of performance:
    // Short rationale for estimate:
    bool change_beacon_name(BeaconID id, std::string const& newname);

    // Estimate of performance:
    // Short rationale for estimate:
    bool change_beacon_color(BeaconID id, Color newcolor);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_lightbeam(BeaconID sourceid, BeaconID targetid);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> get_lightsources(BeaconID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> path_outbeam(BeaconID id);

    // Non-compulsory operations

    // Estimate of performance:
    // Short rationale for estimate:
    bool remove_beacon(BeaconID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<BeaconID> path_inbeam_longest(BeaconID id);

    // Estimate of performance:
    // Short rationale for estimate:
    Color total_color(BeaconID id);

    // Phase 2 operations

    // Estimate of performance: O(1) if already sorted, otherwise O(nlogn)
    // Short rationale for estimate: sort vector takes O(nlogn), but if it is already sorted
    // return directly
    std::vector<Coord> all_xpoints();

    // Function to check xpoints conditions
    // Estimate for performance: O(n) n->number of fibres
    int check_xpoints_condition(Coord xpoint1, Coord xpoint2);

    // Function to add fibre coords to data structures
    // Estimate for performance: O(1)
    // Short rationale for estimate: push_back element to vector takes constant time
    void add_fibre_coord(Coord xpoint1, Coord xpoint2);

    // Estimate of performance: O(n)
    // Short rationale for estimate: O(1) + O(n) -> O(n)
    bool add_fibre(Coord xpoint1, Coord xpoint2, Cost cost);

    // Estimate of performance: O(n)
    // Short rationale for estimate: searching in unordered_map takes constant time,
    // worst case have to push_back to vector all xpoints and costs
    std::vector<std::pair<Coord, Cost>> get_fibres_from(Coord xpoint);

    // Estimate of performance: O(1) if sorted, O(nlogn) otherwise
    // Short rationale for estimate: return already if the vector is sorted
    // otherwise sorting vector takes O(nlogn) times
    std::vector<std::pair<Coord, Coord>> all_fibres();

    // Estimate of performance: O(n)
    // Short rationale for estimate: erase from vector takes linear time worst
    bool remove_fibre(Coord xpoint1, Coord xpoint2);

    // Estimate of performance: O(n)
    // Short rationale for estimate: erase all element in unordered_map and vector takes constant time
    void clear_fibres();

    // Function breath-first-search
    void BFS(std::list<Coord> *queue, std::unordered_map<Coord, path*, CoordHash>& paths);

    // Function for intersecting path
    Coord isIntersecting(std::unordered_map<Coord, path*, CoordHash>& from_path, std::unordered_map<Coord, path*, CoordHash>& to_path);

    // Estimate of performance: O(b^d/2) which b is branching factor and d is number of xpoints from fromxpoint
    // to toxpoint
    // Short rationale for estimate: using breath first search from both ends, the algorithm ends
    // when they met each other
    std::vector<std::pair<Coord, Cost>> route_any(Coord fromxpoint, Coord toxpoint);

    // Non-compulsory operations
    // Function for BFS for unweighted graph
    bool Unweighted_BFS(std::list<Coord> *queue, std::unordered_map<Coord, path*, CoordHash>& paths, Coord des);

    // Estimate of performance: O(x + f) where x is the number of xpoints and f is the number of fibres
    // Short rationale for estimate: using modified breath_first_search -> going through
    // all xpoints and fibres worst case
    std::vector<std::pair<Coord, Cost>> route_least_xpoints(Coord fromxpoint, Coord toxpoint);


    // Estimate of performance: O(xlogf)
    // Short rationale for estimate: similar to Dijkstra's algorithm (using adjacency list and min heap)
    std::vector<std::pair<Coord, Cost>> route_fastest(Coord fromxpoint, Coord toxpoint);


    // Recursive function to check if the cycle is in the graph
    bool iscyclic(Coord current,
    std::unordered_map<Coord, path *, CoordHash> &paths, Coord parent, Coord& intersect, Coord& intersect_child);

    // Estimate of performance: O(x + f)
    // Short rationale for estimate: going through all the xpoints and all possible fibres connected from one xpoint
    std::vector<Coord> route_fibre_cycle(Coord startxpoint);

    // Function to find root of the current xpoint
    Coord find_root(Coord xpoint, std::unordered_map<Coord, path*, CoordHash> &xpoints_source);

    // Estimate of performance:
    // Short rationale for estimate:
    Cost trim_fibre_network();

private:
    // Data structure to contain info about beacons
    std::unordered_map<BeaconID, Beacon*> Beacons;

    // Data structure to contain info about xpoints
    std::unordered_map<Coord, xpoint*, CoordHash> xpoints;

    // Data structure to contain info about fibres
    std::unordered_map<Coord, std::vector<fibre*>, CoordHash> fibres;


    // Data structure to contain all xpoint coords
    std::vector<Coord> xpoint_coords = {};
    bool xpoints_sorted = false;

    // Data structure to contain all fibres first xpoint and cost
    std::vector<std::pair<Coord, Coord>> fibre_infos;
    bool fibres_sorted = false;



};

#endif // DATASTRUCTURES_HH
