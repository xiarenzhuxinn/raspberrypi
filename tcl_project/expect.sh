#!/usr/bin/bash
set -x
ip=192.168.192.128
user=ljx
expect -c "
set timeout -1
log_file -a -noappend $user\.log
spawn ssh $user@$ip
expect \"*assword\"
send -- \"1\r\"
#output is printed on the remote console after the password is sent
expect \"~\"
send \"uname -a\r\"
expect \"~\"
send \"exit\r\"
#interact
expect eof"
