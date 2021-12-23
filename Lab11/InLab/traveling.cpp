/**
 * Ryan Grayson
 * rtg5xkh
 * InLab 11
 * traveling.cpp
 * 5/1/2021
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    string home = dests[0];
    dests.erase(dests.begin());
    
    std::sort(dests.begin(), dests.end());
    vector<string> shortest(dests.size());
    for(int i = 0; i < dests.size(); i++)
      shortest[i] = dests[i];

    int i = 0;
    float d;
    float min = computeDistance(me, home, dests);
    int perms = 0;
    
    while(std::next_permutation(dests.begin(), dests.end())){
      i++;
      d = computeDistance(me, home, dests);
      if (d < min){
	min = d;
	perms = i;
      }
    }

    for(int i = 0; i < perms; i++){
      std::next_permutation(shortest.begin(), shortest.end());
    }

    cout << "Minimum path has Distance " << min << ": ";
    printRoute(home, shortest);
    
    return 0;
}

/**
 * This method computes the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 *
 * @param me A MiddleEarth object representing the cities and distances in the world
 * @param start The starting location of the journey
 * @param dests a list of the destinations of the trip, in order
 *
 * @return the total distance
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float dist = 0;
  dist += me.getDistance(start, dests[0]);
  
  for(int i = 0; i < dests.size() - 1; i++){
    dist += me.getDistance(dests[i], dests[i + 1]);
  }

  dist += me.getDistance(dests[dests.size() - 1], start);
  return dist;
}

/**
 * This method prints the entire route, starting and ending at the
 * 'start' parameter. It will separate each location with '->'
 *
 * @param start The starting location of the route
 * @param dests a list of the destinations of the trip, in order
 */ 
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout << start << " -> ";
  for(int i = 0; i < dests.size(); i++)
    cout << dests[i] << " -> ";

  cout << start << endl;
}
