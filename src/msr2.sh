#!/bin/bash

for p in `cat "msr-index.h" | grep define | grep MSR | grep 0x | grep -v fffff | awk {'printf ("%s%s\n", $2, $3)'} `
do
msr=`echo $p | awk -F '0x' '{print $1}' | tr -d "\n"`
echo "$msr"
value=`echo $p | awk -F '0x' '{print $2}' | tr -d "\n"`
value="0x${value}"
#rdmsr -p0 $value
done

for p in `cat "hyperv.h" | grep define | grep MSR | grep 0x | grep -v fffff | awk {'printf ("%s%s\n", $2, $3)'} `
do
msr=`echo $p | awk -F '0x' '{print $1}' | tr -d "\n"`
echo "$msr"
value=`echo $p | awk -F '0x' '{print $2}' | tr -d "\n"`
value="0x${value}"
#rdmsr -p0 $value
done

#wrmsr -p 0 0x00000186 0x004300c0
#wrmsr -p 0 0x10 0

