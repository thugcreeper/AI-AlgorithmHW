//01257007 hw1-1
package ntou.cs.java2025;
public class CrapsTest{
    // plays one game of craps
    public static void main(String[] args){
        int[] diceRollingWonTimes=new int [21];
        int[] diceRollingLostTimes=new int [21];
        int winTimes=0,lostTimes=0,totalRollTime=0,counter;
        for(counter=0;counter<1000;counter++){
            int result=Craps.play(diceRollingWonTimes,diceRollingLostTimes);//call Craps class's method
            if (result > 0) {
                winTimes++;
                totalRollTime += result;
            } else {
                lostTimes++;
                totalRollTime += -result;
            }
        }
        for(counter=0;counter<diceRollingWonTimes.length-1;counter++){
            System.out.printf("%d games won and %d games lost on roll #%d%n",
            diceRollingWonTimes[counter],diceRollingLostTimes[counter],counter+1);
        }
        System.out.printf("%d games won and %d games lost on rolls after the 20th roll%n",
            diceRollingWonTimes[20],diceRollingLostTimes[20]);//print '%' use %%
        System.out.printf("The chances of winning are %d / 1000 =%.2f%% %n",winTimes,((float)winTimes/1000)*100);
        System.out.printf("The average game length is %.2f rolls.%n",(float)totalRollTime/1000);
    }
   
}