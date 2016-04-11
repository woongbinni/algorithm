import java.math.BigInteger;
import java.util.Scanner;

public class C-CoinJam_try01 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = sc.nextInt();

        for(int idx=0; idx<test_case; ++idx){


        }
        sc.close();
    }

    public static boolean isprime(BigInteger n)
    {
       if(n.compareTo(BigInteger.ONE)==0 || n.compareTo(two)==0)
       {
        return true;
    }
    BigInteger half=n.divide(two);

    for(BigInteger i=three; i.compareTo(half)<=0;i=i.add(two))
    {

        if(n.mod(i).equals(BigInteger.ZERO))
        {
          return false; 
      }

  }
  return true;

}
}