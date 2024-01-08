import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Math;
import java.util.ArrayList;

// Class 1
// Helper class extending JFrame class
public class userInterface extends JFrame {
    int numItems = 0;
    public userInterface() {
        ///////////Home Frame///////////////////
        JFrame home;
        JButton createuser, searchUser,/* searchItem*/exit;
        home = new JFrame("Home Screen");
        // Creating a new buttons
        createuser = new JButton("Create Library Card");
        searchUser = new JButton("Search user");
        //searchItem = new JButton("Search Item");
        exit = new JButton("Exit");
//////////////// Create User Button----->Create user frame ////////////////////
        createuser.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame userCreate;

                JTextField name;
                JTextField address;
                JTextField phoneNumber;
                JTextField age;

                JLabel nameLabel;
                JLabel addressLabel;
                JLabel phoneLabel;
                JLabel ageLabel;

                JButton submitButton;

                name = new JTextField();
                address = new JTextField();
                phoneNumber = new JTextField();
                age = new JTextField();

                nameLabel = new JLabel("Name:");
                addressLabel = new JLabel("Address:");
                phoneLabel = new JLabel("Phone Number:");
                ageLabel = new JLabel("Age:");

                submitButton = new JButton("Submit");
                userCreate = new JFrame("ADD USER");

                nameLabel.setBounds(25, 25, 100, 50);
                addressLabel.setBounds(25, 100, 100, 50);
                phoneLabel.setBounds(25, 175, 100, 50);
                ageLabel.setBounds(25, 250, 100, 50);

                name.setBounds(125, 35, 200, 30);
                address.setBounds(125, 110, 200, 30);
                phoneNumber.setBounds(125, 185, 200, 30);
                age.setBounds(125, 260,200, 30);
                submitButton.setBounds(150, 315, 125, 30);
/////////////////Submit Button on Create User Frame------>user created screen////////////////////////////////
                submitButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        userCreate.dispose();
                        JFrame userCreated;
                        userCreated = new JFrame("User Created");
                        JLabel success;
                        String tempName = null;
                        String tempAddress = null;
                        String tempNumber = null;
                        String tempAge = null;
                        if(! name.getText().isEmpty()) {
                            tempName = name.getText();
                            System.out.println(tempName);
                             }
                        if(! address.getText().isEmpty()) {
                            tempAddress = address.getText();
                            System.out.println(tempAddress);
                        }
                        if(! phoneNumber.getText().isEmpty()) {
                            tempNumber = phoneNumber.getText();
                            System.out.println(tempNumber);
                        }
                        if(! age.getText().isEmpty()) {
                            tempAge = age.getText();
                            System.out.println(tempAge);
                        }
                        /////RAND ID GENERATED(NEED TO ADD CHECKER SO NO DUPLICATES)//////////////
                        long maxID = 999999999;
                        long minID = 100000000;
                        long range = maxID - minID + 1;
                        long rand = (long)(Math.random() * range) + minID;
                        String randId = Long.toString(rand);
                        FileSearch fileSearch = new FileSearch();
                        String[] search = {"UserDB.txt", randId};
                        while (fileSearch.FileSearch(search)) {
                          rand = (long)(Math.random() * range) + minID;
                          randId = Long.toString(rand);
                          search[1] = randId;
                        }
                        new User(tempName,tempAddress, tempNumber, randId, tempAge );

                        success = new JLabel("User " + tempName + " successfully added to system");
                        success.setBounds(15, 50, 275, 75);
                        userCreated.add(success);
                        userCreated.setBackground(Color.cyan);
                        userCreated.setSize(300, 300);
                        userCreated.setLayout(null);
                        userCreated.setVisible(true);
                    }
                });

                userCreate.add(nameLabel);
                userCreate.add(name);
                userCreate.add(addressLabel);
                userCreate.add(ageLabel);
                userCreate.add(address);
                userCreate.add(phoneLabel);
                userCreate.add(phoneNumber);
                userCreate.add(age);
                userCreate.add(submitButton);
                userCreate.setBackground(Color.white);
                userCreate.setSize(400, 400);
                userCreate.setLayout(null);
                userCreate.setVisible(true);
            }
        });
///////////////Search User Button on Main Frame------>search for user frame////////////////////
        searchUser.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame userSearch;
                JTextField searchName;
                JLabel labelName;
                JButton enter;
                searchName = new JTextField();
                labelName = new JLabel("Search user by name:");
                enter = new JButton("Enter");
                userSearch = new JFrame("Search For User");
                labelName.setBounds(15,25,200, 50);
                searchName.setBounds(155,37, 200, 30);
                enter.setBounds(140,80,135,30);
                userSearch.setSize(450, 200);
                userSearch.add(labelName);
                userSearch.add(searchName);
                userSearch.add(enter);
                userSearch.setBackground(Color.white);
                userSearch.setLayout(null);
                userSearch.setVisible(true);
////////////////Enter Button----> UserFound frame//////////////////
                enter.addActionListener(new ActionListener(){
                    //////////////////currently working on//////////////////
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        userSearch.dispose();
                        JFrame userFound;
                        JLabel name;
                        JLabel address;
                        JLabel phoneNumber;
                        JLabel age;
                        JLabel id;
                        JLabel fines;
                        JLabel itemsChecked;
                        //JButton returnItem;
                        //JButton renewItem;
                        JButton payFines;
                        JTextField itemSearched;
                        JTextField itemReturned;
                        JTextField itemRenewed;
                        JButton findItem;
                        String tempSearch;
                        JTextArea ta = new JTextArea();
                        ta.setText("");
                        if(! searchName.getText().isEmpty()) {
                            tempSearch = searchName.getText();
                            new SearchUser(tempSearch);
                            new item(tempSearch);
                            ArrayList<String> items = item.display();
                            int k =0;
                            String tempBooks;
                            String[] tempB;
                            numItems = items.size();
                            while(k<items.size()){
                                tempBooks = items.get(k);
                                tempB = tempBooks.split(",");
                                String tempTitle= tempB[0];
                                String tempAuthor= tempB[1];
                                String dateChecked = tempB[8];
                                String dateReturn = tempB[9];
                                //String tempDays = tempB[8];
                                ta.append(tempTitle+", "+tempAuthor+", Date Checked Out:"+dateChecked+"Due by:"+dateReturn+"\n");
                                //ta.append(tempAuthor+"\n");
                                //ta.append("Checked out for:" +tempDays+" days");
                                k++;
                            }


                            System.out.println(tempSearch);
                        }
                        //SearchUser is called and array from display method is stored
                        String [] values = SearchUser.display();
                        String nameDis = values[0];
                        String addressDis = values[1];
                        String phoneNumberDis = values[2];
                        String ageDis = values[3];
                        String idDis = values[4];
                        String fineDis = values[5];
                        name = new JLabel("Name: "+nameDis );
                        address = new JLabel("Address: " + addressDis);
                        phoneNumber = new JLabel("Phone Number: " + phoneNumberDis);
                        age = new JLabel("Age: "+ageDis);
                        id = new JLabel("ID: "+idDis);
                        fines = new JLabel("Fines Owed $" + fineDis);


                        itemsChecked = new JLabel("Items currently checked out: ");
                        itemSearched = new JTextField();
                        itemReturned = new JTextField();
                        itemRenewed = new JTextField();
                        findItem = new JButton("Check Item");
                        //returnItem = new JButton("Return Item");
                        //renewItem = new JButton("Renew Item");
                        payFines = new JButton("Pay Fines");

                        userFound = new JFrame("User Found");
                        name.setBounds(15,5,200, 50);
                        address.setBounds(15,35,200, 50);
                        phoneNumber.setBounds(15,65,200,50);
                        age.setBounds(15,95,200, 50);
                        id.setBounds(15,125,200, 50);
                        fines.setBounds(15,155, 200,50);

                        findItem.setBounds(15,375,100,30);
                        //returnItem.setBounds(115,375,110, 30);
                        //renewItem.setBounds(215,375,110, 30);
                        payFines.setBounds(235,155,110,30);
                        itemsChecked.setBounds(15,185,200, 50);
                        ta.setBounds(15,215,450,125);
                        itemSearched.setBounds(15, 345, 300, 30);
                        itemReturned.setBounds(15,385,200,30);
                        itemRenewed.setBounds(15,425,200,30);
                        userFound.setSize(500, 550);

                        userFound.add(name);
                        userFound.add(address);
                        userFound.add(phoneNumber);
                        userFound.add(age);
                        userFound.add(id);
                        userFound.add(fines);

                        userFound.add(itemSearched);
                        //userFound.add(itemReturned);
                        //userFound.add(itemRenewed);
                        userFound.add(findItem);
                        userFound.add(itemsChecked);
                        //userFound.add(renewItem);
                        //userFound.add(returnItem);
                        userFound.add(payFines);
                        userFound.add(ta);

                        userFound.setBackground(Color.white);
                        userFound.setLayout(null);
                        userFound.setVisible(true);

                        //////Pay fines button sets fines owed to 0.0//////
                        ////NOTE: NEED TO ADD METHOD THAT CHANGES IT IN TEXT FILE////////
                        payFines.addActionListener(new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                fines.setText("Fines Owed: $0.0");
                            }
                        });
                        /////////item found frame/////////////////////
                        findItem.addActionListener(new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                String tempTitle;
                                if(! itemSearched.getText().isEmpty()) {
                                    tempTitle = itemSearched.getText();
                                    System.out.println("title:" + tempTitle);
                                    new SearchItem(tempTitle);
                                }
                                String[] itemValues = SearchItem.display();
                                String titleDis = itemValues[0];
                                String authorDis = itemValues[1];
                                String typeDis = itemValues[2];
                                String availDis = itemValues[3];
                                String cbDis = itemValues[4];
                                String reqDis = itemValues[5];
                                String costDis = itemValues[6];
                                String checkDate = itemValues[8];
                                String returnDate = itemValues[9];
                                String renew = itemValues[10];
                                JFrame itemFound;
                                JLabel title;
                                JLabel author;
                                JLabel type;
                                JLabel available;
                                JLabel cb;
                                JLabel requested;
                                JLabel cost;
                                JButton check;
                                title = new JLabel("Title: "+ titleDis);
                                author = new JLabel("Author: "+authorDis);
                                type = new JLabel("Type: "+typeDis);
                                available = new JLabel("Available: "+availDis);
                                cb = new JLabel("Current Best Seller: "+cbDis);
                                requested = new JLabel("Requested: "+reqDis);
                                cost = new JLabel("Cost: "+costDis);
                                check = new JButton("Check Out");
                                JButton returnItem = new JButton("Return Item");
                                JButton renewItem = new JButton("Renew Item");
                                JButton request = new JButton("Request");
                                title.setBounds(15,5,300, 50);
                                author.setBounds(15,35,300, 50);
                                type.setBounds(15,65,300,50);
                                available.setBounds(15,95,300, 50);
                                cb.setBounds(15,125,300, 50);
                                requested.setBounds(15,155, 300,50);
                                cost.setBounds(15,185, 200,50);
                                check.setBounds(15,225,100,40);
                                request.setBounds(115,225, 100, 40);
                                returnItem.setBounds(215,225,110, 40);
                                renewItem.setBounds(315,225,110,40);
                                itemFound = new JFrame("Item Found");

                                itemFound.setSize(500,400);
                                itemFound.add(title);
                                itemFound.add(author);
                                itemFound.add(type);
                                itemFound.add(available);
                                itemFound.add(cb);
                                itemFound.add(requested);
                                itemFound.add(cost);
                                itemFound.add(check);
                                itemFound.add(request);
                                itemFound.add(request);
                                itemFound.add(returnItem);
                                itemFound.add(renewItem);
                                itemFound.setBackground(Color.WHITE);
                                itemFound.setLayout(null);
                                itemFound.setVisible(true);
                                check.addActionListener(new ActionListener() {
                                    @Override
                                    public void actionPerformed(ActionEvent e) {
                                        itemFound.dispose();
                                        int numChecked = 0;
                                        int ageInt = Integer.parseInt(ageDis);
                                        if(availDis.equals("Available")&&(typeDis.equals("book")||typeDis.equals("audio")||typeDis.equals("video"))){
                                            new checkOut(titleDis,searchName.getText());
                                            String [] checkedItems = checkOut.display();
                                            numItems ++;
                                            ta.append(checkedItems[0] + checkedItems[1]+checkedItems[8]+checkedItems[9]);
                                        }
                                        if(availDis.equals("Not Available")){
                                            System.out.println("error");
                                            JFrame NotAvailable;
                                            JLabel notAvailable;
                                            NotAvailable = new JFrame("Item Not Available");
                                            notAvailable = new JLabel("Item selected is already checked out");
                                            notAvailable.setBounds(15,15,350,30);
                                            NotAvailable.add(notAvailable);
                                            NotAvailable.setSize(325,150);
                                            NotAvailable.setLayout(null);
                                            NotAvailable.setVisible(true);
                                        }
                                        else if(!(typeDis.equals("book")||typeDis.equals("audio")||typeDis.equals("video"))){
                                            System.out.println("not book or audio or video type");
                                            JFrame notCheckable;
                                            JLabel notcheckable;
                                            notCheckable = new JFrame("Item Not Available");
                                            notcheckable = new JLabel("Item selected cannot be checked out.\n Only books, videos, or audio can be checked out.");
                                            notcheckable.setBounds(15,15,520,30);
                                            notCheckable.add(notcheckable);
                                            notCheckable.setSize(525,150);
                                            notCheckable.setLayout(null);
                                            notCheckable.setVisible(true);
                                        }
                                        //int count = SearchUser.count();

                                    }
                                });
                                request.addActionListener(new ActionListener() {
                                    @Override
                                    public void actionPerformed(ActionEvent e) {
                                        itemFound.dispose();
                                        if(reqDis.equals("NotRequested")){
                                            new Request(titleDis,searchName.getText());
                                            //String [] checkedItems = checkOut.displayReq();
                                            //numItems ++;
                                            //ta.append("\n" +checkedItems[0] + checkedItems[1]);
                                            JFrame Requested;
                                            JLabel requestedLabel;
                                            Requested = new JFrame("Item Not Available");
                                            requestedLabel = new JLabel("Item selected is now requested");
                                            requestedLabel.setBounds(15,15,350,30);
                                            Requested.add(requestedLabel);
                                            Requested.setSize(325,150);
                                            Requested.setLayout(null);
                                            Requested.setVisible(true);

                                        }
                                        if(reqDis.equals("Requested")){
                                            System.out.println("error");
                                            JFrame alreadyRequested;
                                            JLabel alreadyRequestedLabel;
                                            alreadyRequested= new JFrame("Item Not Available");
                                            alreadyRequestedLabel = new JLabel("Item selected is already requested");
                                            alreadyRequestedLabel.setBounds(15,15,350,30);
                                            alreadyRequested.add(alreadyRequestedLabel);
                                            alreadyRequested.setSize(325,150);
                                            alreadyRequested.setLayout(null);
                                            alreadyRequested.setVisible(true);
                                        }
                                    }
                                });
                                returnItem.addActionListener(new ActionListener() {
                                    @Override
                                    public void actionPerformed(ActionEvent e) {
                                        itemFound.dispose();
                                        if(!availDis.equals("Available")){
                                            new ReturnItem(titleDis,searchName.getText());
                                            //String [] checkedItems = checkOut.displayReq();
                                            //numItems ++;
                                            //ta.append("\n" +checkedItems[0] + checkedItems[1]);
                                            JFrame Returned;
                                            JLabel returnedLabel;
                                            Returned = new JFrame("Item Not Available");
                                            returnedLabel = new JLabel("Item selected is now returned");
                                            returnedLabel.setBounds(15,15,350,30);
                                            Returned.add(returnedLabel);
                                            Returned.setSize(325,150);
                                            Returned.setLayout(null);
                                            Returned.setVisible(true);

                                        }

                                    }
                                });
                                renewItem.addActionListener(new ActionListener() {
                                    @Override
                                    public void actionPerformed(ActionEvent e) {
                                        itemFound.dispose();
                                        if(renew.equals("renew")){
                                            String tempNew = searchName.getText();
                                            new RenewItem(titleDis,tempNew);
                                            //String [] checkedItems = checkOut.displayReq();
                                            //numItems ++;
                                            //ta.append("\n" +checkedItems[0] + checkedItems[1]);
                                            JFrame Renewed;
                                            JLabel renewedLabel;
                                            Renewed = new JFrame("Item Not Available");
                                            renewedLabel = new JLabel("Item selected is now renewed");
                                            renewedLabel.setBounds(15,15,350,30);
                                            Renewed.add(renewedLabel);
                                            Renewed.setSize(325,150);
                                            Renewed.setLayout(null);
                                            Renewed.setVisible(true);

                                        }
                                        else if(renew.equals("renewed")){
                                            JFrame Renewedd;
                                            JLabel reneweddLabel;
                                            Renewedd = new JFrame("Item Not Available");
                                            reneweddLabel = new JLabel("Item selected can only be renewed one time");
                                            reneweddLabel.setBounds(15,15,350,30);
                                            Renewedd.add(reneweddLabel);
                                            Renewedd.setSize(325,150);
                                            Renewedd.setLayout(null);
                                            Renewedd.setVisible(true);

                                        }

                                    }
                                });



                            }

                        });


                    }
                    });

            }
        });
//////////////EXIT OR TERMINATE PROGRAM/////////////////
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        // Creating a panel to add buttons
        JPanel p = new JPanel();
        // Adding buttons and textfield to panel
        p.add(createuser);
        p.add(searchUser);
        //p.add(searchItem);
        p.add(exit);
        p.setBackground(Color.white);
        // Adding panel to frame
        home.add(p);
        // Setting the size of frame
        home.setSize(400, 400);
        home.setVisible(true);
    }
}