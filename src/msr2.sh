#!/bin/bash

for p in `cat "msr-index.h" | grep define | grep MSR | grep 0x | awk -F ' ' '{print $3}'`
do echo "$p"
rdmsr -p0 $p
done

for p in `cat "hyperv.h" | grep define | grep MSR | grep 0x | awk -F ' ' '{print $3}'`
do echo "$p"
rdmsr -p0 $p
done

wrmsr -p 0 0x00000186 0x004300c0
wrmsr -p 0 0x10 0

