package Java;
import java.util.Scanner;

public class Array {
    public static void main(String[] arg){

        Scanner sc = new Scanner(System.in);

        int n= 5;
        int[] arr= new int[n];

        for(int i=0;i<n;i++){
            arr[i]= sc.nextInt();
        }
        for(int i=0;i<n;i++){
            System.out.printf("%d " ,arr[i]);
        }
        
        sc.close();
        
    }
}
