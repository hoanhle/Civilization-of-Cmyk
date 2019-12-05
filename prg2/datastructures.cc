// Datastructures.cc

#include "datastructures.hh"

#include <random>

#include <cmath>

#include <algorithm>

#include <queue>

#include <map>

#include <set>


std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Replace this with your implementation
}

Datastructures::~Datastructures()
{
    for (auto& elem : Beacons)
    {
        delete elem.second;
    }

    for (auto& elem : fibres)
    {
        for (auto& fibre_info : elem.second)
        {
            delete fibre_info;
        }
    }

    for (auto& elem : xpoints)
    {
         delete elem.second;
    }
}

int Datastructures::beacon_count()
{
    // Replace this with your implementation
    return NO_VALUE;
}

void Datastructures::clear_beacons()
{
    // Replace this with your implementation

}

std::vector<BeaconID> Datastructures::all_beacons()
{
    // Replace this with your implementation
    return {};
}

bool Datastructures::add_beacon(BeaconID id, const std::string& name, Coord xy, Color color)
{
    // Replace this with your implementation

    if (Beacons.find(id) == Beacons.end())
    {
        int brightness = 3 * color.r + 6 * color.g + color.b;
        std::vector<fibre*> sent_fibres = {};
        Beacon* new_beacon = new Beacon();
        new_beacon->ID = id;
        new_beacon->coord = xy;
        new_beacon->name = name;
        new_beacon->color = color;
        new_beacon->brightness = brightness;
        new_beacon->sent_fibres = sent_fibres;


        Beacons.insert(std::pair<BeaconID, Beacon*>(id, new_beacon));

        return true;
    }

    else
    {
        return false;
    }
}

std::string Datastructures::get_name(BeaconID id)
{
    // Replace this with your implementation
    if (Beacons.find(id) == Beacons.end())
    {
        return NO_NAME;
    }

    else
    {
        return Beacons.find(id)->second->name;
    }
}

Coord Datastructures::get_coordinates(BeaconID id)
{
    if (Beacons.find(id) == Beacons.end())
    {
        return NO_COORD;
    }

    else
    {
        return Beacons.find(id)->second->coord;
    }
}

Color Datastructures::get_color(BeaconID id)
{
    if (Beacons.find(id) == Beacons.end())
    {
        return NO_COLOR;
    }

    else
    {
        return Beacons.find(id)->second->color;
    }
}


std::vector<BeaconID> Datastructures::beacons_alphabetically()
{
    // Replace this with your implementation
    return {};
}

std::vector<BeaconID> Datastructures::beacons_brightness_increasing()
{
    // Replace this with your implementation
    return {};
}

BeaconID Datastructures::min_brightness()
{
    // Replace this with your implementation
    return NO_ID;
}

BeaconID Datastructures::max_brightness()
{
    // Replace this with your implementation
    return NO_ID;
}

std::vector<BeaconID> Datastructures::find_beacons(std::string const& /*name*/)
{
    // Replace this with your implementation
    return {};
}

bool Datastructures::change_beacon_name(BeaconID /*id*/, const std::string& /*newname*/)
{
    // Replace this with your implementation
    return false;
}

bool Datastructures::change_beacon_color(BeaconID /*id*/, Color /*newcolor*/)
{
    // Replace this with your implementation
    return false;
}

bool Datastructures::add_lightbeam(BeaconID /*sourceid*/, BeaconID /*targetid*/)
{
    // Replace this with your implementation
    return false;
}

std::vector<BeaconID> Datastructures::get_lightsources(BeaconID /*id*/)
{
    // Replace this with your implementation
    return {};
}

std::vector<BeaconID> Datastructures::path_outbeam(BeaconID /*id*/)
{
    // Replace this with your implementation
    return {NO_ID};
}

bool Datastructures::remove_beacon(BeaconID /*id*/)
{
    // Replace this with your implementation
    return false;
}

std::vector<BeaconID> Datastructures::path_inbeam_longest(BeaconID /*id*/)
{
    // Replace this with your implementation
    return {NO_ID};
}

Color Datastructures::total_color(BeaconID /*id*/)
{
    // Replace this with your implementation
    return NO_COLOR;
}

std::vector<Coord> Datastructures::all_xpoints()
{
    if ( xpoints_sorted )
    {
        return xpoint_coords;
    }

    else
    {
        std::sort(xpoint_coords.begin(), xpoint_coords.end(), operator<);

        xpoints_sorted = true;

        return xpoint_coords;
    }
}


int Datastructures::check_xpoints_condition(Coord xpoint1, Coord xpoint2)
{
    /* return 0 if 2 xpoints are not existed
     * return 1 if 2 xpoints are already existed but not connected
     * return 2 if 2 xpoints are already connected
     * return 3 if xpoint1 is existed and xpoint2 is not
     * return 4 if xpoint2 is existed and xpoint1 is not
     */

    if ( xpoints.find(xpoint1) == xpoints.end() )
    {
        if ( xpoints.find(xpoint2) == xpoints.end() )
        {
            return 0;
        }

        else
        {
            return 4;
        }
    }

    else if ( xpoints.find(xpoint2) == xpoints.end() )
    {
        if ( xpoints.find(xpoint1) == xpoints.end() )
        {
            return 0;
        }

        else
        {
            return 3;
        }
    }

    else
    {
        if ( fibres.find(xpoint1) != fibres.end() )
        {
            auto& included_fibres = fibres.find(xpoint1)->second;

            // condition to check if 2 xpoints are already connected
            bool xpoint2_existed = false;

            for ( auto& itr : included_fibres )
            {
                if ( itr->xpoint1->location == xpoint1 )
                {
                    if ( itr->xpoint2->location == xpoint2 )
                    {
                        xpoint2_existed = true;
                    }
                }

                else
                {
                    if ( itr->xpoint1->location == xpoint2 )
                    {
                        xpoint2_existed = true;
                    }
                }
            }

            if ( xpoint2_existed )
            {
                return 2;
            }

            else
            {
                return 1;
            }
        }
    }
}

void Datastructures::add_fibre_coord(Coord xpoint1, Coord xpoint2)
{
    if ( operator<(xpoint1, xpoint2) )
    {
        fibre_infos.push_back(std::pair<Coord, Coord>(xpoint1, xpoint2));
        fibres_sorted = false;
    }

    else
    {
        fibre_infos.push_back(std::pair<Coord, Coord>(xpoint2, xpoint1));
        fibres_sorted = false;
    }
}



bool Datastructures::add_fibre(Coord xpoint1, Coord xpoint2, Cost cost)
{
    if ( xpoint1 == xpoint2 )
    {
        return false;
    }

    int xpoints_condition = check_xpoints_condition(xpoint1, xpoint2);

    if ( xpoints_condition == 0 )
    {
        xpoint* new_xpoint1 = new xpoint ();
        xpoint* new_xpoint2 = new xpoint ();

        new_xpoint1->location = xpoint1;
        new_xpoint2->location = xpoint2;

        fibre* new_fibre = new fibre();
        new_fibre->xpoint1 = new_xpoint1;
        new_fibre->xpoint2 = new_xpoint2;
        new_fibre->cost = cost;

        // Adding fibre info to data structures
        std::vector<fibre*> fibre_vector;
        fibre_vector.push_back(new_fibre);

        fibres.insert(std::pair<Coord, std::vector<fibre*>>(xpoint1, fibre_vector));
        fibres.insert(std::pair<Coord, std::vector<fibre*>>(xpoint2, fibre_vector));
        add_fibre_coord(xpoint1, xpoint2);

        // insert new xpoint info to xpoints
        xpoints.insert(std::pair<Coord, xpoint*>(xpoint1, new_xpoint1));
        xpoints.insert(std::pair<Coord, xpoint*>(xpoint2, new_xpoint2));
        xpoint_coords.push_back(xpoint1);
        xpoint_coords.push_back(xpoint2);

        // changing xpoint_coords sorted condition
        xpoints_sorted = false;

        return true;
    }

    else if ( xpoints_condition == 1 )
    {
        fibre* new_fibre = new fibre();
        new_fibre->xpoint1 = xpoints.find(xpoint1)->second;
        new_fibre->xpoint2 = xpoints.find(xpoint2)->second;
        new_fibre->cost = cost;

        // insert fibre info to data structures
        fibres.find(xpoint1)->second.push_back(new_fibre);
        fibres.find(xpoint2)->second.push_back(new_fibre);

        add_fibre_coord(xpoint1, xpoint2);


        return true;
    }

    else if ( xpoints_condition == 2 )
    {
        return false;
    }

    else if ( xpoints_condition == 3 )
    {
        xpoint* new_xpoint2 = new xpoint ();
        new_xpoint2->location = xpoint2;

        fibre* new_fibre = new fibre();
        new_fibre->xpoint1 = xpoints.find(xpoint1)->second;
        new_fibre->xpoint2 = new_xpoint2;
        new_fibre->cost = cost;

        // insert fibre info to fibres
        std::vector<fibre*> fibre_vector;
        fibre_vector.push_back(new_fibre);

        fibres.find(xpoint1)->second.push_back(new_fibre);
        fibres.insert(std::pair<Coord, std::vector<fibre*>>(xpoint2, fibre_vector));
        add_fibre_coord(xpoint1, xpoint2);


        // insert new xpoint info to xpoints
        xpoints.insert(std::pair<Coord, xpoint*>(xpoint2, new_xpoint2));
        xpoint_coords.push_back(xpoint2);

        // changing xpoint_coords sorted condition
        xpoints_sorted = false;

        return true;
    }

    else if ( xpoints_condition == 4 )
    {
        xpoint* new_xpoint1 = new xpoint ();
        new_xpoint1->location = xpoint1;

        fibre* new_fibre = new fibre();
        new_fibre->xpoint2 = xpoints.find(xpoint2)->second;
        new_fibre->xpoint1 = new_xpoint1;
        new_fibre->cost = cost;

        // insert fibre info to fibres
        std::vector<fibre*> fibre_vector;
        fibre_vector.push_back(new_fibre);

        fibres.find(xpoint2)->second.push_back(new_fibre);
        fibres.insert(std::pair<Coord, std::vector<fibre*>>(xpoint1, fibre_vector));
        add_fibre_coord(xpoint1, xpoint2);



        // insert new xpoint info to xpoints
        xpoints.insert(std::pair<Coord, xpoint*>(xpoint1, new_xpoint1));
        xpoint_coords.push_back(xpoint1);


        // changing xpoint_coords sorted condition
        xpoints_sorted = false;

        return true;
    }
}

std::vector<std::pair<Coord, Cost> > Datastructures::get_fibres_from(Coord xpoint)
{
    if ( fibres.find(xpoint) == fibres.end() )
    {
        return {};
    }

    else
    {
        std::vector<std::pair<Coord, Cost>> fibres_from;

        auto included_fibres  = fibres.find(xpoint);

        for ( auto& fibre : included_fibres->second )
        {
            if ( fibre->xpoint1->location == xpoint )
            {
                fibres_from.push_back(
                std::pair<Coord, Cost>(fibre->xpoint2->location, fibre->cost));
            }

            else
            {
                fibres_from.push_back(
                std::pair<Coord, Cost>(fibre->xpoint1->location, fibre->cost));
            }
        }

        std::sort(fibres_from.begin(), fibres_from.end(),
                  [](std::pair<Coord, Cost> a, std::pair<Coord, Cost> b)
        {
            return operator<(a.first, b.first);
        });

        return fibres_from;
    }

}

std::vector<std::pair<Coord, Coord> > Datastructures::all_fibres()
{
    if ( fibres_sorted )
    {
        return fibre_infos;
    }

    else
    {
        std::sort(fibre_infos.begin(), fibre_infos.end(),
                  [](std::pair<Coord, Coord> a, std::pair<Coord, Coord> b)
        {
            if ( a.first == b.first )
            {
                return operator<(a.second, b.second);
            }

            else
            {
                return operator<(a.first, b.first);
            }
        });

        fibres_sorted = true;
        return fibre_infos;
    }
}

bool Datastructures::remove_fibre(Coord xpoint1, Coord xpoint2)
{
    bool fibre_existed = false;

    if ( fibres.find(xpoint1) != fibres.end() and
         fibres.find(xpoint2) != fibres.end() )
    {
        auto& fibres_1 = fibres.find(xpoint1)->second;

        for ( std::vector<fibre*>::size_type i = 0; i < fibres_1.size(); ++i )
        {
            if ( fibres_1[i]->xpoint1->location == xpoint1
                 and fibres_1[i]->xpoint2->location == xpoint2)
            {
                fibres_1.erase(fibres_1.begin() + i);
                fibre_existed = true;
                break;
            }

            else if ( fibres_1[i]->xpoint1->location == xpoint2
                      and fibres_1[i]->xpoint2->location == xpoint1)
            {
                fibres_1.erase(fibres_1.begin() + i);
                fibre_existed = true;
                break;
            }
        }

        auto& fibres_2 = fibres.find(xpoint2)->second;


        for ( std::vector<fibre*>::size_type i = 0; i < fibres_2.size(); ++i )
        {
            if ( fibres_2[i]->xpoint1->location == xpoint1
                 and fibres_2[i]->xpoint2->location == xpoint2)
            {
                fibres_2.erase(fibres_2.begin() + i);
                fibre_existed = true;
                break;
            }

            else if ( fibres_2[i]->xpoint1->location == xpoint2
                      and fibres_2[i]->xpoint2->location == xpoint1)
            {
                fibres_2.erase(fibres_2.begin() + i);
                fibre_existed = true;
                break;
            }
        }
    }


    if ( fibre_existed )
    {
        if ( operator<(xpoint1, xpoint2) )
        {
            fibre_infos.erase(find(
                  fibre_infos.begin(), fibre_infos.end(), std::pair<Coord, Coord>(xpoint1, xpoint2)));
        }

        else
        {
            fibre_infos.erase(find(
                  fibre_infos.begin(), fibre_infos.end(), std::pair<Coord, Coord>(xpoint2, xpoint1)));
        }
    }

    return fibre_existed;
}

void Datastructures::clear_fibres()
{
    fibres.clear();
    fibre_infos.clear();
    xpoint_coords.clear();
    xpoints.clear();
}

void Datastructures::BFS(std::list<Coord> *queue, std::unordered_map<Coord, path *, CoordHash> &paths)
{
    Coord current = queue->front();
    queue->pop_front();

    for ( auto& elem : fibres.find(current)->second )
    {
        if ( elem->xpoint1->location == current )
        {
            if ( paths.find(elem->xpoint2->location) == paths.end() )
            {
                path* current_path = new path();
                current_path->way = elem;
                current_path->parent = current;

                paths.insert(std::pair<Coord, path*>(elem->xpoint2->location, current_path));


                queue->push_back(elem->xpoint2->location);
            }

        }

        if ( elem->xpoint2->location == current )
        {
            if ( paths.find(elem->xpoint1->location) == paths.end() )
            {
                path* current_path = new path();
                current_path->way = elem;
                current_path->parent = current;

                paths.insert(std::pair<Coord, path*>(elem->xpoint1->location, current_path));
                queue->push_back(elem->xpoint1->location);
            }

        }
    }

}

Coord Datastructures::isIntersecting(std::unordered_map<Coord, path*, CoordHash> &from_path, std::unordered_map<Coord, path *, CoordHash> &to_path)
{
    for ( auto& elem : from_path )
    {
        if ( to_path.find(elem.first) != to_path.end() )
        {
            return elem.first;
        }
    }

    return NO_COORD;
}


std::vector<std::pair<Coord, Cost> > Datastructures::route_any(Coord fromxpoint, Coord toxpoint)
{
    // Return value
    std::vector<std::pair<Coord, Cost>> return_route = {};

    if ( fibres.find(fromxpoint) != fibres.end() and
         fibres.find(toxpoint) != fibres.end() )
    {
        // Data structure for searching backward later
        // and if an xpoint is visited
        std::unordered_map<Coord, path*, CoordHash> from_path;
        std::unordered_map<Coord, path*, CoordHash> to_path;

        // Mark fromxpoint and toxpoint are visited
        path* source = nullptr;
        from_path.insert(std::pair<Coord, path*>(fromxpoint, source));
        to_path.insert(std::pair<Coord, path*>(toxpoint, source));


        std::list<Coord> from_queue;
        std::list<Coord> to_queue;

        from_queue.push_back(fromxpoint);
        to_queue.push_back(toxpoint);

        while ( !from_queue.empty() && !to_queue.empty() )
        {
            BFS(&from_queue, from_path);
            BFS(&to_queue, to_path);

            Coord intersect_xpoint = isIntersecting(from_path, to_path);


            if ( intersect_xpoint != NO_COORD )
            {
                // vector contains the path and the cost to go from previous point
                // to a next point
                std::vector<std::pair<Coord, Cost>> path_vector;

                Coord current_coord_1 = intersect_xpoint;

                while ( current_coord_1 != fromxpoint )
                {
                    path_vector.push_back(
                    std::pair<Coord, Cost>(current_coord_1, from_path.find(current_coord_1)->second->way->cost));

                    current_coord_1 = from_path.find(current_coord_1)->second->parent;
                }

                path_vector.push_back(
                std::pair<Coord, Cost>(fromxpoint, 0));

                std::reverse(path_vector.begin(), path_vector.end());

                Coord current_coord_2 = intersect_xpoint;

                while ( current_coord_2 != toxpoint )
                {
                    Coord parent = to_path.find(current_coord_2)->second->parent;
                    path_vector.push_back(
                    std::pair<Coord, Cost>(parent, to_path.find(current_coord_2)->second->way->cost));

                    current_coord_2 = to_path.find(current_coord_2)->second->parent;
                }

                int current_cost = 0;


                for ( auto elem  : path_vector )
                {
                    current_cost += elem.second;
                    return_route.push_back(std::pair<Coord, Cost>(elem.first, current_cost));
                }


                return return_route;

            }
        }
    }


    return return_route;
}

bool Datastructures::Unweighted_BFS(
        std::list<Coord> *queue, std::unordered_map<Coord, path *, CoordHash> &paths, Coord des)
{
    while ( !queue->empty() )
    {
        Coord current  = queue->front();
        queue->pop_front();

        for ( auto& elem : fibres.find(current)->second )
        {
            if ( elem->xpoint1->location == current )
            {
                if ( paths.find(elem->xpoint2->location) ==
                     paths.end() )
                {
                    path* new_path = new path();
                    new_path->way = elem;
                    new_path->parent = current;
                    new_path->cost = paths.find(current)->second->cost +
                            elem->cost;

                    paths.insert(std::pair<Coord, path*>(elem->xpoint2->location, new_path));
                    queue->push_back(elem->xpoint2->location);

                    if ( elem->xpoint2->location == des)
                    {
                        return true;
                    }
                }
            }

            if ( elem->xpoint2->location == current )
            {
                if ( paths.find(elem->xpoint1->location) ==
                     paths.end() )
                {
                    path* new_path = new path();
                    new_path->way = elem;
                    new_path->parent = current;
                    new_path->cost = paths.find(current)->second->cost + elem->cost;

                    paths.insert(std::pair<Coord, path*>(elem->xpoint1->location, new_path));

                    queue->push_back(elem->xpoint1->location);

                    if ( elem->xpoint1->location == des)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

std::vector<std::pair<Coord, Cost>> Datastructures::route_least_xpoints(Coord fromxpoint, Coord toxpoint)
{
    // Return vector
    std::vector<std::pair<Coord, Cost>> fastest_path = {};

    // Data structure to search if a coord is visited or not
    // and also xpoints_cost to that coord and
    // previous coord

    if ( fibres.find(fromxpoint) != fibres.end() and
         fibres.find(toxpoint) != fibres.end() )
    {
        std::unordered_map<Coord, path*, CoordHash> from_path;

        path* source = new path();
        source->parent = NO_COORD;
        source->cost = 0;

        from_path.insert(std::pair<Coord, path*>(fromxpoint, source));

        std::list<Coord> from_queue;

        from_queue.push_back(fromxpoint);


        if ( Unweighted_BFS(&from_queue, from_path, toxpoint) )
        {
            Coord current = toxpoint;

            while ( from_path.find(current)->second->parent != NO_COORD )
            {
                fastest_path.push_back(std::pair<Coord, Cost>(current, from_path.find(current)->second->cost));
                current =  from_path.find(current)->second->parent;
            }

            fastest_path.push_back(std::pair<Coord, Cost>(fromxpoint, 0));

            std::reverse(fastest_path.begin(), fastest_path.end());
        }
    }

    return fastest_path;
}


std::vector<std::pair<Coord, Cost>> Datastructures::route_fastest(Coord fromxpoint, Coord toxpoint)
{
    std::vector<std::pair<Coord, Cost>> return_route = {};

    if ( fibres.find(fromxpoint) != fibres.end() and
         fibres.find(toxpoint) != fibres.end() )
    {
        std::unordered_map<Coord, path*, CoordHash> from_path;

        path* source = new path();
        source->parent = NO_COORD;
        source->cost = 0;

        from_path.insert(std::pair<Coord, path*>(fromxpoint, source));


        // data structure for min heap
        std::priority_queue<std::pair<int, Coord>, std::vector<std::pair<int, Coord>>, comparator> from_queue;
        from_queue.push(std::pair<int, Coord>(0, fromxpoint));


        while ( !from_queue.empty() )
        {
            Coord current  = from_queue.top().second;
            from_queue.pop();

            for ( auto& fibre : fibres.find(current)->second )
            {
                if ( fibre->xpoint1->location == current )
                {
                    if ( from_path.find(fibre->xpoint2->location) == from_path.end() )
                    {
                        path* new_path = new path();
                        new_path->way = fibre;
                        new_path->parent = current;
                        new_path->cost = from_path.find(current)->second->cost +
                                fibre->cost;

                        from_path.insert(std::pair<Coord, path*>(fibre->xpoint2->location, new_path));

                        // break if we find the shortest path to destination
                        if ( fibre->xpoint2->location == toxpoint )
                        {
                            break;
                        }
                        from_queue.push(std::pair<int, Coord>(new_path->cost, fibre->xpoint2->location));
                    }

                    else
                    {
                        Cost current_cost = from_path.find(current)->second->cost + fibre->cost;
                        auto elem = from_path.find(fibre->xpoint2->location);
                        if ( elem->second->cost > current_cost )
                        {
                            elem->second->parent = current;
                            elem->second->cost = current_cost;
                        }

                        if ( fibre->xpoint2->location == toxpoint )
                        {
                            break;
                        }

                    }
                }

                if ( fibre->xpoint2->location == current )
                {
                    if ( from_path.find(fibre->xpoint1->location) == from_path.end() )
                    {
                        path* new_path = new path();
                        new_path->way = fibre;
                        new_path->parent = current;
                        new_path->cost = from_path.find(current)->second->cost +
                                fibre->cost;

                        from_path.insert(std::pair<Coord, path*>(fibre->xpoint1->location, new_path));

                        // break if we find the shortest path to destination
                        if ( fibre->xpoint1->location == toxpoint )
                        {
                            break;
                        }
                        from_queue.push(std::pair<int, Coord>(new_path->cost, fibre->xpoint1->location));
                    }

                    else
                    {
                        Cost current_cost = from_path.find(current)->second->cost + fibre->cost;
                        auto elem = from_path.find(fibre->xpoint1->location);

                        if ( elem->second->cost > current_cost )
                        {
                            elem->second->parent = current;
                            elem->second->cost = current_cost;
                        }

                        if ( fibre->xpoint1->location == toxpoint )
                        {
                            break;
                        }

                    }
                }              
            }
        }

        if ( from_path.find(toxpoint) != from_path.end() )
        {
            Coord current = toxpoint;

            while ( current != fromxpoint )
            {
                auto current_pos = from_path.find(current);
                return_route.push_back(std::pair<Coord, Cost>(current_pos->first, current_pos->second->cost));
                current = current_pos->second->parent;
            }

            return_route.push_back(std::pair<Coord, Cost>(fromxpoint, 0));

            std::reverse(return_route.begin(), return_route.end());
        }
    }


    return return_route;
}

bool Datastructures::iscyclic(
   Coord current, std::unordered_map<Coord, path *, CoordHash> &paths, Coord parent, Coord& intersect, Coord& intersect_child)
{
    // current xpoint is not visited
    if ( paths.find(current) == paths.end() )
    {
        path* new_path  = new path();
        new_path->parent = parent;
        paths.insert(std::pair<Coord, path*>(current, new_path));

        for ( auto& elem : fibres.find(current)->second )
        {
            if ( elem->xpoint1->location == current )
            {
                if ( paths.find(elem->xpoint2->location) ==
                     paths.end())
                {
                    if (iscyclic(elem->xpoint2->location, paths, current, intersect, intersect_child))
                    {
                        return true;
                    }
                }

                else if ( elem->xpoint2->location != parent )
                {
                   intersect = current;
                   intersect_child = elem->xpoint2->location;
                    return true;
                }
            }


            else if ( elem->xpoint2->location == current )
            {
                if ( paths.find(elem->xpoint1->location) ==
                     paths.end())
                {
                    if (iscyclic(elem->xpoint1->location, paths, current, intersect, intersect_child))
                    {
                        return true;
                    }
                }

                else if ( elem->xpoint1->location != parent )
                {
                    intersect = current;
                    intersect_child = elem->xpoint1->location;
                    return true;
                }
            }
        }

        return false;

    }


    return false;

}

std::vector<Coord> Datastructures::route_fibre_cycle(Coord startxpoint)
{
    std::vector<Coord> cycle = {};

    if ( fibres.find(startxpoint) != fibres.end() )
    {
        std::unordered_map<Coord, path*, CoordHash> start_path;

        Coord intersect  = NO_COORD;
        Coord intersect_child = NO_COORD;

        if ( iscyclic(startxpoint, start_path, NO_COORD, intersect, intersect_child) )
        {
            Coord current = intersect;
            cycle.push_back(intersect_child);

            while ( current != intersect_child )
            {
                cycle.push_back(current);
                current = start_path.find(current)->second->parent;
            }

            cycle.push_back(intersect_child);

        }

    }

    return cycle;
}

Coord Datastructures::find_root(Coord xpoint, std::unordered_map<Coord, path*, CoordHash> &xpoints_source)
{
    Coord root = NO_COORD;
    bool finished = false;
    Coord current = xpoint;
    while ( !finished )
    {
        Coord parent = xpoints_source.find(current)->second->parent;
        if ( parent == current )
        {
            root = parent;
            finished = true;
        }

        else
        {
            current = parent;
        }
    }

    return root;
}


Cost Datastructures::trim_fibre_network()
{
    // Data structure for sorting fibres based on cost
    std::vector<std::pair<Cost, fibre*>> undeleted_route = {};
    std::set<std::pair<fibre*, Cost>> all_routes;

    for ( auto& elem : fibres )
    {
        for ( auto& fibre_info : elem.second )
        {
            all_routes.insert(std::pair<fibre*, Cost>(fibre_info, fibre_info->cost));
        }
    }

    for ( auto& elem : all_routes )
    {
        undeleted_route.push_back(std::pair<Cost, fibre*>(elem.second, elem.first));
    }

    std::sort(undeleted_route.begin(), undeleted_route.end(), [](
              std::pair<Cost, fibre*> l , std::pair<Cost, fibre*> r)
    {
        return l.first < r.first;
    });

    std::unordered_map<Coord, path*, CoordHash> xpoints_source;

    for ( auto& elem : xpoint_coords )
    {
        path* new_path = new path();
        new_path->parent = elem;
        new_path->cost = -1;
        xpoints_source.insert(std::pair<Coord, path*>(elem, new_path));
    }

    Cost total_cost = 0;


    for ( auto& elem : undeleted_route )
    {
        Coord& xpoint1 = elem.second->xpoint1->location;
        Coord& xpoint2 = elem.second->xpoint2->location;

        Coord root_1 = find_root(xpoint1, xpoints_source);
        Coord root_2 = find_root(xpoint2, xpoints_source);

        // condition if there is a cycle in the graph
        if ( root_1 == root_2 )
        {
            remove_fibre(xpoint1, xpoint2);
        }

        else
        {
            if ( xpoints_source.find(root_1)->second->cost < xpoints_source.find(root_2)->second->cost )
            {
                xpoints_source.find(xpoint2)->second->parent = root_1;
                xpoints_source.find(root_1)->second->cost -= 1;
            }

            else
            {
                xpoints_source.find(xpoint1)->second->parent = root_2;
                xpoints_source.find(root_2)->second->cost -= 1;

            }
            total_cost += elem.first;
        }
    }


    return total_cost;
}
