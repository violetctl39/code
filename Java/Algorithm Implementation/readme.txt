Percolation Submission Notes

Submitted files:
- Percolation.java
- PercolationStats.java

Notes:
- Percolation.java uses WeightedQuickUnionUF.
- PercolationStats.java uses Stopwatch to measure total running time.
- Allowed libraries: java.lang, stdlib.jar, QuickFindUF.java, WeightedQuickUnionUF.java.

1. Running-time analysis

1. Quick-Find version

If Percolation is implemented with Quick-Find, union scans the entire id array. The union-find structure has size proportional to the number of sites, which is N^2, so one union costs Θ(N^2).
One percolation trial performs about Θ(N^2) open / union-related operations, so the running time for one trial is approximately Θ(N^4).

PercolationStats repeats the trial T times, so the total running time is:
T(N, T) ~ T N^4

Conclusion:
- Doubling N increases the running time by about 16x.
- Doubling T doubles the total running time.

2. Weighted Quick-Union version

With WeightedQuickUnionUF, the cost of find / union is much smaller. One trial still processes about Θ(N^2) sites, so the time per trial is approximately Θ(N^2).
Repeating the trial T times gives:
T(N, T) ~ T N^2

Conclusion:
- Doubling N increases the running time by about 4x.
- Doubling T doubles the total running time.

2. 64-bit memory-cost model

Below is the total memory used by one Percolation object, including the grid and all union-find data structures.

1. Quick-Find version

Percolation contains:
- one boolean[N][N] grid
- two QuickFindUF objects
- several int and reference fields

Grid memory:
- top-level array: 24 + 8N bytes
- N subarrays, each about 24 + N bytes
- total about N^2 + 32N + 24 bytes

Two QuickFindUF objects:
- each object stores one int[] id array
- each id array has length about N^2 + constant
- two id arrays together use about 8N^2 bytes

Therefore the total memory usage is:
M_QF(N) ~ 9N^2 + 32N + O(1) bytes

Using tilde notation:
M_QF(N) ~ 9N^2 bytes

2. Weighted Quick-Union version

Percolation contains:
- one boolean[N][N] grid
- two WeightedQuickUnionUF objects
- several int and reference fields

Grid memory:
- still about N^2 + 32N + 24 bytes

Two WeightedQuickUnionUF objects:
- each object stores parent[] and size[]
- each array has length about N^2 + constant
- four int arrays together use about 16N^2 bytes

Therefore the total memory usage is:
M_WQU(N) ~ 17N^2 + 32N + O(1) bytes

Using tilde notation:
M_WQU(N) ~ 17N^2 bytes

3. Final answers

- Quick-Find:
  - total running time: T(N, T) ~ T N^4
  - total memory: M_QF(N) ~ 9N^2 bytes

- Weighted Quick-Union:
  - total running time: T(N, T) ~ T N^2
  - total memory: M_WQU(N) ~ 17N^2 bytes

Conclusion: Weighted Quick-Union is much faster than Quick-Find. Although it uses a larger constant factor in space because of the extra size[] array, the total memory is still Θ(N^2).
