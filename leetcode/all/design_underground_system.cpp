class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, pair<int, int>> checkOutMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> checkIn = checkInMap[id];
        string route = checkIn.first + "_" + stationName;
        checkOutMap[route].first += t - checkIn.second;
        checkOutMap[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        pair<int, int> checkOut = checkOutMap[route];
        return (double) checkOut.first / checkOut.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
