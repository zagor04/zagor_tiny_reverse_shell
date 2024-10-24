#!/bin/sh

# Ip Address and Port 
read -p "Please enter an ip address: " ip_address
read -p "Please enter a port:  " port_number

# IP Check
if ! echo "$ip_address" | grep -E -q '^([0-9]{1,3}\.){3}[0-9]{1,3}$'; then
    echo "Invalid ip."
    exit 1
fi

# Port check 
if ! [ "$port_number" -ge 1 ] 2>/dev/null || ! [ "$port_number" -le 65535 ] 2>/dev/null; then
    echo "Invalid port. Ip Range: 1 - 65535"
    exit 1
fi

gcc -D SERVER_PORT=$port_number -D SERVER_IP=$ip_address shell.c -o shell
