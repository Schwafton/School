
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
////////This class only opens UserDB.txt and stores into arrayList, search aspect is not implemented//////////
///Note: I tried a few search methods and couldn't get them to work///
//////////method for returning values back to userInterface so user can be displayed needs to be added/////////////
public class SearchUser {
    public SearchUser(String user){
        ArrayList<String> tempFile = new ArrayList<>();
            try {
                Scanner scanner = new Scanner(new FileReader("UserDB.txt"));
                int i =0;
                while(scanner.hasNextLine()){
                    tempFile.add(scanner.nextLine());
                    //System.out.println(tempFile);
                }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            for(String element : tempFile ){
                if(element.equals(user)){
                    System.out.println("found: " + element);
                }
                else{
                    System.out.println("not found");
                }
            }



    }
}
