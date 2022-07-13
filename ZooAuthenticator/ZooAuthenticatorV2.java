package zooauthenticator;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 * SNHU IT 145
 * Zoo Authentication System - Final Project
 * @author Andrew Swarr
 */
public class ZooAuthenticator {
    public static void main(String[] args) throws FileNotFoundException, Exception {
        File Text = new File("src\\zooauthenticator\\credentials.txt");
        String line = "";
        String userName = " ";
        String userPassword = " ";
        String exit = " ";
        int loginAttempts = 0; //Tracking login attempts
        int lineNumber = 1; //To advance lines in the documents
        Scanner scnr = new Scanner(System.in); //For collecting user input
        Scanner reader = new Scanner(Text); //For parsing the documents
        MD5Hash hashWord = new MD5Hash(); //MD5 hash password converter
        FileHandler fileReader = new FileHandler(); //File reader
        boolean containsPassword = false; //booleans to fight infinite loops
        boolean containsUsername = false;
		
		System.out.println("Enter username:");
		userName = scnr.nextLine();
        if (line.contains.(userName){
			
		}
        while (loginAttempts < 3) { //Limits login attempts to 3
            System.out.println("Enter username");
            userName = scnr.nextLine();
            while(reader.hasNextLine() && containsUsername == false){ //added second boolean to prevent infinite loop
                line = reader.nextLine();
                while(line.contains(userName) && containsPassword == false){
                    containsUsername = true;
                    System.out.println("Enter password");
                    userPassword = scnr.nextLine();
                    if(line.contains(hashWord.getMD5Hash(userPassword))){ //Looks for hashed password in the line
                        containsPassword = true; //Following IF statements look for user role and display role specific file
                            if (line.contains("zookeeper")){
                                System.out.println("Zookeeper");
                                System.out.println(Arrays.toString(FileHandler.readFile("src\\zooauthenticator\\zookeeper.txt")));
                                System.out.println("Type \"exit\" to exit the program");
                                exit = scnr.next();
                                if(exit.equalsIgnoreCase("exit"));
                                loginAttempts = 3;
                            }
                            if (line.contains("admin")){
                                System.out.println("admin");
                                System.out.println(Arrays.toString(FileHandler.readFile("src\\zooauthenticator\\admin.txt")));
                                System.out.println("Type \"exit\" to exit the program");
                                exit = scnr.next();
                                if(exit.equalsIgnoreCase("exit"));
                                loginAttempts = 3;
                            }
                            if (line.contains("veterinarian")){
                                System.out.println("veterinarian");
                                System.out.println(Arrays.toString(FileHandler.readFile("src\\zooauthenticator\\veterinarian.txt")));
                                System.out.println("Type \"exit\" to exit the program");
                                exit = scnr.next();
                                if(exit.equalsIgnoreCase("exit"));
                                loginAttempts = 3;
                            }
                    }
                    else {
                        loginAttempts++; // Failed password section, incraments loginAttempts and sends the user back to enter a password
                        System.out.println("Incorrect password " + (3 - loginAttempts) + " login attempts remaining");                        
                    }
                }
                lineNumber++; //Moves scanner to the next line to search for the entered userName
                }
            if(containsUsername == false) {
            loginAttempts++; // Failed username section, incraments loginAttempts and sends user back to re-enter their username
            System.out.println("Incorrect username " + (3 - loginAttempts) + " login attempts remaining");
            lineNumber = 1; // Resets the line back to 1 so the scanner goes to 
            }               // the begining again. Previous attempts even correct 
            }               // usernames would still yeild "incorrect" message, 
                            // caused by while loop not being re-entered
        }
}
    