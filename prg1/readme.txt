1. Choosing data structure:
- Struct Beacon:
	ID: beacon ID
	name: beacon name
	color: beacon's color
	lightbeam: beacon's lightbeam color
	brightness: beacon's brightness
	coord: beacon's coordinations
	sent_lightbeam: ID of the beacon which is sent lightbeam
	received lightbeam: a vector contains all beacons sent lightbeam to this beacon
	// choosing vector: insert element takes constant time and can return directly 
	// in some functions

-> struct: a good way to store every information of the beacons

- unordered_map<BeaconID, Beacon*> Beacons
Reason:
- unordered_map takes constant time to find and insert element on average
  and we have to do this a lot --> save time than other data structures
- we don't have to use this data structure to be sorted in any case
- store ID as key to so that functions can use ID to search later, and pointer so that we can 
  access to the object directly and fast

- vector<BeaconID> BeaconID_abc and bool alphabetically_sorted
Content: to store BeaconID in the order of their names
Reason:
- insert element in the beginning takes constant time
- sorting takes nlogn if the vector is not sorted, but if the 
  vector is already sorted (known by the boolean alphabetically_sorted)
  -> takes constant time
- don't have to make a new vector when call the function: 
  beacon_alphabetically, all_beacon

- vector<BeaconID>  BeaconID_brightness and bool brightness_sorted
Content: to store BeaconId in the order of their brightness
Reason:
- insert element in the beginning takes constant time
- sorting takes nlogn if the vector is not sorted, but if the 
  vector is already sorted (known by the boolean brightness_sorted)
  -> takes constant time
- don't have to make a new vector when call the function: 
  beacon_brightness_increasing
- can return directly the min_brightness BeaconID and max_brightness BeaconID
as constant time if the vector is already sorted

2. Functions:
- beacon_count:
Time complexity: O(1)
Reason: since calculating vector size is constant

- clear_beacon:
Time complexity: O(n)
Reason: clear each vector/map takes linear time -> O(n)

- add_beacon:
Create a pointer to object beacon and store in unordered_map Beacons
Also store beaconID in two vector BeaconID for sorting purpose
If a beaconID is already there -> return false
Time complexity: O(1) average
Reason: inserting elements to the end of vector or to unordered_map
takes constant time

- get_name, get_coordinate, get_color
Time complexity: O(1)
Reason: finding element in unordered_map is constant on average
-> get pointer -> get to the name, coordinate and color directly

- beacon_alphabetically
Time complexity: O(nlogn), can be constant time
Sorting vector BeaconID_abc and then change the boolean value alphabetically_sorted true;
If it is already sorted, return the vector directly

- beacon_brightness_increase
Time complexity: O(nlogn), can be constant time
Sorting vector BeaconID_brightness and then change the boolean value brightness_sorted true;
If it is already sorted, return the vector directly

- min_brightness
Time complexity: O(nlogn) or O(1)
If the vector BeaconID_brightness is already sorted
--> return the first element in the vector
Else: sort the vector takes O(nlogn) and then return the first element

- max_brightness
Time complexity: O(nlogn) or O(1)
If the vector BeaconID_brightness is already sorted
--> return the last element in the vector
Else: sort the vector takes O(nlogn) and then return the last element

- find_beacons
Time complexity: O(n)
Reason: finding element in unordered_map takes constant time, and we have to goes through all elements

- change_beacon_name:
Time complexity: O(1)
Reason: finding element in unordered_map takes constant time, and use pointer to change the name directly

- change_beacon_color:
Time complexity: O(n)
Reason: worst, have to calculate all element's lightbeam color once (goes through each beacon once)
--> O(n)
finding element in unordered_map Beacons takes constant time, and other works takes also constant time

- add_lightbeam:
Time complexity: O(n)
Reason: worst, have to goes through all element to calculate the lightbeam color of the targetid Beacon
-> O(n)

Adding element to vector received_lightbeam: takes constant time and other works are also constant

- get_lightsources:
Time_complexity: O(nlogn)
Reason: getting element in unordered_map takes constant time, and we have to sort the received_lightbeam vector
-> takes O(nlogn)

- path_outbeam:
Time_complexity: O(n)
Reason: worst, we have to goes through every element in unordered_map Beacons and insert to the vector
-> takes O(n)

- remove_beacon:
Content: 
- delete the beacon's info in all datastructure
- remove the beaconID out of the info in the beacon the removed beacon sent lightbeam to
- change lightbeam color of all beacons in its path
- delete the vector that stores the beacon IDs sent lightbeam to the removed_beacon
Time_complexity: O(n)
- every work takes O(n) on average --> total O(n)

- path_inbeam_longest:
Time_complexity: O(n) // as longest_path takes O(n)
Reason: goes through every beacon at most once

- total_color:
Time_complexity: O(1)
Reason: all the hard work we have already done above, we just need to return the beacon's lightbeam color

3. Conclusion:
All the functions takes at most O(nlogn) on average, and a lot of them can go faster, even take only constant time in many cases.





