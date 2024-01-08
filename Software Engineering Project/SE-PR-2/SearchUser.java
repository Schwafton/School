import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
////////This class only opens UserDB.txt and stores into arrayList, search aspect is not implemented//////////
///Note: I tried a few search methods and couldn't get them to work///
//////////method for returning values back to userInterface so user can be displayed needs to be added/////////////

public class SearchUser {
    private static int count;
    private static String[] values;
    public SearchUser(String user){
        count = 0;
        ArrayList<String> tempFile = new ArrayList<>();
            try {
                Scanner scanner = new Scanner(new FileReader("UserDB.txt"));
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
                if(temp.contains(user)){
                    values = temp.split(",");
                    count = i;
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
    public static int count(){
        return count;
    }

}