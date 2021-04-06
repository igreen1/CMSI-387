#########################################################################
# File Name: run.sh
# Author: 
# mail: 
# Created Time: Sun Apr  4 10:47:53 2021
#########################################################################
#!/bin/bash
gcc mmap.c -o mmap

./mmap midBeginning.txt midEnd.txt midNox.txt largeBeignning.txt largeEnd.txt largeNox.txt
