#!usr/bin/bash 
echo "Contest Name "  
eval read name  
echo "Contest Link "  
read link



num=$(($(ls -lR | grep ^d | wc -l)))



# Set space as the delimiter
IFS=' '

#Read the split words into an array based on space delimiter
read -a strarr <<< "$name"


# Print each value of the array by using the loop
folder="$num"
for val in "${strarr[@]}";
do
  folder="$folder\ $val"
done

date=$(date +%m-%d-%Y)
time=$(date +%T)
curr_time="$date $time"
 
eval mkdir $folder
eval cp 0_template/*  $folder/
eval cd $folder/

eval touch details.txt
echo $name >> details.txt
echo $curr_time >> details.txt
echo $link>>details.txt
echo "---------------------------------------------------" >> details.txt
echo "Number of Questions Solved = " >> details.txt
echo "Q1 Number Of Submissions ="    >> details.txt
echo "Q2 Number Of Submissions ="    >> details.txt
echo "Q3 Number Of Submissions ="    >> details.txt
echo "Q4 Number Of Submissions ="    >> details.txt
echo "Q5 Number Of Submissions ="    >> details.txt



echo "$folder is Ready ....."



