import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.io.FileWriter;
import java.io.IOException;
public class User{
///////takes values from text fields in create user and stores them in text doc///////////////
    public User(String name, String number, String address, String id, String age){
        String saveToFile = "";
        saveToFile += name + ",";
        saveToFile += number + ",";
        saveToFile += address + ",";
        saveToFile += age + ",";
        saveToFile += id + ",";
        saveToFile += "0.0";
        // Try block to check if exception occurs
        try {
            // Create a FileWriter object
            FileWriter fWriter = new FileWriter("UserDB.txt", true);
            System.out.println(saveToFile);
            saveToFile+=System.lineSeparator();
            fWriter.write(saveToFile);
            System.out.println("test"+saveToFile);
            fWriter.close();
        }
        // Catch block to handle if exception occurs
        catch (IOException e) {

            // Print the exception
            System.out.print(e.getMessage());
        }
    }



}