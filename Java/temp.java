public class temp {
    public static void main(String[] args) {
        int[][] matrix = new int[3][3];

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (matrix[i][j] % 3 == 0)
                    System.out.print(matrix[i][j] + " ");
    }

    class Computer {
        private String cpu;
        private int memory, disk;

        Computer(String cpu, int memory, int disk) {
            this.cpu = cpu;
            this.memory = memory;
            this.disk = disk;
        }

        public String getDetails() {
            return "cpu=" + cpu + ",memory=" + memory + ",disk=" + disk;
        }

        public String getCpu() {
            return cpu;
        }

        public int getDisk() {
            return disk;
        }

        public int getMemory() {
            return memory;
        }
    }

    class PC extends Computer {
        private String brand;

        PC(String cpu, int memory, int disk, String brand) {
            super(cpu, memory, disk);
            this.brand = brand;
        }

        public String getBrand() {
            return brand;
        }

        public void setBrand(String brand) {
            this.brand = brand;
        }

        @Override
        public String getDetails() {
            return "cpu=" + getCpu() + ",memory=" + getMemory() + ",disk=" + getDisk() + ",brand=" + brand;
        }
    }
}