# NAME: Afton Schwendiman
# CS 4350 - Unix Systems Programming
# Section Number: 001
# Assignment Number: 3
# Due Date: 10/4/2021 no later than 5:15 pm.

#!/bin/bash

# 1. FUnction that adds all the integers and returns the square of the sum of the integers.  Display the result in the main script.
square_sum() {
  local sum=$(($1 + $2 + $3))
  local square=$(($sum * $sum))
  echo $square
}

# 2. Function that determines and display whether each integer is odd, or even.
is_even_odd() {
  if [[ $(($1%2)) -eq 0 ]]; then
    echo "$1 is even"
  else
    echo "$1 is odd"
  fi
}

# 3. Function that finds and displays all odd and even numbers between 1 and the second integer.
find_even_odd() {
  seq -s, $2 2 $1
}

# 4. Function that determines whether third integer is prime.  Display the result in main script.
is_prime() {
  local prime=0
  for ((i = 2 ; i < $1; i++)); do
    if [[ $(($1%$i)) -eq 0 ]]; then
      prime=$((prime + 1))
    fi
  done
  if [[ $prime > 0 ]]; then
    echo "not a prime number."
  else
    echo "a prime number."
  fi
}

# 5. Function that separates and displays the digits of the second integer.
sep_digits() {
  for (( i = 0; i < ${#1}; ++i )); do echo -n "  ${1:$i:1}"; done
}

# 6. Function that takes the first integer and returns the sum of its digits.  Display the result in main.
sum_digits() {
  local sum=0
  for (( i = 0; i < ${#1}; ++i )); do
    sum=$((sum + ${1:$i:1}))
  done
  echo $sum
}

# 7. Function that finds the smallest of the integer numbers. Display the result in main.
find_smallest() {
  if [[ $1 -lt $2 && $1 -lt $3 ]]; then
    echo $1
  elif [[ $2 -lt $1 && $2 -lt $3 ]]; then
    echo $2
  else
    echo $3
  fi
}

# 8. Function that finds the largest of the integer numbers.  Display the result in main.
find_largest() {
  if [[ $1 -gt $2 && $1 -gt $3 ]]; then
    echo $1
  elif [[ $2 -gt $1 && $2 -gt $3 ]]; then
    echo $2
  else
    echo $3
  fi
}

# Function to randomly generate a number within required range
rand_num() {
  local min=99
  local max=399
  local range="$min - $max + 1"
  local number=$RANDOM
  let "number %= $range"
  let "number += $min"
  echo $number
}

main() {
  echo "This script that will generate and display 3 distinct random numbers that are between 99 and 399 and it will perform some calculations."
  echo

  local ans=0
  while [[ $ans != "Generate" && $ans != "Exit" ]]; do
    echo "Select one of the following"
    echo
    echo "1) Generate - Generate numbers and perform some calculations"
    echo "2) Exit"
    echo
    echo
    echo "Enter your selection: "
    echo
    read ans
    echo
    if [[ $ans != "Generate" && $ans != "Exit" ]]; then
      echo "Invalid Selection"
    fi
    echo
  done

  while [[ $ans == "Generate" ]]; do
    local val1=$(rand_num)
    local val2=$(rand_num)
    while [[ $val2 -eq $val1 ]]; do
      val2=$(rand_num)
    done
    local val3=$(rand_num)
    while [[ $val3 -eq $val1 || $val3 -eq $val2 ]]; do
      val3=$(rand_num)
    done
    echo "The generated numbers are   $val1   $val2   $val3"
    echo

    # Calculate and display the following:
    # 1. FUnction that adds all the integers and returns the square of the sum of the integers.  Display the result in the main script.
    echo "1) Squaring the sum of $val1 , $val2 , and $val3 is : $(square_sum $val1 $val2 $val3)"
    echo

    # 2. Function that determines and display whether each integer is odd, or even.
    echo "2) $(is_even_odd $val1), $(is_even_odd $val2), $(is_even_odd $val3)"
    echo
    echo

    # 3. Function that finds and displays all odd and even numbers between 1 and the second integer.
    echo "3) All odd numbers between 1 and the second number ($val2) are: "
    echo
    echo $(find_even_odd $val2 3)
    echo
    echo
    echo "3) All even numbers between 1 and the second number ($val2) are: "
    echo
    echo $(find_even_odd $val2 2)
    echo
    echo

    # 4. Function that determines whether third integer is prime.  Display the result in main script.
    echo "4) The third number ($val3) is $(is_prime $val3)"
    echo
    
    # 5. Function that separates and displays the digits of the second integer.
    echo "5) The second number ($val2) separated: $(sep_digits $val2)"
    echo

    # 6. Function that takes the first integer and returns the sum of its digits.  Display the result in main.
    echo "6) Sum of digits of the first number ($val1) is: $(sum_digits $val1)"
    echo

    # 7. Function that finds the smallest of the integer numbers. Display the result in main.
    echo "7) Smallest of ($val1, $val2, and $val3) is: $(find_smallest $val1 $val2 $val3)"
    echo

    # 8. Function that finds the largest of the integer numbers.  Display the result in main.
    echo "8) Largest of ($val1, $val2, and $val3) is: $(find_largest $val1 $val2 $val3)"
    echo
    echo

    ans=0
    while [[ $ans != "Generate" && $ans != "Exit" ]]; do
      echo "Select one of the following"
      echo
      echo "1) Generate - Generate numbers and perform some calculations"
      echo "2) Exit"
      echo
      echo
      echo "Enter your selection: "
      echo
      read ans
      echo
      if [[ $ans != "Generate" && $ans != "Exit" ]]; then
        echo "Invalid Selection"
      fi
      echo
    done
  done
  if [[ $ans == "Exit" ]]; then
    echo "End of script"
    echo "Implemented by Afton Schwendiman - 10-4-2021"
  fi
}

main





