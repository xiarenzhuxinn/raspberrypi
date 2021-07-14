#!/bin/bash
path="$(dirname $(readlink -f "$0"))"no changes added to commit
modify=(`git status | awk /修改：/'{print$2}'`)
delete=(`git status | awk /删除：/'{print$2}'`)
snum=${snum:=`git status | grep -n "Untracked files:" | awk -F ":" '{print$1}'`}
snum=${snum:=`git status | grep -n "未跟踪的文件:" | awk -F ":" '{print$1}'`}
enum=${enum:=`git status | grep -n "修改尚未加入提交" | awk -F ":" '{print$1}'`}
enum=${enum:=`git status | grep -n "提交为空" | awk -F ":" '{print$1}'`}
enum=${enum:=`git status | grep -n "no changes added to commit" | awk -F ":" '{print$1}'`}
enum=${enum:=`git status | grep -n "提交为空" | awk -F ":" '{print$1}'`}
[[ $enum != "" ]] && add=(`git status | head -$[$enum-2] | tail -$[$enum-$snum-4]`)
#git status | head -$[$enum-2] | tail -$[$enum-$snum-4]
all=(${modify[*]} ${delete[*]} ${add[*]})
for file in ${all[*]}
do
git add $file
done

git commit -m "modify"
expect -c "
set timeout -1
spawn git push
expect \"Username for*\"
send -- \"xiarenzhuxinn\r\"
expect \"Password*\"
send \"Ljxljx19986!7\r\"
#interact
expect eof"
