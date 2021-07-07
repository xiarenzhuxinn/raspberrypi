#!/bin/bash
path="$(dirname $(readlink -f "$0"))"
git status | awk /修改：/'{print$2}' > $path/tmp
git status | awk /删除：/'{print$2}' >> $path/tmp
snum=`git status | grep -n "未跟踪的文件" | awk -F ":" '{print$1}'`
enum=`git status | grep -n "修改尚未加入提交" | awk -F ":" '{print$1}'`
git status | head -$[$enum-2] | tail -$[$enum-$snum-4] >> $path/tmp
for line in `cat $path/tmp`
do
	git add $line
done
git commit -m "modify"
#git push
expect -c "
set timeout -1
spawn git push
expect \"Username for*\"
send -- \"xiarenzhuxinn\r\"
expect \"Password*\"
send \"Ljxljx19986!7\r\"
#interact
expect eof"
