// John Conway's Game of Life Implemented in Java
// Carson Holland
// November 2022
// 
// ***********************************************************
// * 1. A Living Cell with less than 2 living neighbors dies *
// * 2. A Living Cell with 2 or 3 living neighbors lives on  *
// * 3. A Living Cell with 3+ Neighbors dies                 *
// * 4. A Dead Cell with exactly 3 neighbors will gain life  *
// ***********************************************************
package game;
import java.io.*;
import java.nio.file.*;
import java.nio.file.Files;

public class Main
{
    public static void main(String[] args) throws IOException 
    {
        //Variable Declarations----------------------------------------------------------------------------------------------
        char[][] initialData = new char[20][20];
        int iterations;
        
        //Establish the link to the .txt file-------------------------------------------------------------------------------
        String pathname = "C:\\Users\\Carson Holland\\Desktop\\Fall 2022\\Object Programming\\Game Of Life\\gameInitial.txt";
        Path filePath = Paths.get(pathname);

        //Reading the File's contents-------------------------------------------------------------------------------------
        System.out.println("readString");
        String content = Files.readString(filePath);
        System.out.println(content);

        //Splitting the entire file contents into an array of each line, splitting at \n-----------------------------------
        String[] splitlines = content.split("\n");

        //Converting String Lines Array into Character [][] Array-------------------------------------------------------------
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 20; j++)
                initialData[i][j] = splitlines[i].charAt(j);
            
        //Getting the last line into the iterations variable
        iterations = Integer.parseInt(splitlines[20]);


        //Contructing the main Game Grid Object-----------------------------------------------------------------------------
        GameGrid mainGameGrid = new GameGrid(initialData);
        System.out.println("The initial Main Game Grid:");
        mainGameGrid.DisplayGrid();
    

        //Run the rules methodes for iteration number of times to play the game----------------------------------------------
        for (int i = 0; i < iterations; i++)
        {
            mainGameGrid.nextGeneration();
            System.out.println("Iteration #" + Integer.toString(i+1) + ":");
            mainGameGrid.DisplayGrid();
        }

    }
}