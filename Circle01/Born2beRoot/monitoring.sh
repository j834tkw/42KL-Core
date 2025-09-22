#!/bin/bash
arc=$(uname -a)
pproc=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)
vproc=$(nproc --all)
mem=$(free -m | grep Mem | awk '{printf"%s/%sMb (%.2ff%%)", $3, $2, ($3/$2)/100}')
disk=$(df -Bm | grep '^/dev/' | grep -v '^/boot$' | awk '{total += $2} {used += $3} END {printf("%d/%dGb", used, total/1024)}')
diskpercent=$(df -Bm | grep '^/dev/' | grep -v '^/boot$' | awk '{total += $2} {used += $3} END {printf("(%.1f%%)", total/used)}')
cpuload=$(top -bn1 | grep '^%Cpu' | awk '$1 == "%Cpu(s):" {printf("%.1f%%", $2+$4)}')
rbt=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvm=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvm -eq 0 ]; then echo no; else echo yes; fi)
ac=$(netstat -ant | grep "ESTABLISHED" | wc -l)
users=$(users | wc -w)
ivp4=$(hostname -I)
mac=$(cat /sys/class/net/*/address | head -1)
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall            "
                #Architecture: $arc
                #CPU Physical: $pproc
                #vCPU: $vproc
                #Memory Usage: $mem
                #Disk Usage: $disk $diskpercent
                #CPU load: $cpuload
                #Last Boot: $rbt
                #LVM Use: $lvmu
                #Connections TCP: $ac ESTABLISHED
                #User Log: $users
                #Network: IP $ivp4 ($mac)
                #Sudo: $sudo cmd
                "