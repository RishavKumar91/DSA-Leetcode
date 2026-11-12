
class Solution {
    int sgmt[];
    int n;

    // Build segment tree: store index of maximum height
    void build(int[] heights, int i, int l, int r) {
        if(l == r) {
            sgmt[i] = l;
            return;
        }

        int mid = l + (r-l)/2;

        build(heights, 2*i+1, l, mid);
        build(heights, 2*i+2, mid+1, r);

        int left = sgmt[2*i+1];
        int right = sgmt[2*i+2];

        sgmt[i] = heights[left] >= heights[right]
                ? left : right;
    }

    // Find leftmost index >= start with height > threshold
    int find(int ix, int l, int r, int start,
             int threshold, int[] heights) {

        // Outside required range
        if(r < start) return -1;

        // No element in this segment can satisfy condition
        if(heights[sgmt[ix]] <= threshold) return -1;

        // Found the leftmost valid index
        if(l == r) return l;

        int mid = l + (r-l)/2;

        // Search left subtree first
        int left = find(2*ix+1, l, mid, start,
                        threshold, heights);

        if(left != -1) return left;

        // Search right subtree
        return find(2*ix+2, mid+1, r, start,
                    threshold, heights);
    }

    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        n = heights.length;
        sgmt = new int[4*n];

        build(heights, 0, 0, n-1);

        int ans[] = new int[queries.length];
        int i = 0;

        for(int q[] : queries) {
            int lft = Math.min(q[0], q[1]);
            int rgt = Math.max(q[0], q[1]);

            // Directly meeting at right building
            if(lft == rgt || heights[lft] < heights[rgt]) {
                ans[i++] = rgt;
            }
            else {
                ans[i++] = find(0, 0, n-1, rgt+1,
                                heights[lft], heights);
            }
        }

        return ans;
    }
}
