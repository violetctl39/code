import java.util.*;
import java.io.*;

public class Main
{	
	int qpow(int x,int y)
	{
		int res=1;
		while(y!=0)
		{
			if((y&1)!=0)res=res*x;
			x=x*x;y>>=1;
		}return res;
	}
	public static void main(String[] args) 
	{
		
	}
}