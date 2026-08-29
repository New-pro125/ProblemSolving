class Solution {
    static class UnionFind {
        private Map<Integer, Integer> parent = new HashMap<>();

        public UnionFind(int[] nums) {
            for (int num : nums) {
                this.parent.putIfAbsent(num, num);
            }
        }

        public int find(int x) {
            if (this.parent.get(x) != x) {
                this.parent.put(x, this.find(this.parent.get(x)));
            }
            return this.parent.get(x);
        }

        public void union(int x, int y) {
            int parentX = find(x);
            int parentY = find(y);
            if (parentX != parentY) {
                this.parent.put(parentX, parentY);
            }
        }
    }

    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[] sortedNums = Arrays.copyOf(nums, n);
        Arrays.sort(sortedNums);

        UnionFind uf = new UnionFind(nums);

        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i - 1] <= limit) {
                uf.union(sortedNums[i - 1], sortedNums[i]);
            }
        }

        Map<Integer, PriorityQueue<Integer>> comp = new HashMap<>();
        int[] compOf = new int[n];
        for (int i = 0; i < n; i++) {
            int root = uf.find(nums[i]);
            compOf[i] = root;
            comp.computeIfAbsent(root, k -> new PriorityQueue<>()).add(nums[i]);
        }

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = comp.get(compOf[i]).poll();
        }
        return res;
    }
}