read -p "Enter value of n: " n
sum=0
for (( i=1; i<=n; i++ ))
do
    echo "$i"
    sum=$((sum + $i))
done
echo "The sum of $n numbers is: $sum"