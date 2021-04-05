import java.util.Random;
import java.util.Scanner;
import java.util.Vector;
import java.io.*;


public class SkeeBall {
	
	static final int MAX_PLAYS = 8;
	Vector<Integer> plays = new Vector<Integer>();
	Vector<Integer> score = new Vector<Integer>();
	
	public void SimulatePlay(int n) {
		for(int i = 1; i<=n;i++) {
			Random random = new Random();
			int num = random.nextInt(25-1)+1;
			if(num>=1 && num<=6) {
				System.out.println("Rolling ball # " + i +". "+"Landed in 0");
				plays.add(i);
				score.add(0);
			}
			if(num>=7 && num<=12) {
				System.out.println("Rolling ball # " + i +". "+"Landed in 10");
				plays.add(i);
				score.add(10);
			}
			if(num>=13 && num<=18) {
				System.out.println("Rolling ball # " + i +". "+"Landed in 20");
				plays.add(i);
				score.add(20);
			}
			if(num>=19 && num<=24) {
				System.out.println("Rolling ball # " + i +". "+"Landed in 40");
				plays.add(i);
				score.add(40);
			}
			if(num>=25 && num<=30) {
				System.out.println("Rolling ball # " + i +". "+"Landed in 60");
				plays.add(i);
				score.add(60);
			}
			if(num>=31 && num<=35) {
				System.out.println("Rolling ball # " + i +". "+"Landed in 80");
				plays.add(i);
				score.add(80);
			}
		}
	}
	
	public void printf() {
		int totalScore=0;
		for(int i =0;i<score.size();i++) {
			totalScore= totalScore+ score.get(i);
		}
		
		System.out.println("+----------+----------+");
		System.out.printf("%10s %10s","Play #","Score");
		System.out.println();
		System.out.println("+----------+----------+");
		for(int i=0,j=0;i<plays.size() && j<score.size();i++,j++) {
			System.out.format("%8s %8s",plays.get(i),score.get(j));
			System.out.println();
		}
		System.out.println("Total: "+totalScore);
	}
	
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		SkeeBall skee = new SkeeBall();
		while(true) {
			System.out.print("Enter the number of plays (1-8) ");
			int n = in.nextInt();
			switch(n) {
				case 1:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 2:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 3:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 4:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 5:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 6:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 7:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				case 8:
					skee.SimulatePlay(n);
					skee.printf();
					break;
				default:
					System.out.println("Invalid input. Please enter a number between 1 and 8.");
					break;
			}
		}
	}
}
