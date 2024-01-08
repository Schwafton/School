import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class item {
    //private static ArrayList<String> tempFile;
    int count =0;
    static ArrayList<String> tempFile = new ArrayList<>();
    public item(String name){
        String tempHold;
        try {
            Scanner scanner = new Scanner(new FileReader("ItemDB.txt"));
            while(scanner.hasNextLine()){
                tempHold = scanner.nextLine();

                if(tempHold.contains(name)){
                    tempFile.add(tempHold);
                    //System.out.println("Test "+ tempHold);
                }
                count ++;
                //System.out.println(tempFile);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        //System.out.println("associated: " + tempFile);



    }
    public static ArrayList<String> display(){
        return tempFile;
    }
}