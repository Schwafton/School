import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

    public class Request{
        private static String[] valuesReq;

        public Request(String title, String name){
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
                    buffer.append(tempPasser+System.lineSeparator());
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
            while (i < count) {
                String temp;
                temp = tempFile.get(i);
                if (temp.contains(title)) {
                    valuesReq = temp.split(",");
                    oldString= temp;
                    System.out.println("old string: " + oldString);
                    if (valuesReq[5].equals("NotRequested")) {
                        valuesReq[5] = "Requested";
                        //values[3] = "Not Available";
                        //System.out.println(name);
                        String []tempValues = valuesReq;
                        tempValues[0] += ",";
                        tempValues[1] += ",";
                        tempValues[2] += ",";
                        tempValues[3] += ",";
                        tempValues[4] += ",";
                        tempValues[5] += ",";
                        tempValues[6] += ",";
                        tempValues[7] += ",";
                        tempValues[8] +=",";
                        tempValues[9] += ",";
                        try {
                            // Create a FileWriter object
                            FileWriter fWriter = new FileWriter("ItemDB.txt", false);
                            int k =0;
                            String tempPush = "";
                            while(k<tempValues.length){
                                tempPush += tempValues[k];
                                //System.out.println("tempPush: " +tempPush);
                                k++;
                            }
                            String fileContents = fileBuffer.replaceAll(oldString,tempPush);
                            fWriter.append(fileContents);
                            fWriter.flush();
                            fWriter.close();
                        }
                        // Catch block to handle if exception occurs
                        catch (IOException e) {

                            // Print the exception
                            System.out.print(e.getMessage());
                        }
                    }
                    else if (valuesReq[5].equals("Requested")) {
                        //avail = false;
                    }
                    break;
                } else {
                    //System.out.println("not found");
                }
                i++;
            }
        }
        public static String[] displayReq () {
            return valuesReq;
        }
    }
