#! /usr/bin/bash
echo "Enter Sol No"
read sol
rm -f "$sol.cpp"
cp sample.cpp "$sol.cpp"
