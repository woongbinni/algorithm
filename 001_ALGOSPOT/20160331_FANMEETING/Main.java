import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = sc.nextInt();

        for(int i=0; i<test_case; ++i){
            String member = sc.next();
            String fans = sc.next();
            String reversed_fans = new StringBuilder(fans).reverse().toString();
            
//          Vector<Integer> v_member = new Vector<Integer>(200001);
//          Vector<Integer> v_fans   = new Vector<Integer>(200001);
            
            member = member.replace('M', '1');
            member = member.replace('F', '0');

            reversed_fans = reversed_fans.replace('M', '1');
            reversed_fans = reversed_fans.replace('F', '0');
            
            BigInteger num_member = new BigInteger(member);
            BigInteger num_reversed_fans = new BigInteger(reversed_fans);
            
            BigInteger result = num_member.multiply(num_reversed_fans);
            
            String result_str = result.toString();
            while(result_str.length() < (member.length() + fans.length() -1)){
                result_str = result_str.concat("0");
            }
            int hug_cnt = 0;
            
            for(int j=member.length()-1; j<fans.length(); ++j){
                if(result_str.charAt(j) == '0')
                    hug_cnt += 1;
            }
            System.out.println(hug_cnt);
        }
        sc.close();
    }
}