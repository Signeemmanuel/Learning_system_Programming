echo -e "Enter password: \c"
read password

while [ "$password" != "secret" ]
do
    echo -e "Echo try again: \c"
    read password
done

echo "Your Entered the right password!"