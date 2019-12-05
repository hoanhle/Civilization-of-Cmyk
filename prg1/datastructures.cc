    // Datastructures.cc

#include "datastructures.hh"

#include <random>

#include <cmath>

#include <algorithm>
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
    // Replace this with your implementation

    for (auto elem : Beacons)
    {
        delete elem.second;
    }
}

int Datastructures::beacon_count()
{
    return static_cast<int>(BeaconID_abc.size());
}

void Datastructures::clear_beacons() // clear all datastructures contains info abt Beacons
{
    Beacons.clear();
    BeaconID_abc.clear();
    BeaconID_brightness.clear();
}

std::vector<BeaconID> Datastructures::all_beacons()
{
    return BeaconID_abc;
}

bool Datastructures::add_beacon(BeaconID id, const std::string& name, Coord xy, Color color)
{
    if (Beacons.find(id) == Beacons.end())
    {
        int brightness = 3 * color.r + 6 * color.g + color.b;
        std::vector<BeaconID> received_lightbeams = {};
        Beacon* new_beacon = new Beacon();
        new_beacon->ID = id;
        new_beacon->coord = xy;
        new_beacon->name = name;
        new_beacon->color = color;
        new_beacon->lightbeam = color; // beacon's lightbeam color
        new_beacon->brightness = brightness;
        new_beacon->sent_lightbeam = "";
        new_beacon->received_lightbeams = received_lightbeams;


        Beacons.insert(std::pair<BeaconID, Beacon*>(id, new_beacon));
        BeaconID_abc.push_back(id);
        BeaconID_brightness.push_back(id);
        alphabetically_sorted = false;
        brightness_sorted = false;

        return true;
    }

    else
    {
        return false;
    }
}

std::string Datastructures::get_name(BeaconID id)
{
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
    if (alphabetically_sorted)
    {
        return BeaconID_abc;
    }

    else
    {
        std::sort(BeaconID_abc.begin(), BeaconID_abc.end(), [this](BeaconID l, BeaconID r)
        {return Beacons.at(l)->name < Beacons.at(r)->name;});
        alphabetically_sorted = true;

        return BeaconID_abc;
    }
}

std::vector<BeaconID> Datastructures::beacons_brightness_increasing()
{   
    if (brightness_sorted)
    {
        return BeaconID_brightness;
    }

    else
    {
        std::sort(BeaconID_brightness.begin(), BeaconID_brightness.end(), [this](BeaconID l, BeaconID r)
        {return Beacons.at(l)->brightness < Beacons.at(r)->brightness;});

        brightness_sorted = true;

        return BeaconID_brightness;
    }
}

BeaconID Datastructures::min_brightness()
{
    if (Beacons.size() == 0)
    {
        return NO_ID;
    }

    else
    {
        std::vector<BeaconID> BeaconIDs;
        if (brightness_sorted)
        {
            return BeaconID_brightness.at(0);
        }

        else
        {
            std::sort(BeaconID_brightness.begin(), BeaconID_brightness.end(), [this](BeaconID l, BeaconID r)
            {return Beacons.at(l)->brightness < Beacons.at(r)->brightness;});

            brightness_sorted = true;

            return BeaconID_brightness.at(0);
        }
    }

}

BeaconID Datastructures::max_brightness()
{
    std::vector<BeaconID> BeaconIDs;

    if (Beacons.size() == 0)
    {
        return NO_ID;
    }

    else
    {
        if (brightness_sorted)
        {
            return BeaconID_brightness.at(BeaconID_brightness.size() - 1);
        }

        else
        {
            std::sort(BeaconID_brightness.begin(), BeaconID_brightness.end(), [this](BeaconID l, BeaconID r)
            {return Beacons.at(l)->brightness < Beacons.at(r)->brightness;});

            brightness_sorted = true;

            return BeaconID_brightness.at(BeaconID_brightness.size() - 1);
        }
    }
}

std::vector<BeaconID> Datastructures::find_beacons(std::string const& name)
{
    std::vector<BeaconID> BeaconIDs;
    for (auto elem : Beacons)
    {
        if (elem.second->name == name)
        {
            BeaconIDs.push_back(elem.first);
        }
    }

    std::sort(BeaconIDs.begin(), BeaconIDs.end());

    return BeaconIDs;
}

bool Datastructures::change_beacon_name(BeaconID id, const std::string& newname)
{
    if (Beacons.find(id) == Beacons.end())
    {
        return false;
    }

    else
    {
        Beacons.find(id)->second->name = newname;
        alphabetically_sorted = false;

        return true;
    }
}

bool Datastructures::change_beacon_color(BeaconID id, Color newcolor)
{
    if (Beacons.find(id) == Beacons.end())
    {
        return false;
    }

    else
    {
        std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);
        beacon_pos->second->color = newcolor;

        int new_brightness = 3 * newcolor.r + 6* newcolor.g + newcolor.b;
        beacon_pos->second->brightness = new_brightness;
        beacon_pos->second->lightbeam = average_color(id);

        BeaconID next_beacon = beacon_pos->second->sent_lightbeam;

        while (next_beacon != "")
        {
            Beacons.at(next_beacon)->lightbeam = average_color(next_beacon);
            next_beacon = Beacons.at(next_beacon)->sent_lightbeam;
        }

        brightness_sorted = false;

        return true;
    }
}

bool Datastructures::add_lightbeam(BeaconID sourceid, BeaconID targetid)
{
    std::unordered_map<BeaconID, Beacon*>::iterator source_pos = Beacons.find(sourceid);
    std::unordered_map<BeaconID, Beacon*>::iterator target_pos = Beacons.find(targetid);

    if (source_pos == Beacons.end()
       or target_pos == Beacons.end()
       or !source_pos->second->sent_lightbeam.empty())
    {
        return false;
    }

    else
    {
        source_pos->second->sent_lightbeam = targetid;
        target_pos->second->received_lightbeams.push_back(sourceid);
        target_pos->second->lightbeam = average_color(targetid);

        return true;
    }
}

std::vector<BeaconID> Datastructures::get_lightsources(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_posi = Beacons.find(id);

    if (beacon_posi == Beacons.end())
    {
        return {{NO_ID}};
    }

    else
    {
        std::sort(beacon_posi->second->received_lightbeams.begin(),
                  beacon_posi->second->received_lightbeams.end());
        return beacon_posi->second->received_lightbeams;
    }
}

std::vector<BeaconID> Datastructures::path_outbeam(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);

    if (beacon_pos == Beacons.end())
    {
        return {{NO_ID}};
    }

    else
    {
        std::vector<BeaconID> Beacons_path;
        Beacons_path.push_back(beacon_pos->first);
        if (beacon_pos->second->sent_lightbeam.size() == 0)
        {
            return Beacons_path;
        }

        else
        {
            // goes to every possible beacons in the beacon's path
            // concept same as single linked list

            while (beacon_pos->second->sent_lightbeam.size() != 0)
            {
                Beacons_path.push_back(beacon_pos->second->sent_lightbeam);
                beacon_pos = Beacons.find(beacon_pos->second->sent_lightbeam);
            }

            return Beacons_path;
        }
    }
}

bool Datastructures::remove_beacon(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);

    if (beacon_pos == Beacons.end())
    {
        return false;
    }

    else
    {
        BeaconID rm_beaconid = beacon_pos->first;
        BeaconID rm_lightbeamid = beacon_pos->second->sent_lightbeam;

        // remove the removed_beaconID in the vector stored in the beacon that
        // the removed_beacon sent lightbeam to
        if (rm_lightbeamid != "")
        {
            std::vector<BeaconID>::iterator rm_lightbeam_pos;
            rm_lightbeam_pos = std::find(Beacons.at(rm_lightbeamid)->received_lightbeams.begin(),
                                         Beacons.at(rm_lightbeamid)->received_lightbeams.end(),
                                         rm_beaconid);
            Beacons.at(rm_lightbeamid)->received_lightbeams.erase(rm_lightbeam_pos);
        }

        // calculate every beacons in the removed_beacon's path
        // goes through every beacons once most
        while (rm_lightbeamid != "")
        {
            Beacons.at(rm_lightbeamid)->lightbeam = average_color(rm_lightbeamid);
            rm_lightbeamid = Beacons.at(rm_lightbeamid)->sent_lightbeam;
        }

        for (auto elem : beacon_pos->second->received_lightbeams)
        {
            Beacons.at(elem)->sent_lightbeam = "";
        }

        Beacons.erase(rm_beaconid);
        BeaconID_abc.erase(find(BeaconID_abc.begin(),
                                BeaconID_abc.end(), id));
        BeaconID_brightness.erase(find(BeaconID_brightness.begin(),
                                BeaconID_brightness.end(), id));



        return true;
    }

}

std::vector<BeaconID> Datastructures::path_inbeam_longest(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);
    if (beacon_pos == Beacons.end())
    {
        return {{NO_ID}};
    }

    else
    {
        return *longest_path(id);
    }
}

std::vector <BeaconID>* Datastructures::longest_path(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);

    std::vector<BeaconID>* longest_paths = nullptr;
    for (auto elem : beacon_pos->second->received_lightbeams)
    {
        std::vector<BeaconID>* path = longest_path(elem);

        if (longest_paths == nullptr or (*path).size() > (*longest_paths).size())
        {
            longest_paths = path;
        }
    }

    if (longest_paths == nullptr)
    {
        longest_paths = new std::vector<BeaconID>();
    }
    (*longest_paths).push_back(id);

    return longest_paths;
}

Color Datastructures::total_color(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);

    if (beacon_pos == Beacons.end())
    {
        return {NO_COLOR};
    }

    else
    {
        return beacon_pos->second->lightbeam;
    }
}

Color Datastructures::average_color(BeaconID id)
{
    std::unordered_map<BeaconID, Beacon*>::iterator beacon_pos = Beacons.find(id);

    int lightbeam_r = beacon_pos->second->color.r;
    int lightbeam_g = beacon_pos->second->color.g;
    int lightbeam_b = beacon_pos->second->color.b;

    for (auto elem : beacon_pos->second->received_lightbeams)
    {
        std::unordered_map<BeaconID, Beacon*>::iterator elem_pos = Beacons.find(elem);
        lightbeam_r += elem_pos->second->lightbeam.r;
        lightbeam_g += elem_pos->second->lightbeam.g;
        lightbeam_b += elem_pos->second->lightbeam.b;
    }

    int num_combined_lightbeams = static_cast<int>(beacon_pos->second->received_lightbeams.size()) + 1;

    lightbeam_r = lightbeam_r/num_combined_lightbeams;
    lightbeam_g = lightbeam_g/num_combined_lightbeams;
    lightbeam_b = lightbeam_b/num_combined_lightbeams;

    return {lightbeam_r, lightbeam_g, lightbeam_b};
}


