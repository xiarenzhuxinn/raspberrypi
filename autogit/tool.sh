#!/usr/bash

git_pull()
{
git pull && echo "git pull suecss"
[ $? != 0 ] && echo "git pull fail"
}
if [ -e $NOW_PATH/raspiberrypi ]
then
git_pull
[ $? != 0 ] && rm -r $NOW_PATH/raspiberrypi && git clone $url
else
git clone $url && git_pull
fi
