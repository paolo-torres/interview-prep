// Remove check in data after check out, optimizes space, consider NYC
// Saving total vs avg time, less rounding errors vs can store more data

// Time: O(1)
// Space: O(m + n^2) -> m = max # of ppl at once, n = # of stations

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // lookup check in station & check in time for this id
        pair<string, int> checkIn = checkInMap[id];
        string startStation = checkIn.first;
        int checkInTime = checkIn.second;
        
        // lookup current travel time for this route
        string routeKey = startStation + "_" + stationName;
        pair<double, double> routeValue = {0.0, 0.0};
        if (checkOutMap.find(routeKey) != checkOutMap.end()) {
            routeValue = checkOutMap[routeKey];
        }
        double totalTripTime = routeValue.first;
        int totalTrips = routeValue.second;
        
        // update travel time data with this trip
        double tripTime = t - checkInTime;
        checkOutMap[routeKey] = {totalTripTime + tripTime, totalTrips + 1};
        
        // remove check in data for this id
        checkInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        // lookup how many times this route was taken & total time
        string routeKey = startStation + "_" + endStation;
        pair<int, int> routeValue = checkOutMap[routeKey];
        double totalTime = routeValue.first;
        double totalTrips = routeValue.second;
        
        // average is simply total divided by number of trips
        return totalTime / totalTrips;
    }
private:
    // id -> {startStation, checkInTime}
    unordered_map<int, pair<string, int>> checkInMap;
    // startStation, endStation -> {total, count}
    unordered_map<string, pair<double, int>> checkOutMap;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
