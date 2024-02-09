import java.util.Scanner;

public class RestoringDivision {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter dividend: ");
        int q = sc.nextInt();
        System.out.print("Enter divisor: ");
        int m = sc.nextInt();

        int size = Math.max(numSize(q), numSize(m));
        // System.out.println(size);
        int[] A = binary(0, size + 1);
        int[] Q = binary(q, size);
        int[] M = binary(m, size + 1);
        int[] M_2C = twosComplement(M, size + 1);

        System.out.print("Q: ");
        printArray(Q, size);
        System.out.print("\nA: ");
        printArray(A, size + 1);
        System.out.print("\nM: ");
        printArray(M, size + 1);
        System.out.print("\nM_2C: ");
        printArray(M_2C, size + 1);

        int i = size;
        System.out.println("\n\n 'A'   'Q'  'Cycle'\n");
        printArray(A, size + 1);
        printArray(Q, size);
        System.out.println(" initialise");
        while (i > 0) {

            System.out.println();
            A = leftShift(A, size + 1);
            A[size] = Q[0];
            Q = leftShift(Q, size);

            printArray(A, size + 1);
            printArrayAfterLS(Q, size);
            System.out.println("  " + i);

            A = addition(A, M_2C, size + 1);

            printArray(A, size + 1);
            printArrayAfterLS(Q, size);
            System.out.println();

            if (A[0] == 1) {
                A = addition(A, M, size + 1);
                Q[size - 1] = 0;
            } 
            else
                Q[size - 1] = 1;

            printArray(A, size + 1);
            printArray(Q, size);
            System.out.println();
            i--;
        }

        System.out.print("\nRemainder: ");
        printArray(A, size + 1);
        System.out.println("(" + binaryToDecimal(A, size + 1) + ")");
        System.out.print("Quotient :  ");
        printArray(Q, size);
        System.out.println("(" + binaryToDecimal(Q, size) + ")");
        sc.close();
    }

    public static int[] leftShift(int[] A, int size) {
        for (int i = 1; i < size; i++) {
            A[i - 1] = A[i];
        }
        return A;
    }

    public static int[] twosComplement(int[] bin, int size) {
        int[] tc = new int[size];
        int i = size - 1;
        while (size > 0) {
            if (bin[size - 1] == 1) {
                tc[i] = bin[size - 1];
                i--;
                size--;
                break;
            }
            tc[i] = bin[size - 1];
            i--;
            size--;
        }

        while (size > 0) {
            if (bin[size - 1] == 0)
                tc[i--] = 1;
            else
                tc[i--] = 0;
            size--;
        }
        return tc;
    }

    public static int[] binary(int n, int size) {
        int i = size - 1;
        int[] bin = new int[size];
        while (n > 0 || i >= 0) {
            bin[i--] = n % 2;
            n = n / 2;
        }
        return bin;
    }

    public static int numSize(int a) {
        int i = 0;
        a = Math.abs(a);
        while (a > 0) {
            i++;
            a = a / 2;
        }
        return i;
    }

    public static int binaryToDecimal(int[] arr, int size) {
        int i = 0;
        int sum = 0;
        while (size > 0) {
            sum = sum + (arr[size - 1] * (int) (Math.pow(2, i)));
            size--;
            i++;
        }
        return sum;
    }

    public static void printArray(int[] arr, int size) {
        for (int i = 0; i < size; i++)
            System.out.print(arr[i]);

        System.out.print(" ");
    }

    public static void printArrayAfterLS(int[] arr, int size) {
        for (int i = 0; i < size-1; i++)
            System.out.print(arr[i]);

        System.out.print("_");
        System.out.print(" ");
    }

    public static int[] addition(int[] arr1, int[] arr2, int size) {
        int[] add = new int[size];
        int c = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (arr1[i] == 0 && arr2[i] == 0) {
                add[i] = c;
                c = 0;
            } else if ((arr1[i] == 0 && arr2[i] == 1) || (arr1[i] == 1 && arr2[i] == 0)) {
                add[i] = 1 + c;
                if (c == 1)
                    add[i] = 0;
            } else if (arr1[i] == 1 && arr2[i] == 1) {
                add[i] = c;
                c = 1;
            }
        }
        return add;
    }
}
