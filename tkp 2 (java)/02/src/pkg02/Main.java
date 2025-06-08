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
        System.out.println("\n(5) ������������ ���������� ������ ��������� �������."
                + "\n���������� ���������� ������ ��������� �������,"
                + "\n������� �� ������ ������");
        Random rand = new Random();
        int evens = 0, n = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("������� ������ �������: ");
        n = s.nextInt();

        int arr[] = new int[n];
        
        for (int i=0; i<n; i++) {
            arr[i] = rand.nextInt(100);
            if (i%2 == 0 && arr[i] % 2 == 0) evens++;
            System.out.print(arr[i] + " ");
        }
        System.out.print("\n׸���� ��������� �� ������ ������: " + evens);
    }
    
    static void ex02() {
         System.out.println("\n(6) �������� ������. ���������� ���������� ������"
                 + "\n��������� �������, �������� ������� �������� ��������� �����"
                 + "\n������� �������� ������� 2 ���� (�.�. � ������� ������ ����"
                 + "\n�� ������ ����������� �����)");
        Random rand = new Random();
        int first = 0, count = 0, n = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("������� ������ �������: ");
        n = s.nextInt();

        int arr[] = new int[n];
        
        for (int i=0; i<n; i++) {
            arr[i] = rand.nextInt(10000);
            if (i == 0) first = arr[i] % 10;
            System.out.print(arr[i] + " ");
        }
        
        System.out.print("\n������ ��������� �������, ���������� ��������� �����"
                + "\n������� �������� ������� 2 ����: ");
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
        System.out.println("\n(4) ��� ��������� ������. ������������ ����������"
                + "\n������ ������ �� ������ ��������� ���������� �������");
        Random rand = new Random();
        int evensarr[] = new int[25], evarrindex = 0, n = 0, m = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("������� ������ �������: ");
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
        System.out.print("\n������ �� ������ ���������: ");
        
        for (int i=0; i<evarrindex; i++) {
            System.out.print(evensarr[i] + " ");
        }
    }
    
    static void ex04() {
        System.out.println("\n(5) ��� ��������� ������. ����� ����� ���������"
                + "\n�������, ������� � ��������, ������� �������� ������ ������������,"
                + "\n� ���������� ���������, ������� �������� ������ ������������.");
        Random rand = new Random();
        int n, m, starti = 0, startj = 0, endi = 0, endj = 0, sum = 0;
        
        Scanner s = new Scanner(System.in);
        System.out.print("������� ������ �������: ");
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
            System.out.print("\n������� ������� ���������� �������� (��������, 2 5): ");
            starti = s.nextInt();
            startj = s.nextInt();
        } while (starti < 0 || starti >= n || startj < 0 || startj >= m);
        
        do {
            System.out.print("\n������� ������� ��������� �������� (��������, 4 1): ");
            endi = s.nextInt();
            endj = s.nextInt();
        } while (endi < 0 || endi >= n || endj < 0 || endj >= m || endi < starti || endj < startj);
        
        System.out.print("\n����� ��������� �� �������� [" + starti + ", " + startj + "] �� �������� [" + endi + ", " + endj + "] : ");

        for (int i = starti; i <= endi; i++) {
            for (int j = (i == starti)? startj : 0; (i == endi)? j <= endj : j < m; j++) {
                sum += arr[i][j];
            }
        }
        System.out.println(sum);
    }   
}