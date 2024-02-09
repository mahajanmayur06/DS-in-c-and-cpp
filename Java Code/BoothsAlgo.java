import java.util.*;

public class BoothsAlgo {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter multiplicand: ");
        int q = sc.nextInt();
        System.out.print("Enter multiplier: ");
        int m = sc.nextInt();
        int size = (int) Math.max(numSize(q), numSize(m));
        int[] A = binary(0, size);
        int[] Q = binary(q, size);
        int[] M = binary(m, size);
        int[] M_2C = binary(-m, size);

        System.out.println(q + " " + m);
        System.out.print("A: ");
        printArray(A, size);
        System.out.print("\nQ: ");
        printArray(Q, size);
        System.out.print("\nM: ");
        printArray(M, size);
        System.out.println();

        System.out.println(" 'A'  'Q'  'Q-1'  cycle");
        int Qm = 0;
        table(A, Q, Qm, size, 0);
        System.out.println();

        int x = size;
        while (x >= 0) {
            if (Q[size] == 0 && Qm == 1) {
                A = addition(A, M, size);
                table(A, Q, Qm, size, x + 1);
            }
            if (Q[size] == 1 && Qm == 0) {
                A = addition(A, M_2C, size);
                table(A, Q, Qm, size, x + 1);
            }
            Qm = Q[size];
            Q = rightShift(Q, A[size], size);
            A = rightShift(A, A[0], size);
            table(A, Q, Qm, size, x + 1);
            System.out.println();
            x--;
        }
        System.out.println();
        System.out.print("**Booths Product is: ");
        printArray(A, size);
        printArray(Q, size);
        decimal(A, Q, size);
        sc.close();
    }

    public static void table(int[] A, int Q[], int Qm, int size, int i) {
        printArray(A, size);
        printArray(Q, size);
        System.out.print(Qm);
        System.out.println(" " + i);
    }

    public static int[] twosCompliment(int[] bin, int size) {
        while (size >= 0) {
            if (bin[size] == 1) {
                break;
            }
            size--;
        }
        size--;
        while (size >= 0) {
            if (bin[size] == 0)
                bin[size] = 1;
            else
                bin[size] = 0;
            size--;
        }
        return bin;
    }

    public static int[] binary(int a, int size) {
        int n = (int) Math.abs(a);
        int i = size;
        int[] bin = new int[size + 1];
        while (n > 0) {
            bin[i] = n % 2;
            i--;
            n = n / 2;
        }
        if (a < 0) {
            bin = twosCompliment(bin, size);
        }
        return bin;
    }

    public static int numSize(int a) {
        int i = 0;
        a = (int) Math.abs(a);
        while (a > 0) {
            i++;
            a = a / 2;
        }
        return i;
    }

    public static int binaryToDecimal(int[] arr, int size) {
        int i = 0;
        int sum = 0;

        while (size >= 0) {
            sum = sum + (arr[size] * (int) (Math.pow(2, i)));
            size--;
            i++;
        }

        return sum;
    }

    public static void printArray(int[] arr, int size) {
        for (int i = 0; i <= size; i++) {
            System.out.print(arr[i]);
        }
        System.out.print(" ");
    }

    public static int[] rightShift(int[] arr, int x, int size) {
        int[] rs = new int[size + 1];
        rs[0] = x;
        for (int i = 0; i < size; i++) {
            rs[i + 1] = arr[i];
        }
        return rs;
    }

    public static int[] addition(int[] arr1, int[] arr2, int size) {
        int[] add = new int[size + 1];
        int c = 0;
        for (int i = size; i >= 0; i--) {
            if (arr1[i] == 0 && arr2[i] == 0) {
                add[i] = c;
                c = 0;
            } else if ((arr1[i] == 0 && arr2[i] == 1) || (arr1[i] == 1 && arr2[i] == 0)) {
                add[i] = 1 + c;
                if (c == 1) {
                    add[i] = 0;
                }
            } else if (arr1[i] == 1 && arr2[i] == 1) {
                add[i] = c;
                c = 1;
            }
        }
        return add;
    }

    public static void decimal(int[] A, int[] Q, int size) {
        int[] B = new int[A.length + Q.length];

        int cout = 0;
        for (int i = 0; i <= size; i++) {
            B[cout] = A[i];
            cout++;
        }
        for (int i = 0; i <= size; i++) {
            B[cout] = Q[i];
            cout++;
        }

        int x = B[0];
        if (B[0] == 1) {
            int i = B.length - 1;
            B = twosCompliment(B, i);
        }
        if (x == 0)
            System.out.println("\n**The decimal product is " + binaryToDecimal(B, B.length - 1));
        else
            System.out.println("\n**The decimal is -" + binaryToDecimal(B, B.length - 1));
    }

}
