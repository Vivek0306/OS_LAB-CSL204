echo "Enter the string: "
read string
len=${#string}
for ((i=len-1; i>=0; i--))
do
rev+=${string:$i:1}
done

echo "Reversed string is: $rev"