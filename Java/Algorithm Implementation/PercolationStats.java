public class PercolationStats {
    private static final double CONFIDENCE_95 = 1.96;

    private final int trials;
    private final double[] thresholds;

    public PercolationStats(int n, int t) {
        if (n <= 0 || t <= 0) {
            throw new IllegalArgumentException("N and T must be greater than 0");
        }

        this.trials = t;
        this.thresholds = new double[t];

        for (int trial = 0; trial < t; trial++) {
            Percolation percolation = new Percolation(n);
            int openedSites = 0;

            while (!percolation.percolates()) {
                int row = StdRandom.uniform(n);
                int col = StdRandom.uniform(n);
                if (!percolation.isOpen(row, col)) {
                    percolation.open(row, col);
                    openedSites++;
                }
            }

            thresholds[trial] = (double) openedSites / (n * n);
        }
    }

    public double mean() {
        return StdStats.mean(thresholds);
    }

    public double stddev() {
        if (trials == 1) {
            return Double.NaN;
        }
        return StdStats.stddev(thresholds);
    }

    public double confidenceLow() {
        return mean() - (CONFIDENCE_95 * stddev() / Math.sqrt(trials));
    }

    public double confidenceHigh() {
        return mean() + (CONFIDENCE_95 * stddev() / Math.sqrt(trials));
    }

    private static long usedMemoryBytes() {
        Runtime runtime = Runtime.getRuntime();
        return runtime.totalMemory() - runtime.freeMemory();
    }

    public static void main(String[] args) {
        int n = StdIn.readInt();
        int t = StdIn.readInt();

        System.gc();
        long memoryBefore = usedMemoryBytes();
        Stopwatch timer = new Stopwatch();

        PercolationStats stats = new PercolationStats(n, t);
        long memoryAfter = usedMemoryBytes();

        StdOut.printf("mean                    = %.16f\n", stats.mean());
        StdOut.printf("stddev                  = %.16f\n", stats.stddev());
        StdOut.printf("95%% confidence interval = [%.16f, %.16f]\n", stats.confidenceLow(), stats.confidenceHigh());
        StdOut.printf("elapsed time (s)        = %.6f\n", timer.elapsedTime());
        StdOut.printf("memory used (MB)        = %.3f\n", (memoryAfter - memoryBefore) / (1024.0 * 1024.0));
    }
}
