#!/bin/bash
path=$(dirname $(readlink -f "$0"))
fuc=$1
file=$2
lreset(){
flg=""
sig=""
lkh="0"
rkh="0"
}
lreset
trace=`grep -wr $1 $2 | awk -F":" '{print$1}'| sort -u | awk '/\/*.[hc]$/{print$NF}'`
for tr in $trace
do
target=(`grep -wn $1 $tr | tr -d "\t" | sed "s/ \*/\*/"| awk '{print$1}'`)
allta=${#target[@]}
for ((i=0;i<$allta;i++))
{
mark=${target[i]#*:}
grep -w $mark $path/difine &>/dev/null && line=${target[i]%:*} && flg="1" && break
}
[[ $flg != "1" ]] && continue
echo $tr
intline=$line
#peline=`grep -A5 $1 $2 | grep -n "{" | awk -F":" '{print$1}' | head -1`
for str in `seq 1 5`
do
cat $tr | head -$line | tail -1 | grep "{" &>/dev/null && lkh=$[$lkh + 1] && strline=$[$line+1] && cat $tr | head -$line | tail -1 | grep "}" &>/dev/null && rkh=$[$rkh + 1] && break
line=$[$line + 1]
trline=`cat $tr | head -$line | tail -1 | tr -s "/t" " " | awk '{print$1}'`
[[ $trline != "" ]] && grep -w $trline $path/difine &>/dev/null && cat $tr | head -$intline | tail -1 && sig="1" && break
done
[[ $sig = "1" ]] && lreset && continue
[ $lkh = 0 ] && cat $tr | head -$intline | tail -1 && lreset  && continue
[ $lkh = $rkh ] && cat $tr | head -$intline | tail -1 && lreset && continue
peline=$[$strline - $intline]
#echo $strline $peline
for xh in `seq 1 70`
do
cat $tr | head -$strline | tail -1 | grep "{" &>/dev/null && lkh=$[$lkh + 1]
cat $tr | head -$strline | tail -1 | grep "}" &>/dev/null && rkh=$[$rkh + 1]
strline=$[$strline + 1]
#echo $lkh $rkh
[ $lkh = $rkh ] && lpeline=$xh && break 
done
rlline=$[$peline+$lpeline]
endline=$[$intline+$rlline-1]
#echo $intline $endline
cat $tr | head -$endline | tail -$rlline
#grep -A$rlline $1 $2
lreset
done
