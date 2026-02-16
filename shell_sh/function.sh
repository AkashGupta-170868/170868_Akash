# description : a function that ask choice weather the user want to continue the program or nt ?  
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026

askagain(){
while true; do
    echo
    echo "1. Enter the program"
    echo "2. Exit"
    read -p "Enter your choice: " choice

    case "$choice" in
        1) main ;;
        2) echo "exiting..."; exit 0 ;;
        *) echo "invalid choice" ;;
    esac
done
}
#--------------------------------------------------------------------------------------------------------------------------
# description :a script to check if a given string is a palindrome.
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026
is_palindrome() {

    input="$1"

    # remove surrounding quotes
    input="${input%\"}"
    input="${input#\"}"

    # check for only spaces
    if [[ -z "$(echo "$input" | tr -d ' ')" && -n "$input" ]]; then
        echo "cannot enter empty string"
        return
    fi

    # check for empty string
    if [[ -z "$input" ]]; then
        echo "This is a empty string"
        return
    fi

    # remove spaces and convert to lowercase
    clean=$(echo "$input" | tr -d ' ' | tr 'A-Z' 'a-z')

    rev_str=$(echo "$clean" | rev)

    if [[ "$clean" == "$rev_str" ]]; then
        echo "The string '$input' is a palindrome."
    else
        echo "The string '$input' is not a palindrome."
    fi
}

#----------------------------------------------------------------------------------------------------
#Q05
# description :takes a directory as input, creates a backup of all .txt files, and stores them in a compressed archive with the current date as the filename. (create txt file in your home directory)
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026
valid_dir() {

    input="$1"
    path="${input/#\~/$HOME}"

    # if argument is empty or numeric
    if [[ -z "$path" || "$path" =~ ^[0-9]+$ ]]; then
        path="$HOME"
    fi

    # if file given
    if [[ -f "$path" ]]; then
        echo "this $(basename "$path") file not found"
        return
    fi

    # if directory does not exist
    if [[ ! -d "$path" ]]; then
        echo "this $(basename "$path") directory not found"
        return
    fi

    create_tar_backup "$path"
}

create_tar_backup() {

    dir="$1"
    date=$(date +%F)
    backupfile="$HOME/backup_${date}.tar.gz"

    # find only txt files in SAME directory (not subfolders)
    txt_files=$(find "$dir" -maxdepth 1 -type f -iname "*.txt")

    if [[ -z "$txt_files" ]]; then
        echo "Folder does not contain any txt files"
        return
    fi

    tar -czf "$backupfile" $txt_files 2>/dev/null
    echo "filename: $(basename "$backupfile") in home directory"
}

#---------------------------------------------------------------------------------------------------------------------
# description :checks if a specific process (given as an argument) is running and prints a message if it is not.     
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026
#Q06
is_pid() {
	
if [[ "$1" =~ ^[0-9]+$ ]]; then
    # Input is PID
    if ps -p "$1" > /dev/null 2>&1; then
        echo "Process with PID is running"
    else
        echo " not running"
    fi
else
    
    pid=$(pgrep "$1")

    if [[ -n "$pid" ]]; then
        echo "running "
    else
        echo "not"
    fi
fi
}



#---------------------------------------------------------------------------------------------------------------------
# description : adds a new user to the system (requires root privileges) and a default password.      
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026

#Q07
#Q07
add_user() {

DEFAULT_PASSWORD="password123"
username="$1"

# check if script is run as root
if [[ "$EUID" -ne 0 ]]; then
    echo "run script in root mode"
    exit 1
fi

# remove surrounding double quotes
username="${username%\"}"
username="${username#\"}"

# trim leading and trailing spaces
username="$(echo "$username" | xargs)"

# check if username is empty
if [[ -z "$username" ]]; then
    echo "username can not be empty"
    exit 1
fi

# check if username contains internal spaces
if [[ "$username" == *" "* ]]; then
    echo "username cant contain spaces"
    exit 1
fi

# check if user already exists
if id "$username" &>/dev/null; then
    echo "user already exists"
    exit 1
fi

# add user
useradd "$username"
if [[ $? -ne 0 ]]; then
    echo "invalid input"
    exit 1
fi

# set default password
echo "$username:$DEFAULT_PASSWORD" | chpasswd

echo "\"$username\" has been added"
}



#--------------------------------------------------------------------------------------------------------------------------
# description :checks the size of a specified directory and warns if it exceeds a certain limit (e.g., 100MB).
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026
#Q8
dir_size() {
    dir=$1
    LIMIT=100

    # consider ~ as home directory
    dir="${dir/#\~/$HOME}"

    # check empty input
    if [[ -z "$dir" ]]; then
        echo "enter valid directory path"
        return 1
    fi

    # if path does not exist
    if [[ ! -e "$dir" ]]; then
        echo "this test directory not found"
        return 1
    fi

    # if not a directory
    if [[ ! -d "$dir" ]]; then
        echo "this $dir file is not a directory"
        return 1
    fi

    # permission check
    if [[ ! -r "$dir" ]]; then
        echo "permission denied"
        return 1
    fi

    # display directory size in MB
    size=$(du -sm "$dir" 2>/dev/null | awk '{print $1}')

    echo "The size of the directory $dir is ${size}MB."

    if (( size > LIMIT )); then
        echo "The size exceeds the ${LIMIT}MB limit!"
    else
        echo "The size is within the ${LIMIT}MB limit."
    fi
}



#---------------------------------------------------------------------------------------------------------------------------


# description :to search for a given file name recursively in a specified directory and print the full path if found.
# Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026

#Q9
search() {
    read -p "Enter the file name to search for: " filename
    read -p "Enter the directory to search: " dir

    # empty filename
    if [[ -z "$filename" ]]; then
        echo "file name cannot be empty"
        return 1
    fi

    # empty directory name
    if [[ -z "$dir" ]]; then
        echo "directory name can not be empty"
        return 1
    fi

    # ~ to be considered as home directory
    dir="${dir/#\~/$HOME}"

    #invalid directory
    if [ ! -d "$dir" ]; then
        echo "the directory $dir does not exists"
        return 1
    fi

    result=$(find "$dir" -type f -name "$filename" 2>/dev/null)

    # Tc1, Tc6: found case format
    if [ -n "$result" ]; then
        echo "Found $filename at: $result"
    else
        # Tc2: not found case format
        echo "file $filename not found in $dir"
    fi
}


#------------------------------------------------------------------------------------------------------------------------------------
#Q10


# description : a function that generates a random password of a given length using alphanumeric and special characters.
# Author: Akash Gupta
# Created: 19 January 2026
# Modified: 20 January 2026

password() {

	while true ;
	do
read -p "Enter the password length: " length

if [ -z "$length" ]; then
echo "Password length cannot be empty."
return
fi

if ! [[ "$length" =~ ^-?[0-9]+$ ]]; then
echo "invalid input provided this is a not numeric value"
return
fi

if [ "$length" -lt 0 ]; then
echo "Password length must be positive value"
return
fi

if [ "$length" -eq 0 ]; then
echo "password length must be greater than 0."
return
fi
chars='A-Za-z0-9!@#$%^&*()_+=-{}[]:;<>?,.'

password=$(tr -dc "$chars" < /dev/urandom | head -c "$length")

echo "Generated password: $password"
return 0;
done

}
#------------------------------------------------------------------------------------------------------------------------------------
#Q11.

#description: function that monitors CPU and memory usage, logs the data to a file, and alerts if usage exceeds a specified threshold.
# Author: Akash Gupta                                                               
# Created: 19 January 2026 
# Modified: 20 January 2026



cpu_info() {
    logfile="system_usage.log"

    read -p "Enter the CPU usage threshold (e.g., 80 for 80%): " cpu_th
    read -p "Enter the memory usage threshold (e.g., 90 for 90%): " mem_th

    # Empty input check
    if [[ -z "$cpu_th" ]]; then
        echo "CPU usage threshold cannot be empty."
        return 1
    fi

    if [[ -z "$mem_th" ]]; then
        echo "Memory usage threshold cannot be empty."
        return 1
    fi

    # Numeric check (allow decimal)
    if ! [[ "$cpu_th" =~ ^[0-9]+([.][0-9]+)?$ ]]; then
        echo "invalid input"
        echo "provided this is not numeric value for cpu"
        return 1
    fi

    if ! [[ "$mem_th" =~ ^[0-9]+([.][0-9]+)?$ ]]; then
        echo "invalid input"
        echo "provided this is not numeric value for memory"
        return 1
    fi

    # Negative check
    if (( $(echo "$cpu_th < 0" | bc -l) )); then
        echo "CPU usage threshold cannot be negative."
        return 1
    fi

    if (( $(echo "$mem_th < 0" | bc -l) )); then
        echo "Memory usage threshold cannot be negative."
        return 1
    fi

    # Greater than 100 check
    if (( $(echo "$cpu_th > 100" | bc -l) )); then
        echo "cannot be beyond 100%"
        return 1
    fi

    if (( $(echo "$mem_th > 100" | bc -l) )); then
        echo "cannot be beyond 100%"
        return 1
    fi

    # Fetch CPU usage
    cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print 100 - $8}')

    # Fetch Memory usage
    mem_total=$(free | awk '/Mem:/ {print $2}')
    mem_used=$(free | awk '/Mem:/ {print $3}')
    mem_usage=$(echo "scale=2; ($mem_used/$mem_total)*100" | bc)

    # Log data (append)
    echo "$(date) CPU=${cpu_usage}% MEM=${mem_usage}%" >> "$logfile"

    # Alerts
    if (( $(echo "$cpu_usage > $cpu_th" | bc -l) )); then
        echo "CPU usage is ${cpu_usage}%. Exceeds threshold of ${cpu_th}%."
    else
        echo "CPU usage is ${cpu_usage}%. Within limit."
    fi

    if (( $(echo "$mem_usage > $mem_th" | bc -l) )); then
        echo "Memory usage is ${mem_usage}%. Exceeds threshold of ${mem_th}%."
    else
        echo "Memory usage is ${mem_usage}%. Within limit."
    fi
}

#------------------------------------------------------------------------------------------------------------------------------------

#Q12

# description :functionthat generates a disk usage report for all mounted file systems and saves it to a file.
# Author: Akash Gupta
# Created: 25 January 2026
# Modified: 25 January 2026

disk_status() {
	while true ; 
	do
read -p "enter the file name to store the log file for disk status " outfile


outfile="${outfile/#\~/$HOME}"
if [[ -z "$outfile" ]];then
	echo " output path can not be empty "
	return 1 ;
fi

if [[ "${outfile##*.}" != "txt" ]]; then
    echo "not valid file path . enter .txt file"
    exit 1
fi

if [[ -f "$outfile" ]];then
        echo "disk used reprot file save and override the data "
else
        echo "file .txt created..disk used report file save"
fi

# Generate disk usage report
{
    echo "Disk Usage Report"
    echo "Generated on: $(date)"
    echo "-------------------------------------"
    df -h
} > "$outfile"

dir_path=$(dirname "$outfile")
if [[ ! -d "$dir_path" ]];then
	echo "invalid path "
	exit 1
fi
echo "Disk usage report generated and saved to $outfile."
return 0 ;
done
}

#----------------------------------------------------------------------------------------------------------------

#Q13


# description : function that tracks and logs user logins and logout events, appending the data to a log file.
# Author: Akash Gupta
# Created: 25 January 2026
# Modified: 25 January 2026


login_info() {
    read -p "Enter the log file path: " log_file

    #If user enters a number, use default path
    if [[ "$log_file" =~ ^[0-9]+$ ]]; then
        log_file="$HOME/logs/login.log"
    fi

    # Expand ~
    log_file="${log_file/#\~/$HOME}"

    # empty input
    if [[ -z "$log_file" ]]; then
        echo "file path not empty"
        return 1
    fi

    # Only .log allowed
    if [[ "${log_file##*.}" != "log" ]]; then
        echo "Enter valid file type"
        return 1
    fi

    dir_path=$(dirname "$log_file")

    # Create dir if possible, else invalid
    if [[ ! -d "$dir_path" ]]; then
        mkdir -p "$dir_path" || {
            echo "invalid file path"
            return 1
        }
    fi

    #Overwrite data
    echo "login tracking started at $(date)" > "$log_file"
    last -n 10 >> "$log_file"
    echo "tracking finished at $(date)" >> "$log_file"

    echo "User login/logout tracking complete. Data saved to $log_file"
}




#---------------------------------------------------------------

#Q14

# description : a function that count the word frequency .
# Author: Akash Gupta
# Created: 27 January 2026
# Modified: 27 January 2026
word_freq() {
while true ;
do

read -p " enter the file name " file

file="${file/#\~/$HOME}";

#empty input
if [[ -z "$file" ]] ; then
        echo "file path can not empty"
        return 1
fi

# only .txt files allowed
if [[ "${file##*.}" != "txt" ]];then
        echo "only .txt files are allowed"
        return 1
fi

# file does not exist
if [[ ! -e "$file" ]]; then
        echo "the file $file does not exists"
        return 1
fi

#file not readable
if [[ ! -r "$file" ]]; then
        echo "cant read this file"
        return 1
fi

# file is empty
if [[ ! -s "$file" ]]; then
        echo "the file $file is empty"
        return 1
fi

if [[ -r "$file" ]];
then
     echo -e "Word frequency analysis: \n-------------------------------------------\n$(cat "$file" | tr '[A-Z]' '[a-z]' | tr " " "\n" | sort | uniq -c | sort -nr | awk '{print $2 " - " $1 " occurrence"}')"
else 
     echo "$file can't read "
fi
return 0;
done
}


#------------------------------------------------------------------------------------------
#Q17
# description : a function that check waether the c file is exits if exits then compile it and save it to be excutable file
# Author: Akash Gupta
# Created: 28 January 2026
# Modified: 27 January 2026
c_log() {
while true;
do
read -p "Enter the C file path: " cfile

# Expand ~ first
cfile="${cfile/#\~/$HOME}"

# empty input
if [ -z "$cfile" ]; then
    echo "input cannot be empty"
    return 1
fi

# only .c file allowed
if [[ "$cfile" != *.c ]]; then
    echo "only .c file take as i/p"
    return 1
fi

#missing file
if [ ! -e "$cfile" ]; then
    echo "missing c file does not exists"
    return 1
fi

#empty file
if [ ! -s "$cfile" ]; then
    echo "that file in log file empty"
    return 1
fi

# Log file name
logfile="${cfile%.c}.log"

# log file input cannot be empty (safety check)
if [ -z "$logfile" ]; then
    echo "log file input cannot be empty"
    return 1
fi

echo $(date) >> "$logfile"
gcc "$cfile" -o temp_exec 2>> "$logfile"

if [ $? -eq 0 ]; then
    ./temp_exec >> "$logfile"
    echo "o/p stored in log file"
else
    echo "Compilation error stored in log file"
fi

rm -f temp_exec
return 0
done
}


#------------------------------------------------------------------------------------------------------------------
#Q15
# description : a function that takes username , gid, firstname , taskname as a input and put all file according to its exte#-nsion
# Author: Akash Gupta
# Created: 26 January 2026
# Modified: 26 January 2026
make_dir() {

read -p "Enter Linux username: " username
read -p "Enter GID: " gid
read -p "Enter Firstname: " firstname
read -p "Enter Taskname: " taskname

# ---------------- VALIDATIONS ----------------

# Empty input check
if [[ -z "$username" || -z "$gid" || -z "$firstname" || -z "$taskname" ]]; then
    echo "All inputs (username, GID, firstname, task ID) are required."
    return 1
fi

# GID must be numeric
if ! [[ "$gid" =~ ^[0-9]+$ ]]; then
    echo "Enter valid GID"
    return 1
fi

# GID length must be exactly 6 OR allow 0 (Tc3)
if [[ "$gid" != "0" && "${#gid}" -ne 6 ]]; then
    echo "Enter valid GID"
    return 1
fi

# Taskname space check
if [[ "$taskname" =~ [[:space:]] ]]; then
    echo "spaces not allowed in taskname use _"
    return 1
fi

# ---------------- DIRECTORY STRUCTURE ----------------

main_dir="${gid}_${firstname}"
task_dir="${main_dir}/${taskname}"

# Main folder exists but subfolder does not
if [[ -d "$main_dir" && ! -d "$task_dir" ]]; then
    echo "Folder exists making subfolders"
    mkdir -p "$task_dir"
elif [[ -d "$task_dir" ]]; then
    # Same input second time
    echo "directory already exists"
    return 0
else
    mkdir -p "$task_dir"
fi

# ---------------- FILE GENERATION ----------------

extensions=(c h sh xls ko a so)

count=1
for ext in "${extensions[@]}"; do
    filename="${gid}_${firstname}_${taskname}_Module1_task${count}.${ext}"
    touch "$task_dir/$filename"
    ((count++))
done

echo "Files created successfully inside $task_dir"
}




#------------------------------------------------------------------------------------------------------------------------------------
#Q16

# description : a function that search keyword kernal panic and segmental fault and checks its from dmesg if it is exits then print yes it is available .
# Author: Akash Gupta
# Created: 28 January 2026
# Modified: 27 January 2026

fault_msg() {
read -p "Enter first keyword: " key1
read -p "Enter second keyword (optional): " key2

# Trim spaces and convert to lowercase
key1=$(echo "$key1" | xargs | tr 'A-Z' 'a-z')
key2=$(echo "$key2" | xargs | tr 'A-Z' 'a-z')

# Empty input validation
if [[ -z "$key1" && -z "$key2" ]]; then
    echo "cannot take empty i/p"
    exit 1
fi

# Kernel log source
LOGFILE="/var/log/kern.log"

if [[ ! -r "$LOGFILE" ]]; then
    LOGDATA=$(dmesg)
else
    LOGDATA=$(cat "$LOGFILE")
fi

found=0

# Function to search keyword
search_log() {
    local keyword="$1"

    if [[ "$keyword" == "panic" ]]; then
        echo "$LOGDATA" | grep -i "panic" && found=1
        [[ $found -eq 1 ]] && echo "panic fault displayed full line with timestamp"
    elif [[ "$keyword" == "segfault" ]]; then
        echo "$LOGDATA" | grep -i "segmentation fault\|segfault" && found=1
        [[ $found -eq 1 ]] && echo "segmentation fault displayed full line with timestamp"
    else
        echo "there is no fault $keyword"
    fi
}

# Process inputs
if [[ -n "$key1" ]]; then
    search_log "$key1"
fi

if [[ -n "$key2" && "$key2" != "$key1" ]]; then
    search_log "$key2"
fi

}


#---------------------------------------------------------------------------------------------------------------------------

#Q18

# description : a function that check waether the c file is follows codinnf standards or not ?                              # Author: Akash Gupta                                                                                                       # Created: 28 January 2026                                                                                                  # Modified: 27 January 2026
# Q18 - Check C coding standards

coding_std() {

    read -p "Enter the C file: " cfile

    # empty input
    if [[ -z "$cfile" ]]; then
        echo "C file cannot be empty input"
        return
    fi

    # expand ~
    cfile="${cfile/#\~/$HOME}"

    # only .c files allowed
    if [[ "${cfile##*.}" != "c" ]]; then
        echo ".c files are allowed"
        return
    fi

    # file existence
    if [[ ! -f "$cfile" ]]; then
        echo "c file not found.c does not exits"
        return
    fi

    # empty file
    if [[ ! -s "$cfile" ]]; then
        echo "this $(basename "$cfile") file empty"
        return
    fi

    # single-line comments not allowed
    if grep -q "//" "$cfile"; then
        echo "// comments are not allowed. only multi line comments are allowed"
        return
    fi

    # multiline comment check (must exist)
    if ! grep -q "/\*" "$cfile"; then
        echo "this $cfile file does not follow coding standards"
        return
    fi



    if ! grep -qi "main()" "$cfile" ;then
	echo" this $cfile file does not follow coding standards ";
	return 
    fi

    if ! grep -qi "author" "$cfile" &&
    grep -qi "description" "$cfile" &&
    grep -qi "created" "$cfile" &&
    grep -qi "modified" "$cfile" ; then
     echo" this $cfile file does not follow coding standards ";
        return
    fi


 echo "this $cfile file follow coding standards"
}





