echo "Enter the 3 nums: "
read num1
read num2
read num3

if (($num1 > $num2 && $num1 > $num3))
then
echo "num1 is the largest"

elif (($num2 > $num3))
then
echo "num2 is the largest"

else
echo "num3 is the largest"

fi