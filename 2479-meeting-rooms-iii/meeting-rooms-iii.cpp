class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        priority_queue<int, vector<int>, greater<int>> free;

        for(int i = 0; i < n; i++)
            free.push(i);

        vector<int> count(n, 0);

        for(auto &v : meetings) {

            while(!pq.empty() && pq.top().first <= v[0]) {
                auto [last, room] = pq.top();
                free.push(room);
                pq.pop();
            }

            int room;

            if(!free.empty()) {
                room = free.top();
                free.pop();

                pq.push({v[1], room});
            }
            else {
                auto [last, r] = pq.top();
                pq.pop();

                room = r;
                pq.push({last + (v[1] - v[0]), room});
            }

            count[room]++;   // ⭐ yahan
        }

        int ans = 0;

        for(int i = 1; i < n; i++) {
            if(count[i] > count[ans])
                ans = i;
        }

        return ans;
    }
};