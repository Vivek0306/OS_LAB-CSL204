i="$#"
sum=0
for j in "$@"
do
sum=$((sum+j))
done
echo "Average is: " $(echo "scale=2; $sum/$i" | bc)