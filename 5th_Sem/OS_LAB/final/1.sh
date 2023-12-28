#!/bash/bin


while true; do

	echo "1.Create DB "
	echo "2.Insert"
	echo "3.search"
	echo "4.Display"
	echo "7.Exit"
	read ch

	case "$ch" in
		1)
			echo "Enter a Database name :- "
			read db 
			if [ -f "$db" ]; then
				echo "File available "
			else
				touch "$db"
				echo "creating file "
				if [ -f "$db" ]; then
					id=$(tail -n 1 "$db" | cut -d ' ' -f 1)
					id=$((id+1))
				else
					id=1
				fi
			fi
			;; 
		2)
			echo "enter a database name you want to add "
			read db 

			if [[ -f "$db" ]] ;then

				echo "Enter the student name student "
				read name 


				while true; do
					echo "Mobile No: "
					read mono

					if ! [[ "$mono" =~ ^[0-9]{10}$ ]]; then
						echo "Mobile number should be exactly 10 digits."
					elif grep -q "^$mono" "$db"; then
						echo "Mobile number is not unique."
					else
						break
					fi
				done




				while true; do 
					read -p "Enter email :-" email

					if [[ "$email" == *"@"* ]]; then
							break
					else
						echo "invalid"
					fi
				done
				


				echo "Enter city"
        		read city

				data="$id $name $city $mono $email"
				
				echo $data >> $db 	
				echo "Record Inserted Successfully"
				
				id=$((id+1));
			
			else
                echo "Database file not found"
			fi 

		;;
		3)
			echo "enter a id " 
			read sid 

		echo "Enter the db in which you want to search: "
		read db
		if [ -f "$db" ]; then
			echo "Enter the student id which you want to search: "
			read sid
			data=$(grep "^$sid" $db)
			if [ -z "$data" ];then 
				echo "Record not found"
			else
				echo "Record found"
				echo "$data"
			fi
		
		else 
			echo "DB doesnt exists"
		fi

		;;
		4)
			echo "Enter name of the db which you have display: "
				read db
				if [ -f "$db" ];then
					cat $db
				else
					echo "DB doesnt exist!"
				fi
			;;
		
		5)
			echo "Enter the db in which you want to delete: "
			read db
			if [ -f "$db" ]; then
				echo "Enter the student id which you want to delete: "
				read did
				if grep -q "^$did" "$db";then
					grep -v "^$did" "$db" > temp_db && mv temp_db "$db"
					echo "Record deleted!"
				else
					echo "Record not found!"
				fi
			else
				echo "DB not found"
			fi
		;;

		6)
			echo "Enter the address book name in which data has to modify"
			read ab
			if [ -e "$ab" ]; then
				echo "Enter the id of the entry in which data has to modify"
				read modifyId
				echo "Enter the new data (ID Name Phone City):"
				read newdata
				sed -i "/^$modifyId/c$newdata" $ab
				echo "Entry modified successfully"
			else
				echo "File does not exist"
			fi
		;;

		7)
			echo "Existing  " 
			exit 0
			;;
		*)
			echo "Wrong Number bhai " 
			exit 0
			;;
		esac
	done