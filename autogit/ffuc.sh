#!/bin/bash
path=$(dirname $(readlink -f "$0"))
fuc=$1
tfile=$2
lreset(){
flg=""
sig=""
lkh="0"
rkh="0"
}
lreset
[ -d $2 ] && trace=`grep -wr $1 $2 | awk -F":" '{print$1}'| sort -u | awk '/\/*.[hc]$/{print$NF}'`
[ -f $2 ] && trace=$2
#echo $trace
for tr in $trace
do
target=(`grep -wn $1 $tr | tr -d "\t" | sed "s/ \*/\*/"| awk '{print$1}'`)
allta=${#target[@]}
#echo $target
for ((i=0;i<$allta;i++))
{
mark=${target[i]#*:}
[[ $mark != "" ]] && grep -w $mark $path/difine &>/dev/null && line=${target[i]%:*} && flg="1" && break
}
[[ $flg != "1" ]] && continue
intline=$line
echo $tr +$intline
#peline=`grep -A5 $1 $tpath/$2 | grep -n "{" | awk -F":" '{print$1}' | head -1`
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
for xh in `seq 1 170`
do
cat $tr | head -$strline | tail -1 | grep "{" &>/dev/null && lkh=$[$lkh + 1]
cat $tr | head -$strline | tail -1 | grep "}" &>/dev/null && rkh=$[$rkh + 1]
strline=$[$strline + 1]
#echo $lkh $rkh
[ $lkh = $rkh ] && lpeline=$xh && break 
done
#echo $strline $peline $lpeline
rlline=$[$peline + $lpeline]
endline=$[$intline + $rlline-1]
#echo $intline $endline
cat $tr | head -$endline | tail -$rlline
#grep -A$rlline $1 $tpath/$2
lreset
done
