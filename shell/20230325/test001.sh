#!/bin/bash

a=`which glibtoolize`
echo $a


gprefix=`which glibtoolize 2>&1 >/dev/null`

echo $gprefix