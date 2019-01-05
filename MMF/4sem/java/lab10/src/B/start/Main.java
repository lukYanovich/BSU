package B.start;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("введите радиус круга: ");
        int n = scanner.nextInt();
        String file = "C:\\Projects\\MMF\\4sem\\java\\lab10\\src\\B\\resources\\output.txt";
        task(n, file);
    }


    private static void task(int radius, String filename) {
        // creating the coordinate grid; center of the circle is in the center of the grid
        Cell[][] matrix = new Cell[radius * 2][radius * 2];
        // creating the queue for sorting cells by their distance from the center
        PriorityQueue<Cell> myQueue = new PriorityQueue<>();
        // filling the grid with Cell objects which carry the "proper" coordinates
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                int x, y;

                boolean insideCircle = false;
                if (i < radius && j < radius) {
                    x = i - radius;
                    y = radius - j;
                    if ((Math.abs(x) < radius && Math.abs(y) < radius) && (i + j + 2) > radius) insideCircle = true;
                } else if (i < radius && j >= radius) {
                    x = i - radius;
                    y = radius - j - 1;
                    if ((Math.abs(x) < radius && Math.abs(y) < radius) && ((2 * radius - j) + i + 1) > radius)
                        insideCircle = true;
                } else if (i >= radius && j < radius) {
                    x = i - radius + 1;
                    y = radius - j;
                    if ((Math.abs(x) < radius && Math.abs(y) < radius) && ((2 * radius - i) + j + 1) > radius)
                        insideCircle = true;
                } else {
                    x = i - radius + 1;
                    y = radius - j - 1;
                    if ((Math.abs(x) < radius && Math.abs(y) < radius) && ((2 * radius - i) + (2 * radius - j)) > radius)
                        insideCircle = true;
                }
                Cell cell = new Cell(x, y);
                if (insideCircle) myQueue.offer(cell);
                matrix[i][j] = cell;
            }
        }
        Cell cell;
        try (BufferedWriter fileWriter = new BufferedWriter(new FileWriter(filename))) {
            while ((cell = myQueue.poll()) != null) {
                fileWriter.write(cell.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static class Cell implements Comparable {
        private final int x;
        private final int y;

        private Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + "; " + y + ")";
        }

        public boolean equals(Object o) {
            if (!(o instanceof Cell)) return false;
            Cell other = (Cell) o;
            return (other.x == this.x) && (other.y == this.y);
        }

        public int hashCode() {
            return (30 + x) * 5 + (20 + y) * 11;
        }

        @Override
        public int compareTo(Object o) {
            Cell other = (Cell) o;
            return (Math.abs(this.x) + Math.abs(this.y)) - (Math.abs(other.x) + Math.abs(other.y));
        }
    }
}
