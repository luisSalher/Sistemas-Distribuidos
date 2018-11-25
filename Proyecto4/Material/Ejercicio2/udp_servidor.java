import java.io.*;
import java.net.*;
import java.nio.ByteBuffer; //Para manejo de ByteBuffer
import java.nio.ByteOrder;

public class udp_servidor{
	public static void main(String args[]){
		
		int port = 7200;
		while(true){
			try{
				DatagramSocket ds = new DatagramSocket(7200);  
			    final ByteBuffer buf = ByteBuffer.allocate(8);  
			    buf.order(ByteOrder.BIG_ENDIAN);
			    //DatagramPacket dp = new DatagramPacket(buf, buf.limit); 
			    DatagramPacket dp = new DatagramPacket(buf.array() , buf.limit()); 
			    ds.receive(dp);  
			    int entero1 = buf.getInt();
				int entero2 = buf.getInt();
				System.out.println("int MIN = " + entero1 + " int MAX = " + entero2);
			    ds.close(); 
			}
			catch(IOException e){
				System.err.println("IOException " + e); 
			}
		}
	}
} 
