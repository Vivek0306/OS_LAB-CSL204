echo "Enter the first num"
read num1
echo "Enter the second num"
read num2
echo "Before swapping: num1 = $num1 and num2 = $num2"

num2=$((num2+num1))
num1=$((num2-num1))
num2=$((num2-num1))

echo "After swapping: num1 = $num1 and num2 = $num2"
