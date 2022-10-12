echo "1. F to C Conversion"
echo "2. C to F Conversion"
echo "Enter your choice: "
read n

if ((n==1))
then
echo "Enter the temp in F: "
read F
echo "Temp in C = " $(echo "scale=2; ($F-32)*5/9" | bc)

elif ((n==2))
then
echo "Enter the temp in C: "
read C
echo "Temp in F = " $(echo "scale=2; ($C*9/5)+32" | bc)

else
echo "Invalid choice"

fi