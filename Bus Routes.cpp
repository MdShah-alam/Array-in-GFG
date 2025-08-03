#include<bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
{
    if (source == target) return 0;

    unordered_map<int, vector<int>> stopToBuses;

    // Map each stop to the buses that go through it
    for (int bus = 0; bus < routes.size(); ++bus) {
        for (int stop : routes[bus]) {
            stopToBuses[stop].push_back(bus);
        }
    }

    queue<int> q;  // stops to explore
    unordered_set<int> visitedStops;
    unordered_set<int> visitedBuses;

    q.push(source);
    visitedStops.insert(source);

    int busesTaken = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        ++busesTaken;

        for (int i = 0; i < levelSize; ++i) {
            int currStop = q.front();
            q.pop();

            for (int bus : stopToBuses[currStop]) {
                if (visitedBuses.count(bus)) continue;
                visitedBuses.insert(bus);

                for (int nextStop : routes[bus]) {
                    if (nextStop == target) return busesTaken;
                    if (!visitedStops.count(nextStop)) {
                        q.push(nextStop);
                        visitedStops.insert(nextStop);
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    // In the main function
    int n;
    cout << "Enter the number of buses : ";
    cin >> n;
    vector<vector<int>> routes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the number of stops for bus " << i << ": ";
        int numStops;
        cin >> numStops;
        routes[i].resize(numStops);
        cout << "Enter the stops for bus " << i << ": ";
        for (int j = 0; j < numStops; j++) {
            cin >> routes[i][j];
        }
    }

    int source, target;
    cout<<"Enter source : ";
    cin>>source;
    cout<<"Enter target : ";
    cin>>target;

    int result = numBusesToDestination(routes, source, target);
    cout << "Minimum buses needed: " << result << endl;

    return 0;
}

/**

routes = [[1,2,7],[3,6,7]], source = 1, target = 6

routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12

*/

