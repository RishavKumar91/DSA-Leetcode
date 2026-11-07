class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {

        PriorityQueue<int[]> free = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        PriorityQueue<long[]> busy = new PriorityQueue<>((a, b) -> {
            int cmp = Long.compare(a[0], b[0]);
            if (cmp != 0) return cmp;

            cmp = Long.compare(a[1], b[1]);
            if (cmp != 0) return cmp;

            return Long.compare(a[2], b[2]);
        });

        for (int i = 0; i < servers.length; i++) {
            free.offer(new int[]{servers[i], i});
        }

        int[] ans = new int[tasks.length];
        long currTime = 0;

        for (int i = 0; i < tasks.length; i++) {
            currTime = Math.max(currTime, i);

            while (!busy.isEmpty() && busy.peek()[0] <= currTime) {
                long[] t = busy.poll();
                free.offer(new int[]{(int)t[1], (int)t[2]});
            }

            if (free.isEmpty()) {
                currTime = busy.peek()[0];

                while (!busy.isEmpty() && busy.peek()[0] <= currTime) {
                    long[] t = busy.poll();
                    free.offer(new int[]{(int)t[1], (int)t[2]});
                }
            }

            int[] p = free.poll();
            ans[i] = p[1];

            busy.offer(new long[]{currTime + tasks[i], p[0], p[1]});
        }

        return ans;
    }
}