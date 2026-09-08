public class Percolation {
    private int N;
    private boolean[][] grid;
    private WeightedQuickUnionUF uf1, uf2;
    private int top, bottom;
    public Percolation(int N){
        this.N = N;
        if(N<=0){
            throw new java.lang.IllegalArgumentException("N must be greater than 0");
        }
        this.grid = new boolean[N][N];
        this.uf1 = new WeightedQuickUnionUF(N*N+2);
        this.uf2 = new WeightedQuickUnionUF(N*N+1);
        this.top = N * N;
        this.bottom = N * N + 1;
    }
    public void open(int i,int j){
        if(i<0 || i>=N || j<0 || j>=N){
            throw new java.lang.IndexOutOfBoundsException("index out of bounds");
        }
        if(grid[i][j]) return;
        grid[i][j] = true;
        if(i>=1 && isOpen(i-1, j))    {uf1.union(i*N+j, (i-1)*N+j); uf2.union(i*N+j, (i-1)*N+j);}
        if(i<N-1 && isOpen(i+1, j))   {uf1.union(i*N+j, (i+1)*N+j); uf2.union(i*N+j, (i+1)*N+j);}
        if(j>=1 && isOpen(i, j-1))    {uf1.union(i*N+j, i*N+j-1); uf2.union(i*N+j, i*N+j-1);}
        if(j<N-1 && isOpen(i, j+1))   {uf1.union(i*N+j, i*N+j+1); uf2.union(i*N+j, i*N+j+1);}
        if(i==0)                      {uf1.union(i*N+j, top); uf2.union(i*N+j, top);}       
        if(i==N-1)                     uf1.union(i*N+j, bottom);

    }
    public boolean isOpen(int i,int j){
        if(i<0 || i>=N || j<0 || j>=N){
            throw new java.lang.IndexOutOfBoundsException("index out of bounds");
        }
        return grid[i][j];
    }
    public boolean isFull(int i,int j){
        if(i<0 || i>=N || j<0 || j>=N){
            throw new java.lang.IndexOutOfBoundsException("index out of bounds");
        }
        return isOpen(i, j) && uf2.find(i*N+j) == uf2.find(top);
    }
    public boolean percolates(){
        return uf1.find(top) == uf1.find(bottom);
    }
}


