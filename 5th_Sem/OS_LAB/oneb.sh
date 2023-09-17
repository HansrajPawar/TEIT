#!/bin/bash

export id=1;
book="addressBook.txt"

while true ;
do 
  echo "
  1)Create a Address book 
  2)Insert the data into it 
  3)view
  4)delete
  5)update
  6)exit
  7)Clear file 
  "
  read choice 
  
  case $choice in 
  	
    1)
    touch "$book"
    echo "Address book is created "
    
    ;;
    
    2) 
    
      read -p "Enter Name (Default Name User$id) :- " name
      name=${name:-"user$id"}

      read -p "Enter Name (Default Mobile Number  123457890) :- " num
      num="1234567890"  

      if  ! [[ $num =~ ^[0-9]{10}$ ]]
      then
      {
        echo " You have entered wrong number Default Mobile Number is "
        num="123457890"
      }
      fi
      
      read -p "Enter address :- " address 

      if [ -z $address ]
      then
        echo " Address can't be null Default Address is India "
        address="India"
      fi

      id=$(( id + 1 ))

     echo "ID :- $id Name :- $name Mobile Number :- $num Address :- $address">>"$book"
    ;;
    3)
    cat "$book"
    ;;

    
    4)

    echo "Enter an ID ";
    read idno ;

    if ! grep "ID :- $idno" "$book" ;
    then
     echo "No Record is found " 
    else
      grep -v "ID :- $idno " "$book" > temp
      mv temp "$book"

      echo "Record is deleted "
    fi
    ;;
5)

  echo "enter id no :- "
  read idno ;

  if ! grep "$idno" "$book" ; then 
  echo "No Record is found."
  return
  fi
    echo "Enter Updated Name :- " 
    read uname

    echo "Enter Updated Mobile No :- " 
    read umno

    echo "Enter Updated Address :- " 
    read uadd

      existing_name=$(grep "ID :- $idno" "$book" | sed -n 's/.*Name :- \(.*\) Mobile.*/\1/p')
      existing_num=$(grep "ID :- $idno" "$book" | sed -n 's/.*Mobile Number :- \(.*\) Address.*/\1/p')
      existing_address=$(grep "ID :- $idno" "$book" | sed -n 's/.*Address :- \(.*\)$/\1/p')

      # Use sed to update the record in the book file
      sed -i "/ID :- $idno/c\ID :- $idno Name :- ${uname:-$existing_name} Mobile Number :- ${umno:-$existing_num} Address :- ${uadd:-$existing_address}" "$book"

      # Check if any field was updated
      if [[ "$uname" != "$existing_name" || "$umno" != "$existing_num" || "$uadd" != "$existing_address" ]]; then
          echo "Record is updated."
      else
          echo "No changes made to the record."
      fi

   
;;

    6)
      exit 0;
    ;;
    *)
    echo "Wrong number bhai "
    ;;
    
   esac
 done 
    
