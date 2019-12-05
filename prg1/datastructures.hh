// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <map>
#include <unordered_map>

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

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance: O(1)
    // Short rationale for estimate: calculate size of vector is constant time
    int beacon_count();

    // Estimate of performance: O(n)
    // Short rationale for estimate: destroy map and vector takes linear time
    void clear_beacons();

    // Estimate of performance: O(1)
    // Short rationale for estimate: already have a vector contains all BeaconIDs
    std::vector<BeaconID> all_beacons();

    // Estimate of performance: O(1) average, O(n) worst
    // Short rationale for estimate: unordered_map can be O(n) on inserting, vectors takes constant time
    // for inserting to the end
    bool add_beacon(BeaconID id, std::string const& name, Coord xy, Color color);

    // Estimate of performance: O(1) average, O(n) worst
    // Short rationale for estimate: unorderd_map takes constant time for searching element on average
    std::string get_name(BeaconID id);

    // Estimate of performance: O(1) average, O(n) worst
    // Short rationale for estimate: unorderd_map takes constant time for searching element on average
    Coord get_coordinates(BeaconID id);

    // Estimate of performance: O(1) average, O(n) worst
    // Short rationale for estimate: unorderd_map takes constant time for searching element on average
    Color get_color(BeaconID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(1) if the vector is already sorted, otherwise O(nlogn)
    // Short rationale for estimate: sorting unsorted vector takes O(nlogn)
    std::vector<BeaconID> beacons_alphabetically();

    // Estimate of performance: O(1) if the vector is already sorted, otherwise O(nlogn)
    // Short rationale for estimate: sorting unsorted vector takes O(nlogn)
    std::vector<BeaconID> beacons_brightness_increasing();

    // Estimate of performance: O(1) if the vector is already sorted, otherwise O(nlogn)
    // Short rationale for estimate: sorting vector takes O(nlogn) -> find min element O(nlogn)
    BeaconID min_brightness();

    // Estimate of performance: O(1) if the vector is already sorted, otherwise O(nlogn)
    // Short rationale for estimate: sorting vector takes O(nlogn) -> find max element O(nlogn)
    BeaconID max_brightness();

    // Estimate of performance: O(nlogn)
    // Short rationale for estimate: goes through every element takes O(n) and sorting vectors
    // takes O(nlogn) -> O(nlogn)
    std::vector<BeaconID> find_beacons(std::string const& name);

    // Estimate of performance: O(1) average, O(n) worst
    // Short rationale for estimate: since finding element in unordered map is O(1) on average
    bool change_beacon_name(BeaconID id, std::string const& newname);

    // Estimate of performance: O(n) average
    // Short rationale for estimate: since change one beacon color affect the lightbeam color
    // of all beacons in its path --> goes through all elements worst once
    bool change_beacon_color(BeaconID id, Color newcolor);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(n)
    // Short rationale for estimate: finding Beacons takes O(1) on average, calculating the beacon
    // lightbeam color takes worst O(n)
    bool add_lightbeam(BeaconID sourceid, BeaconID targetid);

    // Estimate of performance: O(1)
    // Short rationale for estimate: finding element in unordered map is O(1) on average
    std::vector<BeaconID> get_lightsources(BeaconID id);

    // Estimate of performance: O(n) average
    // Short rationale for estimate: finding takes O(1) average
    // and worst have to goes through every elements -> n
    std::vector<BeaconID> path_outbeam(BeaconID id);

    // Non-compulsory operations

    // Estimate of performance: O(n)
    // Short rationale for estimate: have to change all of the lightbeam color the removed beacon
    // send lightbeam directly or indirectly
    bool remove_beacon(BeaconID id);

    // Estimate of performance: O(n)
    // Short rationale for estimate: goes through all elements once
    std::vector<BeaconID> path_inbeam_longest(BeaconID id);

    std::vector<BeaconID>* longest_path(BeaconID id); // return pointers to longest_path for given ID

    // Estimate of performance: O(1)
    // Short rationale for estimate: have already done the hard part above, just need to return
    // the beacon lightbeam color
    Color total_color(BeaconID id);

    // calculate beacon's lightbeam color based on its received_lightbeam and itself
    Color average_color(BeaconID id);

private:
    // Add stuff needed for your class implementation here

    // Type for Beacon
    struct Beacon
    {
        BeaconID ID;
        std::string name;
        Color color;
        Color lightbeam;
        Coord coord;
        int brightness;
        std::vector<BeaconID> received_lightbeams;
        BeaconID sent_lightbeam;

    };
    std::unordered_map<BeaconID, Beacon*> Beacons;

    // Data structure for sorting alphabetically purpose
    std::vector<BeaconID> BeaconID_abc;
    bool alphabetically_sorted = false;

    // Data structure for sorting by brightness purpose
    std::vector<BeaconID> BeaconID_brightness;
    bool brightness_sorted = false;
};

#endif // DATASTRUCTURES_HH
