echo "Enter the number"
read n
num=0
while (($n > 0))
do
num=$(expr $num \* 10)
k=$(expr $n % 10)
num=$(expr $num + $k)
n=$(expr $n / 10)
done
echo "Reverse is: $num"