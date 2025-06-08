import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // ex01();
        // ex02();
        // ex03();
        ex04();
    }

    static void ex01() {
        Scanner s = new Scanner(System.in);
        System.out.print("Array size: ");

        Random rand = new Random();
        int n = s.nextInt();
        
        int arr[] = new int[n];
        System.out.print("Source array: ");
        
        for (int i = 0; i < n; i++) {
            arr[i] = rand.nextInt(100);
            System.out.print(arr[i] + " ");
        }
        
        ArrayList<Integer> repeatingList = new ArrayList<Integer>();
        System.out.print("\nDuplicate elements: ");

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j] && !repeatingList.contains(arr[j])) {
                    repeatingList.add(arr[j]);
                    System.out.print(arr[j] + " ");
                }
            }
        }

        if (repeatingList.size() == 0) System.out.print("none");
    }

    static void ex02() {
        Scanner s = new Scanner(System.in);
        System.out.print("Array size: ");

        Random rand = new Random();
        int n = s.nextInt();
        
        int arr[] = new int[n];
        System.out.print("Source array: ");
        
        for (int i = 0; i < n; i++) {
            arr[i] = rand.nextInt(100);
            System.out.print(arr[i] + " ");
        }
    
        System.out.print("\nArr a[i] > i: ");

        for (int i = 0; i < n; i++) {
            if (arr[i] > i) System.out.print(arr[i] + " ");
        }
    }

    static void ex03() {
        Scanner s = new Scanner(System.in);
        System.out.print("Array size: ");

        Random rand = new Random();

        int m = s.nextInt(), n = s.nextInt(), min = 0, minI = 0, minJ = 0, max = 0, maxI = 0, maxJ = 0;

        int[][] arr = new int[m][n];
        System.out.print("Source array:\n");

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = rand.nextInt(100);
                System.out.print(arr[i][j] + " ");
            }
            System.out.print("\n");
        }
        
        min = max = arr[0][0];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] <= min) {
                    if (arr[i][j] < min) {
                        min = arr[i][j];
                        minI = i;
                        minJ = j;
                    }
                    else if (i + j < minI + minJ) {
                        minI = i;
                        minJ = j;
                    }
                }
                if (arr[i][j] >= max) {
                    if (arr[i][j] > max) {
                        max = arr[i][j];
                        maxI = i;
                        maxJ = j;
                    }
                    else if (i + j > maxI + maxJ) {
                        maxI = i;
                        maxJ = j;
                    }
                }
            }
        }

        System.out.println("Minimal element " + min + " found at position [" + minI + ", " + minJ + "]");
        System.out.println("Maximal element " + max + " found at position [" + maxI + ", " + maxJ + "]");
    }

    static void ex04() {
        Scanner s = new Scanner(System.in);
        System.out.print("Array size: ");

        Random rand = new Random();

        int n = s.nextInt();

        int[][] arr = new int[n][n];
        int[] diagArr = new int[n];
        System.out.print("Source array:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = rand.nextInt(100);
                System.out.print(arr[i][j] + " ");
                if (i == j) diagArr[i] = arr[i][j];
            }
            System.out.print("\n");
        }

        System.out.print("Diagonals array: ");
        for (int i = 0; i < n; i++) System.out.print(diagArr[i] + " ");
    }
}
