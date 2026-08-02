class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target)
            return 0;

        unordered_map<int, vector<int>> mp;

        
        for(int i = 0; i < routes.size(); i++)
        {
            for(auto stop : routes[i])
            {
                mp[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visStop;
        vector<bool> visBus(routes.size(), false);

        q.push(source);
        visStop.insert(source);

        int buses = 0;

        while(!q.empty())
        {
            int sz = q.size();
            buses++;

            while(sz--)
            {
                int stop = q.front();
                q.pop();

                for(auto bus : mp[stop])
                {
                    if(visBus[bus])
                        continue;

                    visBus[bus] = true;

                    for(auto nextStop : routes[bus])
                    {
                        if(nextStop == target)
                            return buses;

                        if(visStop.find(nextStop) == visStop.end())
                        {
                            visStop.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};