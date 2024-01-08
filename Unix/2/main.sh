#!/bin/sh
install-pkg bc
: '
Name: Afton Schwendiman
CS 4350 - Unix Systems Programming
Section Number: 001
Assignment Number: 2
Due Date: 9/22/2021 no later than 5:15 pm.

Simple Math Application Using Shell Scripts

The function of this script is to accept four positive integer values \(points\) on a circle between 0 - 10000.  The script will calculate and display
the circle radius, circumference, area, and diameter.
'

echo "Simple Math Application Using Shell Scripts"
echo "By entering four integer values form the keyboard, the application will calculate the circle radius, circumference, area, and diameter."

pi=3.14159
ans="Y"
while [[ $ans == "Y" ]]
  do
    echo "Enter four integer values (X1, X2, Y1, Y2): "
    read x1 x2 y1 y2

    if [[ $x1 -lt 0 || $x2 -lt 0 || $y1 -lt 0 || $y2 -lt 0 ]]; then
      echo "Error - Integer values must be >= 0"

    elif ! [[ $x1 =~ ^[0-9]+$ && $x2 =~ ^[0-9]+$ && $y1 =~ ^[0-9]+$ && $y2 =~ ^[0-9]+$ ]]; then
      echo "Error - Must input 4 integer Values"

    else
      radius=`echo "scale=6; sqrt((($x2-$x1)*($x2-$x1))+(($y2-$y1)*($y2-$y1)))" | bc`
      circumference=`echo "scale=6; 2*$pi*$radius" | bc`
      area=`echo "scale=6; $pi*$radius*$radius" | bc`
      diameter=`echo "scale=6; sqrt((4*$area)/$pi)" | bc`

      printf "The radius is           :       %.2f \n" $radius
      printf "The circumference is    :       %.2f \n" $circumference
      printf "The area is             :       %.2f \n" $area
      printf "The diameter is         :       %.2f \n" $diameter
    fi
    echo -n "Run the script again? Y|N "
    read -n 1 ans
    while [[ $ans != "Y" && $ans != "N" ]]
      do
        echo
        echo "Error - Must input Y or N"
        echo "Run the script again? Y|N "
        read -n 1 ans
    done
    echo
done
echo "The script is implemented by Afton Schwendiman"
echo "9-22-2021"