echo "N: "
read N
num=0
while [ $N -gt 0 ]
do
num=$((num\*10))
k=$(($N%10))
num=$((num+k))
N=$((N%10))
done
echo "Rev: $num"