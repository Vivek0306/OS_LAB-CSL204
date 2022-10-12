echo "Enter the number of lines to print: "
read n

for((i=0; i<n; i++))
do
for((j=1;j<=i+1;j++))
do
echo -n "$j "
done
echo
done
