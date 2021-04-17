#!usr/bin/bash 
echo "Enter Commit Messge"
read message
git add .
git commit -m "$(date +%F) $message" --author="Ashish Singh"
echo "Push To Remote ?"
read option
if option="Y"
then
  git remote set-url origin git@github.com:ashishsingh2022/Competative_Coding.git
  git remote add origin git@github.com:ashishsingh2022/Competative_Coding.git
  git push -u origin main
fi






