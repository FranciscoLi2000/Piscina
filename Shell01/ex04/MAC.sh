#!/bin/sh

#ifconfig | grep "ether" | awk '{print $2}'

ip link show | grep link/ether | awk '{print $2}'
