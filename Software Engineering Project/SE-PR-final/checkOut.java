import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class checkOut {
    private static String[] values;

    //private static boolean avail;
    public checkOut(String title, String name) {
        int count = 0;
        ArrayList<String> tempFile = new ArrayList<>();
        StringBuffer buffer = new StringBuffer();
        String fileBuffer = null;
        try {
            Scanner scanner = new Scanner(new FileReader("ItemDB.txt"));
            //
            while (scanner.hasNextLine()) {
                String tempPasser;
                tempPasser = scanner.nextLine();
                buffer.append(tempPasser + System.lineSeparator());
                tempFile.add(tempPasser);

                count++;
            }
            fileBuffer = buffer.toString();
            scanner.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        int i = 0;
        String oldString;
        SimpleDateFormat formatter = new SimpleDateFormat("MM-dd-yyyy");
        Calendar c = Calendar.getInstance();
        String checkOutDate = formatter.format(c.getTime());
        while (i < count) {
            String temp;
            temp = tempFile.get(i);
            if (temp.contains(title)) {
                values = temp.split(",");
                oldString = temp;
                System.out.println("old string: " + oldString);
                if ((values[7].equals("none")) && (values[2].equals("book") || values[2].equals("audio")||values[2].equals("video")))/*&&(values[2].equals("book"))*/ {
                    /*String titleDis = values[0];
                    String authorDis = values[1];
                    String typeDis = values[2];
                    String availDis = values[3];
                    String cbDis = values[4];
                    String reqDis = values[5];
                    String costDis = values[6];*/
                    values[7] = name;
                    values[3] = "Not Available";
                    values[8] = checkOutDate;
                    if(values[2].equals("book")&&values[4].equals("NotCB")){
                        c.add(Calendar.DAY_OF_MONTH,21);
                        String dueDate = formatter.format(c.getTime());
                        values[9]=dueDate;
                    }
                    else if((values[2].equals("audio")||values[2].equals("video"))||values[4].equals("CurrentBestSeller")){
                        c.add(Calendar.DAY_OF_MONTH,14);
                        String dueDate = formatter.format(c.getTime());
                        values[9]= dueDate;
                    }
                    else{
                        System.out.println("item cant be checked out");
                    }
                    //System.out.println(name);
                    String[] tempValues = values;
                    tempValues[0] += ",";
                    tempValues[1] += ",";
                    tempValues[2] += ",";
                    tempValues[3] += ",";
                    tempValues[4] += ",";
                    tempValues[5] += ",";
                    tempValues[6] += ",";
                    tempValues[7] += ",";
                    tempValues[8] += ",";
                    tempValues[9] += ",";
                    try {
                        // Create a FileWriter object
                        FileWriter fWriter = new FileWriter("ItemDB.txt", false);
                        int k = 0;
                        String tempPush = "";
                        while (k < tempValues.length) {
                            tempPush += tempValues[k];
                            //System.out.println("tempPush: " +tempPush);
                            k++;
                        }
                        String fileContents = fileBuffer.replaceAll(oldString, tempPush);
                        fWriter.append(fileContents);
                        fWriter.flush();
                        fWriter.close();
                    }
                    // Catch block to handle if exception occurs
                    catch (IOException e) {

                        // Print the exception
                        System.out.print(e.getMessage());
                    }
                } else if (!values[7].equals("none")) {
                    //
                }
                break;
            } else {
                //System.out.println("not found");
            }
            i++;
        }

    }

    public static String[] display() {
        return values;
    }

}



