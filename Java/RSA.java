import java.util.*;
public class RSA{

    static long quickPow(long x,long y,long mod){
        long res=1,bs=1,in=x,lim=0;while(Math.pow(2,lim+1)<=y){lim++;}
        for(long i=0;i<=lim;++i){
            System.out.printf("%d^%d=%d : %b\n",in,bs,x,(y&bs)!=0);
            if((y&bs)!=0)res=res*x%mod; x=x*x%mod;
            bs=bs*2;
        }
        return res;
    }
    static long gcd(long x,long y){
        return y!=0?gcd(y,x%y):x;
    }
    static long Phi(long x){
        long res=0;
        for(long i=1;i<x;++i){
            if(gcd(i,x)==1)++res;
        }
        return res;
    }
    public static void main(String[] args){
        Scanner io=new Scanner(System.in);
        long p,q,d,e;
        System.out.printf("input:\n");
        System.out.printf("p = ");p=io.nextLong();
        System.out.printf("q = ");q=io.nextLong();
        long n=p*q,t=(p-1)*(q-1);
        System.out.printf("d = ");d=io.nextLong();
        System.out.printf("Phi(%d) = %d\n",t,Phi(t));
        e=quickPow(d,Phi(t)-1,t);
        System.out.printf("e = %d\n",e);

        long m=65;
        System.out.println(quickPow(m,e,n));
        System.out.println(quickPow(quickPow(m,e,n),d,n));

        io.close();
        
    }
}