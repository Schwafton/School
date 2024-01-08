import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
public class SearchItem {
    private static String[] values;
    public SearchItem(String item){
        int count = 0;
        ArrayList<String> tempFile = new ArrayList<>();
        try {
            Scanner scanner = new Scanner(new FileReader("ItemDB.txt"));
            while(scanner.hasNextLine()){
                tempFile.add(scanner.nextLine());
                count ++;
                //System.out.println(tempFile);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        int i =0;
        while(i < count){
            String temp = "";
            temp = tempFile.get(i);
            if(temp.contains(item)){
                values = temp.split(",");
                //System.out.println("found: " + tempFile.get(i) );
                break;
            }
            else{
                //System.out.println("not found");
            }
            i++;
        }

    }
    public static String[] display(){
        return values;
    }

    }
