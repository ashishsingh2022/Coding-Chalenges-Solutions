#!usr/bin/bash 
echo "Enter Commit Messge"
read message
git add .
git commit -m "$(date +%m-%d-%Y) $message"
echo "Push To Remote ?"
read option
if option="Y"
then
  git push
fi






