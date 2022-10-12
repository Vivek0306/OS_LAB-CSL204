echo "Calculator"
echo "1.ADD 2.SUB 3.MUL 4.DIV 0.EXIT"
ch=1

while ((ch!=0))
do
echo "Enter your choice: "
read ch

case $ch in
1)
echo "Enter the two numbers: "
read a
read b
echo "Sum is: $((a+b))"
;;

2)
echo "Enter the two numbers: "
read a
read b
echo "Diff is: $((a-b))"
;;

3)
echo "Enter the two numbers: "
read a
read b
echo "Prod is: $((a*b))"
;;

4)
echo "Enter the two numbers: "
read a
read b
echo "Div is: $((a/b))"
;;

0)
;;

*)
echo "Invalid choice"
esac

done

