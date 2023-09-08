#!/usr/bin/env bash

date=$(date +"%y%m%d-%H:%M")
git_short=$(git rev-parse --short=0 HEAD)
git_dirty=$(git describe --always --dirty)
git_status=$(git status --porcelain $1)

if [[ -n ${git_status} ]]; then
	git_short="${git_short}*"
fi

mkdir $1/src 2>/dev/null
file="$1/src/buildinfo.h"
rm $file
echo "/* buildinfo.sh script generated file */" > $file
echo "#define BUILD_TIME \"${date}\"" > $file
echo "#define BUILD_GIT_SHORT \"${git_short}\"" >> $file
echo "#define BUILD_GIT_DIRTY \"${git_dirty}\"" >> $file

