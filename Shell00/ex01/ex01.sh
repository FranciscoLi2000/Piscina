#!/bin/sh

dd if=/dev/zero of=testShell00 bs=1 count=40 2>/dev/null

chmod 455 testShell00

touch -t 202306012343 testShell00

tar -cf testShell00.tar testShell00
