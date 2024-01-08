import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Math;
import java.nio.file.*;
import java.util.Scanner;
import java.io.IOException;

// Class 1
// Helper class extending JFrame class
public class userInterface extends JFrame {
    public userInterface() {
        ///////////Home Frame///////////////////
        JFrame home;
        JButton createuser, searchUser, searchItem, exit;
        home = new JFrame("Home Screen");
        // Creating a new buttons
        createuser = new JButton("Create Library Card");
        searchUser = new JButton("Search user");
        searchItem = new JButton("Search Item");
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
                        /////RAND ID GENERATED(NEED TO ADD CHECKER SO NO DUPLICATES//////////////
                        boolean uniqueId = false;
                        int rand;
                        String randId;
                        while (uniqueId == false) {
                          uniqueId = true;
                          rand = (int)(Math.random()*(10-1+1)+1);
                          randId = Integer.toString(rand);
                          FileSearch fileSearch = new FileSearch();
                          String[] search = {"UserDB.txt", Integer.toString(rand)};
                          if (fileSearch.FileSearch(search)) {
                            uniqueId = false;
                          }
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
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        userSearch.dispose();
                        JFrame userFound;
                        JLabel name;
                        JLabel address;
                        JLabel age;
                        JLabel id;
                        JLabel itemsChecked;
                        JButton returnItem;
                        JButton renewItem;
                        name = new JLabel("Name: ");
                        address = new JLabel("Address: ");
                        age = new JLabel("Age: ");
                        id = new JLabel("ID: ");
                        itemsChecked = new JLabel("Items currently checked out: ");
                        returnItem = new JButton("Return Item");
                        renewItem = new JButton("Renew Item");
                        userFound = new JFrame("User Found");
                        name.setBounds(15,25,200, 50);
                        address.setBounds(15,75,200, 50);
                        age.setBounds(15,125,200, 50);
                        id.setBounds(15,175,200, 50);
                        returnItem.setBounds(15,255,100, 30);
                        renewItem.setBounds(115,255,100, 30);
                        itemsChecked.setBounds(15,225,200, 50);
                        String tempSearch;
                        //////////////////Currently Working on(Search is not implemented)//////////////////
                        if(! searchName.getText().isEmpty()) {
                            tempSearch = searchName.getText();
                            new SearchUser(tempSearch);
                            //System.out.println(tempSearch);
                        }
                        userFound.setSize(500, 500);
                        userFound.add(name);
                        userFound.add(address);
                        userFound.add(age);
                        userFound.add(id);
                        userFound.add(itemsChecked);
                        userFound.add(renewItem);
                        userFound.add(returnItem);
                        userFound.setBackground(Color.white);
                        userFound.setLayout(null);
                        userFound.setVisible(true);
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
        p.add(searchItem);
        p.add(exit);
        p.setBackground(Color.white);
        // Adding panel to frame
        home.add(p);
        // Setting the size of frame
        home.setSize(400, 400);
        home.setVisible(true);
    }
}
