#!usr/bin/env bash

# set the GITHUB_USER variable
GITHUB_USER=Fernando-Ibarra

# read the GITHUB_USER from the environment
user=$GITHUB_USER

# concatenate the user with the github url
url=https://api.github.com/users/$user


# save the user information in a variable
user_info=$(curl -s $url)

# create the folder tmp/$todayDate if it doesn't exist
todayDate=$(date +"%d_%m_%Y")
mkdir -p /tmp/$todayDate

# save the user information in a file and show
echo "Hola" $(echo $user_info | jq -r '.name'). "User ID:" $(echo $user_info | jq -r '.id'). "Cuenta creada el:" $(echo $user_info | jq -r '.created_at'). > \
/tmp/$todayDate/saludos.log && \
cat /tmp/$todayDate/saludos.log