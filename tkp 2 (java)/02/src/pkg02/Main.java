package pkg02;

import java.util.*;
/**
 *
 * @author cdctt
 */
public class Main {
    public static void main(String[] args) {
        ex01();
        ex02();
        ex03();
        ex04();
    }
    
    static void ex01() {
        System.out.println("\n(5) Сформировать одномерный массив случайным образом."
                + "\nОпределить количество четных элементов массива,"
                + "\nстоящих на четных местах");
        Random rand = new Random();
        int evens = 0, n = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("Введите размер массива: ");
        n = s.nextInt();

        int arr[] = new int[n];
        
        for (int i=0; i<n; i++) {
            arr[i] = rand.nextInt(100);
            if (i%2 == 0 && arr[i] % 2 == 0) evens++;
            System.out.print(arr[i] + " ");
        }
        System.out.print("\nЧётных элементов на чётных местах: " + evens);
    }
    
    static void ex02() {
         System.out.println("\n(6) Задается массив. Определить порядковые номера"
                 + "\nэлементов массива, значения которых содержат последнюю цифру"
                 + "\nпервого элемента массива 2 раза (т.е. в массиве должны быть"
                 + "\nне только однозначные числа)");
        Random rand = new Random();
        int first = 0, count = 0, n = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("Введите размер массива: ");
        n = s.nextInt();

        int arr[] = new int[n];
        
        for (int i=0; i<n; i++) {
            arr[i] = rand.nextInt(10000);
            if (i == 0) first = arr[i] % 10;
            System.out.print(arr[i] + " ");
        }
        
        System.out.print("\nНомера элементов массива, содержащих последнюю цифру"
                + "\nпервого элемента массива 2 раза: ");
        for (int i=0; i<n; i++) {
            while (arr[i] > 0) {
                if (arr[i] % 10 == first) count++;
                arr[i] /= 10;
            }
            if (count == 2) System.out.print(i + " ");
            count = 0;
        }
    }
    
    static void ex03() {
        System.out.println("\n(4) Дан двумерный массив. Сформировать одномерный"
                + "\nмассив только из четных элементов двумерного массива");
        Random rand = new Random();
        int evensarr[] = new int[25], evarrindex = 0, n = 0, m = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("Введите размер массива: ");
        n = s.nextInt();
        m = s.nextInt();

        int arr[][] = new int[n][m];
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                arr[i][j] = rand.nextInt(100);
                if (arr[i][j] % 2 == 0) {
                    evensarr[evarrindex] = arr[i][j];
                    evarrindex++;
                }
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        System.out.print("\nМассив из чётных элементов: ");
        
        for (int i=0; i<evarrindex; i++) {
            System.out.print(evensarr[i] + " ");
        }
    }
    
    static void ex04() {
        System.out.println("\n(5) Дан двумерный массив. Найти сумму элементов"
                + "\nмассива, начиная с элемента, индексы которого вводит пользователь,"
                + "\nи заканчивая элементом, индексы которого вводит пользователь.");
        Random rand = new Random();
        int n, m, starti = 0, startj = 0, endi = 0, endj = 0, sum = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("Введите размер массива: ");
        n = s.nextInt();
        m = s.nextInt();
        
        int arr[][] = new int[n][m];
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                arr[i][j] = rand.nextInt(100);
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        
        do {
            System.out.print("\nВведите индексы начального элемента (например, 2 5): ");
            starti = s.nextInt();
            startj = s.nextInt();
        } while (starti < 0 || starti >= n || startj < 0 || startj >= m);
        
        do {
            System.out.print("\nВведите индексы конечного элемента (например, 4 1): ");
            endi = s.nextInt();
            endj = s.nextInt();
        } while (endi < 0 || endi >= n || endj < 0 || endj >= m || endi < starti || endj < startj);
        
        System.out.print("\nСумма элементов от элемента [" + starti + ", " + startj + "] до элемента [" + endi + ", " + endj + "] : ");

        for (int i = starti; i <= endi; i++) {
            for (int j = (i == starti)? startj : 0; (i == endi)? j <= endj : j < m; j++) {
                sum += arr[i][j];
            }
        }
        System.out.println(sum);
    }   
}