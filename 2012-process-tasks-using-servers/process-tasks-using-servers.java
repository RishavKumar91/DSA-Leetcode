class Solution {
    record Pair(int weight, int ix) {}
    record Trio(long end, int weight, int ix) {}

    public int[] assignTasks(int[] servers, int[] tasks) {
        PriorityQueue<Pair> free = new PriorityQueue<>((a, b) -> {
            if (a.weight != b.weight)
                return Integer.compare(a.weight, b.weight);
            return Integer.compare(a.ix, b.ix);
        });

        PriorityQueue<Trio> busy = new PriorityQueue<>((a, b) -> {
            int cmp = Long.compare(a.end, b.end);
            if (cmp != 0) return cmp;
            if (a.weight != b.weight)
                return Integer.compare(a.weight, b.weight);
            return Integer.compare(a.ix, b.ix);
        });

        for (int i = 0; i < servers.length; i++)
            free.offer(new Pair(servers[i], i));

        int[] ans = new int[tasks.length];
        // long currTime = 0;

        for (int i = 0; i < tasks.length; i++) {
            long currTime =  i ;

            while (!busy.isEmpty() && busy.peek().end <= currTime) {
                Trio t = busy.poll();
                free.offer(new Pair(t.weight, t.ix));
            }

            if (free.isEmpty()) {
                currTime = busy.peek().end;

                // while (!busy.isEmpty() && busy.peek().end <= currTime) {
                    Trio t = busy.poll();
                    free.offer(new Pair(t.weight, t.ix));
                // }
            }

            Pair p = free.poll();
            ans[i] = p.ix;

            busy.offer(new Trio(currTime + tasks[i], p.weight, p.ix));
        }

        return ans;
    }
}