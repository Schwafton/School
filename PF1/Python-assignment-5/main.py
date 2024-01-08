def main():

# Function: about_function
# Purpose: To explain the purpose of the program
# Input parameters: None
# Returns: None
# Called by: main()
# Calls: None
# Global variables used: None
# If any global variables were used, explain why:
  def about_function():
    print("""This program will read a file of richter measurements into a list, then read the contents of the list into a separate output file.  The list will be stripped of newline characters and invalid values, then list elements will be placed in ascending order.  The smallest and largest values in the list are determined.  The resulting list and min/max values are written to the output file.\n""")

# Beginning of try/except block
  try:
# Call to function that explains the purpose of the program.
    about_function()

# Asks user for user input to continue with program.
    print("Press enter to begin!")
    input()

# Open quakesL5.txt in read mode.
    infile = open('quakesL5.txt', 'r')

# Open quakes5.txt in write mode.
    outfile = open('afton_schwendiman_quakes5.txt', 'w')

# Read contents of infile into a list using readlines()
    quakesList = []
    quakesList = infile.readlines()

# Write quakesList contents to outfile using loop and strip endline characters    
    index = 0
    while index < len(quakesList):
      outfile.write(quakesList[index])
      quakesList[index] = quakesList[index].rstrip('\n')
      index += 1

# Remove 11 and -111 from List
    quakesList.remove('11')
    quakesList.remove('-111')

# Find smallest and largest values in List
    minimum = min(quakesList)
    maximum = max(quakesList)

# Sort List in ascending order
    quakesList.sort()

# Inserts list title
    quakesList.insert(0,'The sorted List\n')

# Append \n to each list item and write each list item to outfile
    index = 0
    for item in quakesList:
      quakesList[index] = item+'\n'
      outfile.write(quakesList[index])
      index += 1
  
# Write min/max values to outfile
    outfile.write("Minimum: " + str(minimum) + "\n" + "Maximum: " + str(maximum))

    print("Done.")

# Exception clause of try/except block.  Notifies user an error has occurred, and displays error information.
  except Exception as e:
    print("An error has occurred.")
    print("error: ", e)

# Finally clause includes file closures.
  finally:

# Close files
    infile.close()
    outfile.close()

main()